#include <bits/stdc++.h>
using namespace std;
#define fo(i, x) for (int i = 1; i <= x; i++)
#define fo_(i, b, x) for (int i = b; i <= x; i++)
#define re(i, x, b) for (int i = x; i > b; i--)
#define N 10010
int n, m, a[N][N], l[N][N], r[N][N], h[N][N], ans;
char c;
inline void solve()
{
    for (int i = 1; i <= m; i++)
        r[0][i] = m + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            h[i][j] = a[i][j] ? h[i - 1][j] + 1 : 0;
        int t = 0;
        for (int j = 1; j <= m; j++)
            if (a[i][j])
                l[i][j] = max(l[i - 1][j], t);
            else
                l[i][j] = 0, t = j;
        t = m + 1;
        for (int j = m; j; j--)
            if (a[i][j])
                r[i][j] = min(r[i - 1][j], t);
            else
                r[i][j] = m + 1, t = j;
        for (int j = 1; j <= m; j++)
            ans = max(ans, (r[i][j] - l[i][j] - 1) * h[i][j]);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> c;
            a[i][j] = (c == 'F') ? 1 : 0;
        }
    solve();
    cout << ans * 3;
    return 0;
}