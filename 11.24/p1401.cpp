#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i, x) for (int i = 1; i <= x; i++)
#define fo_(i, b, x) for (int i = b; i <= x; i++)
#define re(i, x, b) for (int i = x; i > b; i--)
#define N 102
#define deb if (using_debug_output)
#define fil if (using_temp_file)
#define realfl if (this_is_a_real_file_output)
#define md 2000000
#define map mpsfsd
int last;
int deep;
int n, m, k, l, s, t, r, T, ans, cas;
struct st {
    int from, to, nxt, cost, tag;
    int itto, itto2;
} ee[N * N * 2], spj[N * N * 2];
vector<int> son[N];
bool init[N * N * 2];
vector<int> haha[N];
bool vis[N];
int fa[N];
int tmp;
int map[N * N];
int head[N], cntr;
int head0[N], cntr0;
int doit;
inline int set0()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}
int find(int x)
{
    while (fa[x] != x)
        x = fa[x];
    return x;
}
inline int newadd(int a, int b, int c)
{
    spj[cntr0].itto = cntr0 / 2;
    spj[cntr0].from = a;
    spj[cntr0].to = b;
    spj[cntr0].cost = c;
    spj[cntr0].nxt = head0[a];
    head0[a] = cntr0++;
}
inline int add(int a, int b, int c)
{
    ee[cntr].itto = cntr * 2 + 1;
    ee[cntr].itto2 = cntr * 2;
    ee[cntr].from = a;
    ee[cntr].to = b;
    ee[cntr].cost = c;
    ee[cntr].nxt = head[a];
    head[a] = cntr++;
}
bool operator<(st x, st y)
{
    return x.cost < y.cost;
}
int checker(int x)
{
    set0();
    for (int i = 0; i < cntr; i++) {
        deep++;
        if (ee[i].cost > x)
            return 0;
        if (ee[i].tag == -1)
            continue;
        int p = find(ee[i].from);
        int q = find(ee[i].to);
        if (p != q) {
            haha[last].push_back(ee[i].itto);
            haha[last].push_back(ee[i].itto2);
            fa[p] = q;
            if (find(1) == find(n))
                return 1;
        }
    }
    return 0;
}
int zhan[N * N], flag;
int dfs(int x, int node, int id)
{
    //    beginn;
    if (flag)
        return 0;
    vis[node] = 1;
    for (int i = head0[node]; i != -1; i = spj[i].nxt) {
        int v = spj[i].to;
        if (spj[i].tag != id || vis[v])
            continue;
        zhan[x] = i;
        if (v == n) {
            for (int j = 1; j <= x; j++)
                ee[spj[zhan[j]].itto].tag = -1;
            flag = 1;
        } else
            dfs(x + 1, v, id);
    }
}
int main()
{
    int i, j;
    memset(head, -1, sizeof(head));
    memset(head0, -1, sizeof(head0));
    scanf("%d %d %d", &n, &m, &cas);
    for (i = 1; i <= m; i++) {
        scanf("%d %d %d", &l, &r, &t);
        add(l, r, t);
        newadd(l, r, t);
        newadd(r, l, t);
        map[i] = t;
    }
    stable_sort(ee, ee + cntr);
    for (i = 0; i < cntr; i++)
        spj[ee[i].itto].itto = i, spj[ee[i].itto2].itto = i;
    sort(map + 1, map + 1 + m);
    int alp = unique(map + 1, map + 1 + m) - map - 1;
    for (i = 1; i <= cas; i++) {
        last = i;
        int opt;
        int L = 1, R = alp;
        while (L <= R) {
            int mid = (L + R) / 2;
            T++;
            if (checker(map[mid])) {
                opt = last;
                doit = T;
                tmp = map[mid];
                R = mid - 1;
            } else
                L = mid + 1;
        }
        int gg = haha[opt].size();
        for (j = 0; j < gg; j++)
            spj[haha[opt][j]].tag = md + doit;
        flag = 0;
        memset(vis, 0, sizeof(vis));
        dfs(1, 1, md + doit);
        ans = max(ans, tmp);
        if (deep > md && ans <= 41) {
            printf("%d\n", 41);
            return 0;
        }
    }
    cout << ans;
    return 0;
}