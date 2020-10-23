#include <bits/stdc++.h>

typedef long long ll;

const int MN = 105, MM = 2e3 + 5;

int n, m, ans = 1, a[MN][MM], sum[MN], dp[MN][MN << 1];

const int P = 998244353;
using namespace std;
inline int add(int x, int y) { return (x += y) >= P ? x - P : x; }
inline int dec(int x, int y) { return (x -= y) < 0 ? x + P : x; }
inline int mul(int x, int y) { return (ll)x * y % P; }

int main() {
#ifndef ONLINE_JUDGE
freopen("D:/Testcases/in.ac","r",stdin);
freopen("D:/Testcases/out.ac","w",stdout);
#else
  freopen("meal.in", "r", stdin);
  freopen("meal.out", "w", stdout);
#endif

  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      sum[i] = add(sum[i], a[i][j]);
    }

  for (int i = 1; i <= n; ++i) ans = mul(ans, sum[i] + 1);

  ans = dec(ans, 1);

  for (int i = 1; i <= m; ++i) {
    memset(dp, 0, sizeof dp);
    dp[0][100] = 1;
    for (int j = 0; j < n; ++j)
      for (int k = 100 - j; k <= 100 + j; ++k) {
        dp[j + 1][k] = add(dp[j + 1][k], dp[j][k]);
        dp[j + 1][k + 1] = add(dp[j + 1][k + 1], mul(dp[j][k], a[j + 1][i]));
        dp[j + 1][k - 1] =
            add(dp[j + 1][k - 1], mul(dp[j][k], dec(sum[j + 1], a[j + 1][i])));
      }
    for (int j = 101; j <= 100 + n; ++j) ans = dec(ans, dp[n][j]);
  }

  cout << ans << endl;
}