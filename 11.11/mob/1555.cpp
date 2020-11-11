#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i, x) for (int i = 1; i <= x; i++)
#define fo_(i, b, x) for (int i = b; i <= x; i++)
#define re(i, x, b) for (int i = x; i > b; i--)
#define N 10010
#define deb if (using_debug_output)
#define fil if (using_temp_file)
#define realfl if (this_is_a_real_file_output)
#define ls(o) o<<1
#define rs(o) o<<1 | 1
#include <algorithm>
const int maxn = 200005;
int n, cnt = 0, x, head[maxn], q, dep[maxn], fat[maxn], sz[maxn];
int id2[maxn], top[maxn], son[maxn], tdnum = 0, pos[maxn];
char s[15];
struct node {
    int to, next;
} e[maxn << 1];
struct Node {
    int ll, rr, lz, sum;
} t[maxn << 2];
void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void dfs1(int x, int fa, int depth)
{
    sz[x] = 1;
    fat[x] = fa;
    dep[x] = depth;
    for (int i = head[x]; i; i = e[i].next) {
        if (e[i].to == fa)
            continue;
        dfs1(e[i].to, x, depth + 1);
        sz[x] += sz[e[i].to];
        if (!son[x] || sz[e[i].to] > sz[son[x]])
            son[x] = e[i].to;
    }
}
void dfs2(int x, int tp)
{
    id2[x] = ++tdnum;
    pos[id2[x]] = x;
    top[x] = tp;
    if (!son[x])
        return;
    dfs2(son[x], tp);
    for (int i = head[x]; i; i = e[i].next) {
        if (e[i].to != son[x] && e[i].to != fat[x])
            dfs2(e[i].to, e[i].to);
    }
}
void build(int o, int l, int r)
{
    t[o].ll = l;
    t[o].rr = r;
    t[o].sum = 0;
    t[o].lz = -1;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(ls(o), l, mid);
    build(ls(o) | 1, mid + 1, r);
    return;
}
void pushdn(int o)
{
    t[ls(o)].sum = (t[ls(o)].rr - t[ls(o)].ll + 1) * t[o].lz;
    t[ls(o) | 1].sum = (t[ls(o) | 1].rr - t[ls(o) | 1].ll + 1) * t[o].lz;
    t[ls(o)].lz = t[ls(o) | 1].lz = t[o].lz;
    t[o].lz = -1;
}
int get(int o, int l, int r)
{
    if (t[o].rr < l || t[o].ll > r)
        return 0;
    if (t[o].rr <= r && t[o].ll >= l)
        return t[o].sum;
    if (t[o].lz != -1)
        pushdn(o);
    return get(ls(o), l, r) + get(ls(o) | 1, l, r);
}
void aske(int o, int l, int r, int val)
{
    if (t[o].rr < l || t[o].ll > r)
        return;
    if (t[o].rr <= r && t[o].ll >= l) {
        t[o].sum = (t[o].rr - t[o].ll + 1) * val;
        t[o].lz = val;
        return;
    }
    if (t[o].lz != -1)
        pushdn(o);
    aske(ls(o), l, r, val);
    aske(ls(o) | 1, l, r, val);
    t[o].sum = t[ls(o)].sum + t[ls(o) | 1].sum;
    return;
}
void moldify(int u, int v, int val)
{
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            std::swap(u, v);
        aske(1, id2[top[u]], id2[u], val);
        u = fat[top[u]];
    }
    if (dep[u] > dep[v])
        std::swap(u, v);
    aske(1, id2[u], id2[v], val);
    return;
}
int main()
{
    cin>>n;
    for (int i = 2; i <= n; i++) {
        cin>>x;
        x++;
        add(x, i);
    }
    dfs1(1, 1, 1);
    dfs2(1, 1);
    cin>>q;
    build(1, 1, tdnum);
    for (int i = 1; i <= q; i++) {
        scanf("%s", s);
        cin>>x;
        x++;
        int t1 = t[1].sum;
        if (s[0] == 'i') {
            moldify(1, x, 1);
            int t2 = t[1].sum;
            printf("%d\n", abs(t2 - t1));
        }
        if (s[0] == 'u') {
            aske(1, id2[x], id2[x] + sz[x] - 1, 0);
            int t2 = t[1].sum;
            printf("%d\n", abs(t1 - t2));
        }
    }
    return 0;
}
