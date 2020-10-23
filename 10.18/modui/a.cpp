#include <bits/stdc++.h>
#define N 100005
using namespace std;
inline int read() {
  register int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
int v[N], blocksize = 0;
struct query {
  int l, r, id, bl;
} q[N];
int sum[N];
bool ans[N];
int cnt = 0;
inline void add(register int x) {
  if (++sum[v[x]] == 1) ++cnt;
}
inline void del(register int x) {
  if (--sum[v[x]] == 0) --cnt;
}
inline bool cmp(register query a, register query b) {
  return a.bl != b.bl ? a.l < b.l : ((a.bl & 1) ? a.r < b.r : a.r > b.r);
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("D:/Testcases/in.ac", "r", stdin);
  freopen("D:/Testcases/out.ac", "w", stdout);
#else
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif
  memset(sum, 0, sizeof(sum));
  int n = read(), m = read();
  blocksize = sqrt(n);
  for (register int i = 1; i <= n; ++i) v[i] = read();
  for (register int i = 1; i <= m; ++i) {
    int l = read(), r = read();
    q[i] = (query){l, r, i, (l - 1) / blocksize + 1};
  }
  sort(q + 1, q + m + 1, cmp);
  int l = 1, r = 0;
  for (register int i = 1; i <= m; ++i) {
    int ll = q[i].l, rr = q[i].r;
    while (l < ll) del(l++);
    while (l > ll) add(--l);
    while (r < rr) add(++r);
    while (r > rr) del(r--);
    ans[q[i].id] = (cnt == rr - ll + 1) ? 1 : 0;
  }
  for (register int i = 1; i <= m; ++i)
    if (ans[i])
      puts("Yes");
    else
      puts("No");
  return 0;
}