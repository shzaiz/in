#include <bits/stdc++.h>
using namespace std;
#define D double
#define MOD 998244353
#define N 100010
int n;
D m, g;
int x[N], y[N];
int add(int a, int b) {
  return (a % MOD + b % MOD) % MOD;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("D:/Testcases/in.ac", "r", stdin);
  freopen("D:/Testcases/out.ac", "w", stdout);
#else
  freopen("jump.in", "r", stdin);
  freopen("jump.out", "w", stdout);
#endif
  cin >> n >> m >> g;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 2; i <= n; i++) {
    if (y[i] > y[i - 1]) {
      // printf("Upward\n");
      int dy = y[i] - y[i - 1];
      int dx = x[i] - x[i - 1];
      ans = add(ans, m * g * dy + m * ((dx * dx * g) / 4 * dy));
    } else if (y[i] == y[i - 1]) {
      // printf("Plain\n");
    } else if (y[i] < y[i - 1]) {
      // printf("Downward\n");
      int dy = y[i] - y[i - 1];
      int dx = x[i] - x[i - 1];
      ans = add(ans, m * ((dx * dx * g) / 4 * dy));
    }
  }
  printf("%dJ\n", ans);
}