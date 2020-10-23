#include <bits/stdc++.h>
#define reg register
#define int long long
using namespace std;
const int MaxN = 150;
const int base = 100000000;
const int pow10[] = {1,      10,      100,      1000,     10000,
                     100000, 1000000, 10000000, 100000000};
int s[MaxN], k;
struct Bigint {
  int a[MaxN], n;
  inline void clear() {
    memset(a, 0, sizeof a);
    n = 1;
    return;
  }
  inline void work() {
    while (n > 1 && !a[n]) --n;
    return;
  }
  inline Bigint read() {
    memset(s, 0, sizeof s);
    clear();
    reg int cnt = 0;
    reg char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) s[++cnt] = c ^ '0', c = getchar();
    for (int i = 1; i <= (cnt >> 1); ++i) swap(s[i], s[cnt - i + 1]);
    n = 0;
    for (int i = 1; i <= cnt; i += 8) {
      ++n;
      a[n] += s[i + 7] * 10000000;
      a[n] += s[i + 6] * 1000000;
      a[n] += s[i + 5] * 100000;
      a[n] += s[i + 4] * 10000;
      a[n] += s[i + 3] * 1000;
      a[n] += s[i + 2] * 100;
      a[n] += s[i + 1] * 10;
      a[n] += s[i + 0] * 1;
    }
    work();
    return *this;
  }
  inline void write() const {
    printf("%lld", a[n]);
    for (int i = n - 1; i; --i) printf("%08lld", a[i]);
    puts("");
    return;
  }
  inline Bigint operator*(const Bigint &nt) const {
    Bigint res;
    res.clear();
    res.n = min(105ll, n + nt.n);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= nt.n; ++j)
        if (i + j - 1 <= k) res.a[i + j - 1] += a[i] * nt.a[j];
    for (int i = 1; i <= res.n; ++i)
      res.a[i + 1] += res.a[i] / base, res.a[i] %= base;
    res.work();
    return res;
  }
  inline bool operator<(const Bigint &nt) const {
    if (n != nt.n) return n < nt.n;
    for (int i = n; i; --i)
      if (a[i] != nt.a[i]) return a[i] < nt.a[i];
    return false;
  }
};
template <class t>
inline void read(t &s) {
  s = 0;
  reg int f = 1;
  reg char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  s *= f;
  return;
}
inline bool issame(const Bigint &a, const Bigint &b) {
  int T = k / 8;
  for (int i = 1; i <= T; ++i)
    if (a.a[i] != b.a[i]) return false;
  reg int lim = pow10[k - T * 8];
  return a.a[T + 1] % lim == b.a[T + 1] % lim;
}
inline Bigint fastpow(Bigint a, int b) {
  reg Bigint res;
  res.clear();
  res.a[1] = 1;
  for (; b; b >>= 1, a = a * a)
    if (b & 1) res = res * a;
  return res;
}
Bigint A, B, t, two, five;
Bigint ans;
Bigint fivepow[150], twopow[150];
Bigint dp[150][150];
signed main(void) {
  A.read();
  read(k);
  if (A.a[1] == 1 && A.n == 1) {
    puts("0");
    return 0;
  }
  if (A.a[1] == 0 && A.n == 1) {
    puts("0");
    return 0;
  }
  if (issame(A * A, A)) {
    puts("1");
    return 0;
  }
  two.clear();
  five.clear();
  ans.clear();
  ans.a[1] = -1;
  two.a[1] = 2;
  five.a[1] = 5;
  {
    for (int i = 0; i < k; ++i) fivepow[i].clear();
    fivepow[0].a[1] = 1;
    for (int i = 1; i < k; ++i) fivepow[i] = fivepow[i - 1] * five;
  }
  {
    for (int i = 0; i <= k + 1; ++i) twopow[i].clear();
    twopow[0].a[1] = 1;
    for (int i = 1; i <= k + 1; ++i) twopow[i] = twopow[i - 1] * two;
  }
  {
    for (int i = 0; i <= k + 1; ++i)
      for (int j = 0; j < k; ++j) dp[i][j].clear();
    dp[0][0] = A;
    for (int i = 1; i <= k + 1; ++i) dp[i][0] = dp[i - 1][0] * dp[i - 1][0];
    for (int i = 0; i <= k + 1; ++i)
      for (int j = 1; j < k; ++j)
        dp[i][j] = dp[i][j - 1] * dp[i][j - 1] * dp[i][j - 1] * dp[i][j - 1] *
                   dp[i][j - 1];
  }
  for (int i = 0; i <= k + 1; ++i) {
    for (int j = 0; j < k; ++j) {
      if (!i && !j) continue;
      B = twopow[i] * fivepow[j];
      t = dp[i][j] * A;
      if (issame(t, A)) {
        if (ans.a[1] == -1 || B < ans) ans = B;
      }
    }
  }
  ans.write();
  return 0;
}