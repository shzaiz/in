#include <bits/stdc++.h>
long long p = 0;
long long qu(long long x, long long y) {
  if (y == 0) {
    return 1;
  } else {
    long long dq = qu(x, y / 2);
    if (y % 2 == 0) {
      return ((dq % p) * (dq % p)) % p;
    } else if (y % 2 == 1) {
      return ((dq % p) * (dq % p) * (x % p)) % p;
    }
  }
}
int main() {
  long long m = 0, n = 0;
  scanf("%lld %lld", &m, &n);
  p = 100003;
  printf("%lld", (qu(m, n) - (m * qu(m - 1, n - 1)) % p + p) % p);
  return 0;
}