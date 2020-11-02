#include <bits/stdc++.h>
using namespace std;
struct node {
    int u, v;
    double w;
} a[1000000];
int n, f[10000], cnt, k, l;
int x[10000], y[10000];
void add(int uu, int vv, double ww)
{
    a[++cnt].u = uu;
    a[cnt].v = vv;
    a[cnt].w = ww;
}
bool cmp(node a1, node a2)
{
    return a1.w < a2.w;
}
int find(int u)
{
    if (f[u] == u)
        return u;
    else
        return f[u] = find(f[u]);
}
int main()
{
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            double s = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            add(i, j, s);
        }
    sort(a + 1, a + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++) {
        int uu = find(a[i].u);
        int vv = find(a[i].v);
        if (uu == vv)
            continue;
        f[uu] = vv;
        l++;
        if (l == n - k + 1) {
            printf("%.2lf", a[i].w);
            return 0;
        }
    }
    return 0;
}
