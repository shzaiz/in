#include <bits/stdc++.h>
using namespace std;
#define fo(i, x) for (int i = 1; i <= x; i++)
#define fo_(i, b, x) for (int i = b; i <= x; i++)
#define re(i, x, b) for (int i = x; i > b; i--)
#define all(dat) dat.begin(), dat.end()
#define over(msg) cout << msg << endl, exit(0);
#define loop(i, to) for (int i = 0; i < to; ++i)
#define cont(i, to) for (int i = 1; i <= to; ++i)
#define circ(i, fr, to) for (int i = fr; i <= to; ++i)
#define foreach(i, dat) for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)
#define ll long long
#define N 10010
const int logsize = 18;
int n, m, q, rt = 1, t, sc, vis[100005], dfn[100005], low[100005], sid[100005], sz[100005], dep[100005], pr[100005][logsize], w[100005], mod = 1e9 + 7;
stack<int> s;
vector<int> g[100005], ng[100005];

int inline read()
{
    int res = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); res *= 10, res += c ^ 48, c = getchar())
        ;
    return res;
}
void tarjan(int u, int p)
{
    dfn[u] = low[u] = ++t;
    vis[u] = 1;
    s.push(u);
    for (int v : g[u]) {
        if (v == p || vis[v] == 2)
            continue;
        if (!vis[v]) {
            tarjan(v, u);
        }
        low[u] = min(low[u], low[v]);
    }
    if (dfn[u] == low[u]) {
        ++sc;
        for (;;) {
            int v = s.top();
            s.pop();
            vis[v] = 2;
            sid[v] = sc;
            ++sz[sc];
            if (u == v)
                break;
        }
    }
}

void dfs(int u, int p)
{
    dep[u] = u == rt ? 0 : dep[p] + 1;
    w[u] = u == rt ? sz[u] > 1 : w[p] + (sz[u] > 1);
    pr[u][0] = p;
    for (int v : ng[u]) {
        if (v == p)
            continue;
        dfs(v, u);
    }
}
void inline init()
{
    dfs(rt, -1);
    fo(i, logsize - 1)
    {
        cont(u, sc)
        {
            int p = pr[u][i - 1];
            if (p == -1) {
                pr[u][i] = -1;
            } else {
                pr[u][i] = pr[p][i - 1];
            }
        }
    }
}
int inline lca(int u, int v)
{
    if (dep[u] > dep[v]) {
        swap(u, v);
    }
    loop(i, logsize)
    {
        if ((dep[v] - dep[u]) >> i & 1) {
            v = pr[v][i];
        }
    }
    if (u == v)
        return u;
    for (int i = logsize - 1; i >= 0; --i) {
        if (pr[u][i] != pr[v][i]) {
            u = pr[u][i];
            v = pr[v][i];
        }
    }
    return pr[u][0];
}

int qpow(ll a, int p)
{
    ll res = 1;
    while (p) {
        if (p & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        p >>= 1;
    }
    return res % mod;
}

int main()
{
    n = read();
    m = read();
    cont(i, m)
    {
        int u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cont(u, n)
    {
        if (!vis[u]) {
            tarjan(u, -1);
        }
    }
    cont(u, n)
    {
        for (int v : g[u]) {
            int su = sid[u], sv = sid[v];
            if (su == sv)
                continue;
            ng[su].push_back(sv);
        }
    }
    init();
    q = read();
    cont(i, q)
    {
        int u = read(), v = read(), su = sid[u], sv = sid[v], sp = lca(su, sv);
        int d = w[su] + w[sv] - w[sp] * 2 + (sz[sp] > 1);
        cout << qpow(2, d) << endl;
    }
    return 0;
}
