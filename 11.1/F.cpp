#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, k, f[100100], ans;
struct no {
    int x, y, z;
} a[100100];
bool comp(const no& a, const no& b)
{
    return a.z > b.z;
}
int find(int x)
{
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
void un(int x, int y)
{
    f[x] = y;
}
int main()
{
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    sort(a + 1, a + m + 1, comp);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1, kk = 0; i <= m && kk < k; i++) {
        int l = find(a[i].x), r = find(a[i].y);
        if (l != r) {
            un(l, r);
            kk++;
            ans += a[i].z;
        }
    }
    printf("%d", ans);
    return 0;
}