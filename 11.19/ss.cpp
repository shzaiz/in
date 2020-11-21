#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define Match
using namespace std;
const int N = 3e2 + 10;

struct Edge {
    int nxt, to;
} edge[N << 1], G[N << 1];
int H[N], head[N], v[N], w[N], cost[N], val[N], f[N][N * 5], cnt, C, tot, n, m, low[N], dfn[N], num, hep[N], top, vis[N], fa[N], up[N], use[N];

inline void addedge(int u, int v)
{
    edge[++cnt].nxt = head[u];
    edge[cnt].to = v;
    head[u] = cnt;
}

inline void addG(int u, int v)
{
    G[++C].nxt = H[u];
    G[C].to = v;
    H[u] = C;
}

inline void tarjan(int u)
{
    low[u] = dfn[u] = ++num;
    hep[++top] = u;
    vis[u] = 1;
    for (register int i = head[u]; i; i = edge[i].nxt) {
        int to = edge[i].to;
        if (!dfn[to]) {
            tarjan(to), low[u] = min(low[u], low[to]);
        } else if (vis[to]) {
            low[u] = min(low[u], dfn[to]);
        }
    }
    if (dfn[u] == low[u]) {
        ++tot;
        vis[u] = 0;
        while (hep[top + 1] != u) {
            fa[hep[top]] = tot, vis[hep[top--]] = 0;
        }
    }
    return;
}
inline void dp(int x)
{
    for (register int i = cost[x]; i <= m; ++i) {
        f[x][i] = val[x];
    }
    for (register int i = H[x]; i; i = G[i].nxt) {
        int v = G[i].to;
        dp(v);
        for (register int j = m - cost[x]; j >= 0; --j)
            for (register int k = 0; k <= j; ++k) {
                f[x][j + cost[x]] = max(f[x][j + cost[x]], f[x][j + cost[x] - k] + f[v][k]);
            }
    }
    return;
}
int main()
{
    scanf("%d%d", &n, &m);
    memset(f, -inf, sizeof(f));
    for (register int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
    }
    for (register int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }
    for (register int x, i = 1; i <= n; ++i) {
        scanf("%d", &x);
        up[i] = x;
        if (x != 0) {
            addedge(x, i);
        }
    }
    for (register int i = 1; i <= n; ++i)
        if (!dfn[i]) {
            tarjan(i);
        }
    for (register int i = 1; i <= n; ++i) {
        val[fa[i]] += v[i];
        cost[fa[i]] += w[i];
        if (fa[i] != fa[up[i]] && up[i]) {
            addG(fa[up[i]], fa[i]), use[fa[i]]++;
        }
    }
    int s = tot + 1;
    for (register int i = 1; i <= tot; ++i) {
        if (!use[i]) {
            addG(s, i);
        }
    }
    dp(s);
    cost[s] = 0;
    val[s] = 0;
    printf("%d\n", f[s][m + cost[s]]);
    return 0;
}