#include <cstdio>
#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <iterator>
#include <set>
#include <vector>
#include <algorithm>

using std::printf;
using std::string;

struct State;
typedef std::list<State>::iterator State_it;
std::list<State> state_pool;

enum class Step_type {
    Char, Epsilon, Any
};

struct Step {
    Step_type t;
    char c;
    State_it p;
};

struct State {
    std::vector<Step> next;
    int id; // for visualizing
};

State_it new_state() {
    state_pool.emplace_back();
    state_pool.back().id = state_pool.size();
    return std::prev(state_pool.end());
};

void add_step(State_it s, const Step &step) {
    s->next.push_back(step);
}

struct NFA {
    State_it start;
    State_it accept; // only one accept state, and *accept always an empty State
};

struct Head {
    const char *p;
};

bool match(Head *h, char c) {
    return *h->p == c ? (++h->p, true) : false;
}

void expect(Head *h, char c) {
    if (!match(h, c))
        throw "Expect " + string(1, c);
}

void unexpect(Head *h, char c) {
    if (*h->p == c)
        throw "Unexpected " + string(1, c);
}

NFA expr(Head *h);

NFA trivial() {
    NFA nfa;
    nfa.start = new_state();
    nfa.accept = nfa.start;
    return nfa;
}

bool is_trivial(const NFA &nfa) {
    return nfa.start == nfa.accept;
}

NFA single(Step_type t, char c) {
    NFA nfa = trivial();

    State_it p = new_state();
    add_step(nfa.start, Step{t, c, p});
    nfa.accept = p;

    return nfa;
}

NFA unit(Head *h) {
    if (match(h, '(')) {
        NFA nfa = expr(h);
        expect(h, ')');
        return nfa;
    }

    if (match(h, '.')) {
        return single(Step_type::Any, '.');
    }

    if (match(h, '\\')) {
        char escape[][2] = {
            {'n', '\n'},
            {'t', '\t'},
            {'\\', '\\'},
            {'.', '.'},
            {'*', '*'},
            {'|', '|'}
        };

        for (size_t i = 0; i < sizeof escape; ++i) {
            if (match(h, escape[i][0]))
                return single(Step_type::Char, escape[i][1]);
        }
    }

    if (*h->p == '\0' || *h->p == '|' || *h->p == ')') {
        return trivial();
    } else {
        unexpect(h, '*');
        unexpect(h, '+');

        return single(Step_type::Char, *h->p++);
    }
}

NFA post(Head *h) {
    NFA nfa = unit(h);

    if (match(h, '*')) {
        add_step(nfa.accept, Step{Step_type::Epsilon, '*', nfa.start});
        State_it p = new_state();
        add_step(nfa.start, Step{Step_type::Epsilon, '*', p});
        nfa.accept = p;
    }

    if (match(h, '+')) {
        add_step(nfa.accept, Step{Step_type::Epsilon, '*', nfa.start});
        State_it p = new_state();
        add_step(nfa.accept, Step{Step_type::Epsilon, '*', p});
        nfa.accept = p;
    }

    return nfa;
}

NFA cat(Head *h) {
    NFA nfa = post(h), inc;

    while (true) {
        inc = post(h);

        if (is_trivial(inc)) {
            return nfa;
        } else {
            *nfa.accept = *inc.start;
            nfa.accept = inc.accept;
        }
    }
}

NFA alt(Head *h) {
    NFA nfa = cat(h);

    while (match(h, '|')) {
        NFA inc = cat(h);
        NFA pivot = trivial();
        add_step(pivot.start, Step{Step_type::Epsilon, '|', nfa.start});
        add_step(pivot.start, Step{Step_type::Epsilon, '|', inc.start});

        State_it sink = new_state();
        add_step(nfa.accept, Step{Step_type::Epsilon, '|', sink});
        add_step(inc.accept, Step{Step_type::Epsilon, '|', sink});

        pivot.accept = sink;
        nfa = pivot;
    }

    return nfa;
}

NFA expr(Head *h) {
    return alt(h);
}

namespace print {
std::set<int> visited;

void lines(State_it s) {
    visited.insert(s->id);

    for (auto step : s->next) {
        string type;

        switch (step.t) {
        case Step_type::Char:
            type = "char";
            break;

        case Step_type::Any:
            type = "any";
            break;

        case Step_type::Epsilon:
            type = "eps";
            break;
        }

        printf("S_%d -> S_%d [ label = \"%s, %c\" ];\n",
               s->id,
               step.p->id,
               type.c_str(),
               step.c);

        if (!visited.count(step.p->id))
            lines(step.p);
    }
}

void graphviz(const NFA &nfa) {
    printf("digraph NFA {\n");
    printf("rankdir = LR;\n");
    printf("node [shape = doublecircle]; S_%d;\n", nfa.accept->id);
    printf("node [shape = square]; S_%d;\n", nfa.start->id);
    printf("node [shape = circle];\n");

    lines(nfa.start);
    printf("}\n");
}
}

bool run(const NFA &nfa, const char *s) {
    std::vector<State_it> states;
    std::set<int> ids;
    states.push_back(nfa.start);
    ids.insert(nfa.start->id);

    while (true) {
        for (size_t k = 0; k < states.size(); ++k) { // expands while looping
            for (auto step : states[k]->next) {
                if (step.t == Step_type::Epsilon) {
                    if (!ids.count(step.p->id)) {
                        ids.insert(step.p->id);
                        states.push_back(step.p);
                    }
                }
            }
        }

        if (*s == '\0')
            break;

        std::vector<State_it> next_states;
        std::set<int> next_ids;

        for (size_t k = 0; k < states.size(); ++k) {
            for (auto step : states[k]->next) {
                if (step.t == Step_type::Any
                        || (step.t == Step_type::Char && step.c == *s)) {
                    if (!next_ids.count(step.p->id)) {
                        next_ids.insert(step.p->id);
                        next_states.push_back(step.p);
                    }
                }
            }
        }

        ++s;
        states.swap(next_states);
        ids.swap(next_ids);
    }

    return ids.count(nfa.accept->id);
}

int main() {
    while (true) {
        string s;
        getline(std::cin, s);

        if (s == "")
            break;

        Head h;
        h.p = s.c_str();

        try {
            NFA nfa = expr(&h);
                   print::graphviz(nfa);

            string t;
            getline(std::cin, t);
            bool r = run(nfa, t.c_str());
            printf("%s\n", r ? "Yes" : "No");
        } catch (const string &msg) {
            fprintf(stderr, "%s\n", msg.c_str());
        }
    }

    return 0;
}
