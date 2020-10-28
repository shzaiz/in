#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 1e2;
const int inf = 0x3f3f3f3f;

multiset<int> delta, full;
int st[maxn], ed[maxn];
int srt = inf;
int n, m;

inline void update_srt(int x)
{
    multiset<int>::iterator it = full.lower_bound(x);
    int nw = *it - x;
    --it;
    nw = min(nw, x - *it);
    srt = min(srt, nw);
    full.insert(x);
}

inline void replac(int pos, int x)
{
    delta.insert(abs(x - ed[pos]));
    if (pos != n)
        delta.erase(delta.find(abs(st[pos + 1] - ed[pos]))),
            delta.insert(abs(st[pos + 1] - x));
    ed[pos] = x;
}

inline int getint()
{
    int ret = 0, fix = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            fix = -1;
        ch = getchar();
    }
    while (isdigit(ch))
        ret = ret * 10 + (ch - '0'),
        ch = getchar();
    return ret * fix;
}

int main()
{
    static char str[1 << 5];
    n = getint(), m = getint();
    for (int i = 1; i <= n; i++)
        st[i] = ed[i] = getint();

    full.insert(inf),
        full.insert(-inf);
    for (int i = 1; i < n; i++)
        delta.insert(abs(st[i + 1] - ed[i]));
    for (int i = 1; i <= n; i++)
        update_srt(st[i]);
    for (int i = 1, pos, x; i <= m; i++) {
        scanf("%s", str);
        if (*str == 'I') {
            pos = getint(), x = getint();
            update_srt(x);
            replac(pos, x);
        } else if (str[4] == 'S')
            printf("%d\n", srt);
        else
            printf("%d\n", *delta.begin());
    }
    return 0;
}