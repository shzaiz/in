#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
long long ans = 0;
int fa[500010][25], lg[500010], deep[500010], t;
struct node {
    int from;
    int to;
    int next;
} ed[2 * 500001];
int v[2 * 500001], tot = 0;
void add(int x, int y)
{
    ed[++tot].from = x;
    ed[tot].to = y;
    ed[tot].next = v[x];
    v[x] = tot;
}
int lca(int x, int y)
{
    if (deep[x] < deep[y])
        swap(x, y);
    while (deep[x] > deep[y]) {
        x = fa[x][lg[deep[x] - deep[y]] - 1];
    }
    if (x == y)
        return x;
    for (int k = lg[deep[x]]; k >= 0; k--) {
        if (fa[x][k] != fa[y][k]) {
            x = fa[x][k];
            y = fa[y][k];
        }
    }
    return fa[x][0];
}
void dfs(int x, int fath)
{
    deep[x] = deep[fath] + 1;
    fa[x][0] = fath;
    for (int i = 1; (1 << i) <= deep[x]; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (int i = v[x]; i; i = ed[i].next)
        if (ed[i].to != fath)
            dfs(ed[i].to, x);
}
int n, m;
int a, b, c;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    for (int i = 1; i <= m; i++) {
        ans = 0;
        scanf("%d%d%d", &a, &b, &c);
        int t1 = lca(a, b);
        int t2 = lca(a, c);
        int t3 = lca(b, c);
        if (t1 == t2)
            t = t3;
        else if (t1 == t3)
            t = t2;
        else if (t2 == t3)
            t = t1;
        ans = deep[a] + deep[b] + deep[c] - deep[t1] - deep[t2] - deep[t3];
        printf("%d %lld\n", t, ans);
    }
    return 0;
}