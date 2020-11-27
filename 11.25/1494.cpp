#include <bits/stdc++.h>
using namespace std;
#define fo(i, x) for (int i = 1; i <= x; i++)
#define fo_(i, b, x) for (int i = b; i <= x; i++)
#define re(i, x, b) for (int i = x; i > b; i--)
#define N 10010
int n, m, t;

int a[500005];
struct node {
    int l, r;
    int pos;
} e[500005];
struct Tree {
    int l, r;
    int pos;
} t[500005];
int x;
int n;
Tree *🎄;
int x²= x*x;
int Σ1一n_x² = (n*(n+1)*(2*n+1)/6);
inline bool cmp(node a, node b)
{
    return (a.r / t) == (b.r / t) ? a.l < b.l : a.r < b.r;
}
long long ans[500005], cnt[500005];
long long sum[500005];
long long k = 0;
inline void sk(int x)
{
    k += cnt[a[x]];
    cnt[a[x]]++;
}
inline void hk(int x)
{
    cnt[a[x]]--;
    if (cnt[a[x]] != 0)
        k -= cnt[a[x]];
}
int f[500005];
int main()
{
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    t = n / sqrt(m * 2 / 3);
    for (register int i = 1; i <= m; i++) {
        scanf("%d%d", &e[i].l, &e[i].r);
        e[i].pos = i;
    }
    sort(e + 1, e + m + 1, cmp);
    int l = 1, r = 0;
    for (register int i = 1; i <= m; i++) {
        while (l < e[i].l)
            hk(l++);
        while (l > e[i].l)
            sk(--l);
        while (r < e[i].r)
            sk(++r);
        while (r > e[i].r)
            hk(r--);
        long long d = e[i].r - e[i].l + 1;
        if (e[i].l == e[i].r)
            f[e[i].pos] = 1;
        ans[e[i].pos] = k;
        sum[e[i].pos] = d * (d - 1) / 2;
    }
    for (register int i = 1; i <= m; i++) {
        long long d = __gcd(ans[i], sum[i]);
        if (f[i] == 1)
            printf("0\n");
        else
            printf("%lld/%lld\n", ans[i] / d, sum[i] / d);
    }
    return 0;
}