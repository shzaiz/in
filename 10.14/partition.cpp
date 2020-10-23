#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e7 + 10;
int n, type, a[N], q[N], dp[N], sum[N], d[N];
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> type;
  for (register int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  int h, t;
  q[h = t = 0] = 0;
  for (register int i = 1; i <= n; i++) {
    while (h < t && d[q[h + 1]] + sum[q[h + 1]] <= sum[i]) ++h;
    d[i] = sum[i] - sum[q[h]];
    dp[i] = dp[q[h]] + (d[i] * d[i]);
    while (h < t && d[q[t]] + sum[q[t]] >= d[i] + sum[i]) --t;
    q[++t] = i;
  }
  cout << dp[n] << '\n';
  return 0;
}