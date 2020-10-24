#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ll long long
using namespace std;
int n, m, rt;
int x, y;
int ans = 0;
int k;
int head[1009];
int mk[1009];
int to[1009];
int nxt[1009];
int son[1009];
int mx[1009];
int top[1009];
int d[1009];
int build[1009];
int f[1009];
int tot;
void add(int x, int y)
{
    tot++;
    nxt[tot] = head[x];
    head[x] = tot;
    to[tot] = y;
}
void mark(int u, int fa, int cur, int dep)
{
    if (cur > dep)
        return;
    mk[u] = 1;
    // printf("%d ", u);
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == fa)
            continue;
        mark(v, u, cur + 1, dep);
    }
}
void dfs(int x)
{
    d[x] = d[f[x]] + 1;
    mx[x] = d[x];
    for (int i = head[x]; i; i = nxt[i]) {
        if (to[i] != f[x]) {
            f[to[i]] = x;
            dfs(to[i]);
            mx[x] = max(mx[to[i]], mx[x]);
            if (mx[to[i]] > mx[son[x]]) {
                son[x] = to[i];
            }
        }
    }
}
void dfs2(int x, int tp)
{
    // printf("%d ", x);
    top[x] = tp;
    if (son[x]) {
        dfs2(son[x], tp);
    }
    for (int i = head[x]; i; i = nxt[i]) {
        if (to[i] != f[x] && to[i] != son[x]) {
            dfs2(to[i], to[i]);
        }
    }
    if (!mk[x]) {
        ans++;
        int p = x;
        for (int i = 1; i <= k; i++) {
            p = f[p];
        }
        mark(p, 0, 0, k);
    }
}
int lca(int x, int y)
{
    while (top[x] != top[y]) {
        if (d[top[x]] < d[top[y]]) {
            swap(x, y);
        }
        x = f[top[x]];
    }
    return d[x] < d[y] ? x : y;
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i < m; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    mark(m, 0, 0, k);
    dfs(m);
    dfs2(m, m);
    printf("%d\n", ans);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
#endif
    int T;cin>>T;
    while(T--){
        #define M(x) memset((x),0,sizeof((x)))
        ans = 0; M(d); M(f); M(head); k = 0; m = 0; M(mk); M(mx); n = 0;M(nxt);rt = 0; M(son);M(top);tot = 0;x = 0;y=0;
        solve();
    }
}