#include <bits/stdc++.h>
using namespace std;
#define D double
#define N 9080040
int fa[N];
int S, P;
int cnt = 0;
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool unite(int x, int y)
{
    int xx = find(x);
    int yy = find(y);
    if (xx == yy)
        return 0;
    else
        fa[yy] = xx;
}
bool same(int x, int y)
{
    return find(x) == find(y);
}
int x[N], y[N];
struct Edge {
    int frm, to, nxt;
    D w;
} e[N];
D dist(D x1, D x2, D y1, D y2)
{
    return sqrt(abs((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}
int main()
{
#ifdef FUCKCCF
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
    freopen("wireless.in", "r", stdin);
    freopen("wireless.out", "w", stdout);
#endif
    for (int i = 0; i <= N; i++)
        fa[i] = i;
    cin >> S >> P;
    for (int i = 1; i <= P; i++) {
        cin >> x[i] >> y[i];
        for (int j = 1; j < i; j++) {
            e[++cnt].frm = j;
            e[cnt].to = i;
            e[cnt].w = dist(x[i], x[j], y[i], y[j]);
            // printf("%d,%d = %lf\n",i,j,dist(x[i],x[j],y[i],y[j]));
        }
    }
    sort(e + 1, e + cnt + 1, cmp);
    // for(int i = 1;i<=cnt;i++) printf("[%d --> %d] = %lf\n",e[i].frm,e[i].to,e[i].w);
    int chose = 0;
    D ans = 0;
    for (int i = 1; i <= cnt; i++) {
        int u = e[i].to;
        int v = e[i].frm;
        if (!same(u, v)) {
            unite(u, v);
            ans = e[i].w;
            chose++;
            if (chose == P-S)
                break;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
}