#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define ls(x) x << 1
#define rs(x) x << 1 | 1
#define sz(x) r[x] - l[x] + 1
#define mid (ll + rr) / 2
#define fo(i, x) for (int i = 1; i <= (x); ++i)
#define int long long
int a[N];
int l[N], r[N], lz[N], lz2[N], sum[N];
void pushup(int o) { sum[o] = sum[ls(o)] + sum[rs(o)]; }
void pushdn(int o, int ln, int rn)
{   
    if (lz[o]!=0 || lz2[o] != 1) {
        sum[ls(o)] = sum[ls(o)] * lz2[o] + lz[o] * ln;
        sum[rs(o)] = sum[rs(o)] * lz2[o] + lz[o] * rn;
        lz2[ls(o)] = lz2[ls(o)]*lz2[o];
        lz2[rs(o)] = lz2[rs(o)]*lz2[o];
        lz[ls(o)] = lz[ls(o)] * lz2[o] + lz[o];
        lz[rs(o)] = lz[rs(o)] * lz2[o] + lz[o];
        lz[o] = 0;
        lz2[o] = 1;
    }
}
void build(int o, int ll, int rr)
{
    if (ll == rr) {
        sum[o] = a[ll];
        l[o] = ll;
        r[o] = rr;
        return;
    }
    l[o] = ll;
    r[o] = rr;
    lz[o] = 0;lz2[o] =1;
    build(ls(o), ll, mid);
    build(rs(o), mid + 1, rr);
    pushup(o);
}
void add(int o, int ll, int rr, int L, int R, int delta)
{
    if (L <= ll && rr <= R) {
        sum[o] += (delta * (sz(o)));
        lz[o] += delta;
        return;
    }
    pushdn(o, mid - ll + 1, rr - mid);
    if (L <= mid)
        add(ls(o), ll, mid, L, R, delta);
    if (mid < R)
        add(rs(o), mid + 1, rr, L, R, delta);
    pushup(o);
}

void add2(int o, int ll, int rr, int L, int R, int delta)
{
    if (L <= ll && rr <= R) {
        lz[o] = lz[o] * delta;
        lz2[o] = lz2[o] * delta;
        sum[o] = delta * sum[o];
        return;
    }
    pushdn(o, mid - ll + 1, rr - mid);
    if (L <= mid)
        add2(ls(o), ll, mid, L, R, delta);
    if (mid < R)
        add2(rs(o), mid + 1, rr, L, R, delta);
    pushup(o);
}

int query(int o, int ll, int rr, int L, int R)
{
    int ans = 0;
    if (L <= ll && rr <= R) {
        return sum[o];
    }
    pushdn(o, mid - ll+1, rr - mid);
    if (L <= mid)
        ans += query(ls(o), ll, mid, L, R);
    if (mid < R)
        ans += query(rs(o), mid + 1, rr, L, R);
    pushup(o);
    return ans;
}
signed main()
{
#ifdef FUCKCCF
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#endif
    int n, m, fk;
    cin >> n >> m >> fk;
    fo(i, n) cin >> a[i];
    build(1, 1, n);
    fo(i, m)
    {
        int op;
        cin >> op;
        if (op == 1) {
            int _l, _r, del;
            cin >> _l >> _r >> del;
            add2(1, 1, n, _l, _r, del);
        } else if (op == 2) {
            int _l, _r, del;
            cin >> _l >> _r >> del;
            add(1, 1, n, _l, _r, del);
        } else if (op == 3) {
            int _l, _r;
            cin >> _l >> _r;
            cout << query(1, 1, n, _l, _r) << endl;
        }
    }
}