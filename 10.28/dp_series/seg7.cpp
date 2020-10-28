#include <bits/stdc++.h>
#define lson o << 1
#define rson (o << 1) | 1
using namespace std;
const int maxn = 1e4 + 7, maxm = 1e6 + 7;
int n, a[maxn], tong[maxm], maxx[maxn * 4];
void up(int o)
{
    maxx[o] = max(maxx[lson], maxx[rson]);
}
void Insert(int o, int l, int r, int pos, int v)
{
    if (l == r) {
        maxx[o] = v;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        Insert(lson, l, mid, pos, v);
    else
        Insert(rson, mid + 1, r, pos, v);
    up(o);
}
int quiry_(int o, int l, int r, int ll, int rr)
{
    if (ll <= l && rr >= r)
        return maxx[o];
    int mid = (l + r) / 2, ans = 0;
    if (ll <= mid)
        ans = quiry_(lson, l, mid, ll, rr);
    if (rr > mid)
        ans = max(ans, quiry_(rson, mid + 1, r, ll, rr));
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= a[i]; ++j) {
            if (a[i] % j)
                continue;
            tong[j]++;
            int y = a[i] / j;
            if (y != j)
                tong[y]++;
        }
    }
    for (int i = 1; i <= 1e6; ++i)
        if (tong[i] > 0)
            Insert(1, 1, n, tong[i], i);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", quiry_(1, 1, n, i, n));
    return 0;
}