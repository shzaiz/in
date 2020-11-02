#include <cstdio>
#define MAXN 100005
using namespace std;

struct edge {
    int v, pre;
} e[MAXN << 1];
int N, T, fst[MAXN], dep[MAXN], dp[MAXN][18];
int vis[MAXN], lg[MAXN];

inline int read()
{
    register int o = 0;
    register char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
        o = (o << 3) + (o << 1) + (c & 15), c = getchar();
    return o;
}
inline int abs(int x) { return x > 0 ? x : -x; }
inline int swap(int& x, int& y) { x ^= y ^= x ^= y; }
inline int addedge(int a, int b, int k)
{
    e[k] = (edge) { b, fst[a] }, fst[a] = k;
}
int build(int k, int d)
{
    vis[k] = 1, dep[k] = d;
    for (register int o = fst[k]; o; o = e[o].pre)
        if (!vis[e[o].v])
            dp[e[o].v][0] = k, build(e[o].v, d + 1);
}
int prepare(int k)
{
    vis[k] = 0;
    for (register int i = 1; i <= lg[dep[k]]; i++)
        dp[k][i] = dp[dp[k][i - 1]][i - 1];
    for (register int o = fst[k]; o; o = e[o].pre)
        if (vis[e[o].v])
            prepare(e[o].v);
}
int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);
    while (dep[a] > dep[b])
        a = dp[a][lg[dep[a] - dep[b]]];
    if (a == b)
        return a;
    for (register int i = lg[dep[a]]; i >= 0; i--)
        if (dp[a][i] != dp[b][i])
            a = dp[a][i], b = dp[b][i];
    return dp[a][0];
}
inline int dis(int a, int b)
{
    register int c = lca(a, b);
    return abs(dep[c] - dep[a]) + abs(dep[c] - dep[b]);
}
int main()
{
    N = read(), T = read();
    for (register int i = 1, a, b, c; i < N; i++) {
        a = read(), b = read();
        addedge(a, b, i);
        addedge(b, a, i + N);
    }
    build(1, 0);
    for (register int i = 1; i <= N; i++)
        lg[i] = lg[i - 1] + ((1 << (lg[i - 1] + 1)) == i);
    prepare(1);
    for (register int a, b, c, d, x, y; T; T--) {
        a = read(), b = read(), c = read(), d = read();
        x = lca(a, b), y = lca(c, d);
        if (dis(a, y) + dis(b, y) == dis(a, b) || dis(c, x) + dis(d, x) == dis(c, d))
            puts("Y");
        else
            puts("N");
    }
}