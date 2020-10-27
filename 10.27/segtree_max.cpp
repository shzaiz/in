#include <algorithm>
#include <cstdio>
#define lson rt << 1
#define rson rt << 1 | 1
using std::max;
const int N = 5e4 + 5;
int n, m, a[N];

struct Tree {
    int prel, prer, res, sum;
} seg[N << 2];

void pushup(int rt)
{
    Tree L = seg[lson], R = seg[rson];
    seg[rt].sum = L.sum + R.sum;
    seg[rt].prel = max(L.prel, L.sum + R.prel);
    seg[rt].prer = max(R.prer, R.sum + L.prer);
    seg[rt].res = max(L.prer + R.prel, max(L.res, R.res));
}
void build(int rt, int l, int r)
{
    if (l == r) {
        seg[rt].prel = seg[rt].prer = seg[rt].res = seg[rt].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void modify(int x, int rt, int l, int r, int val)
{
    if (l == r) {
        seg[rt].prel = seg[rt].prer = seg[rt].res = seg[rt].sum = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        modify(x, lson, l, mid, val);
    else
        modify(x, rson, mid + 1, r, val);
    pushup(rt);
}
Tree query(int x, int y, int rt, int l, int r)
{
    if (x <= l && r <= y)
        return seg[rt];
    int mid = (l + r) >> 1;
    if (y <= mid)
        return query(x, y, lson, l, mid);
    if (mid < x)
        return query(x, y, rson, mid + 1, r);
    Tree L = query(x, mid, lson, l, mid), R = query(mid + 1, y, rson, mid + 1, r), res;
    res.sum = L.sum + R.sum;
    res.prel = max(L.prel, L.sum + R.prel);
    res.prer = max(R.prer, R.sum + L.prer);
    res.res = max(L.prer + R.prel, max(L.res, R.res));
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    build(1, 1, n);
    for (scanf("%d", &m); m--;) {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        if (opt)
            printf("%d\n", query(x, y, 1, 1, n).res);
        else
            modify(x, 1, 1, n, y);
    }
    return 0;
}