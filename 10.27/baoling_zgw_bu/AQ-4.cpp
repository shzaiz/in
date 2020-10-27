#include <bits/stdc++.h>
#define maxn 100007
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;
int n, m, tim;
ll maxx[maxn << 2], sum[maxn << 2];
inline ll qread()
{
    char c = getchar();
    ll num = 0, f = 1;
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar())
        num = num * 10 + c - '0';
    return num * f;
}
inline void pushup(int rt)
{
    sum[rt] = sum[ls] + sum[rs];
    maxx[rt] = max(maxx[ls], maxx[rs]);
}
void build(int rt, int l, int r)
{
    if (l == r) {
        sum[rt] = maxx[rt] = qread();
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(rt);
}
void modify(int rt, int l, int r, int L, int R)
{
    if (l == r) {
        sum[rt] = sqrt(sum[rt]);
        maxx[rt] = sqrt(maxx[rt]);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid && maxx[ls] > 1)
        modify(ls, l, mid, L, R);
    if (R > mid && maxx[rs] > 1)
        modify(rs, mid + 1, r, L, R);
    pushup(rt);
}
ll csum(int rt, int l, int r, int L, int R)
{
    if (L > r || R < l)
        return 0;
    if (L <= l && r <= R)
        return sum[rt];
    int mid = (l + r) >> 1;
    return csum(ls, l, mid, L, R) + csum(rs, mid + 1, r, L, R);
}
int main()
{
    while (scanf("%d", &n) == 1) {
        printf("Case #%d:\n", ++tim);
        build(1, 1, n);
        m = qread();
        for (int i = 1, k, x, y; i <= m; ++i) {
            k = qread(), x = qread(), y = qread();
            if (x > y)
                swap(x, y);
            if (!k)
                modify(1, 1, n, x, y);
            else
                printf("%lld\n", csum(1, 1, n, x, y));
        }
    }
    return 0;
}