#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define MOD 998244353
#define int long long
int f[2][N], alp[N], fst = 1, s[N] = {}, tp = 0, pv = -1, bk = -1, ans1 = 1,ans2 = 1, combo = false, n, k;
int head[N], cnt = 0;
int finalans = 0;
int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int qpow(int u, int v) {int rep = 1;while (v > 0) {if (v & 1) {rep = mul(rep, u);}u = mul(u, u);v >>= 1;}return rep;}
int sub(int a, int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
int divi(int a, int b) { return mul(a, qpow(b, MOD - 2)); }
struct Edge {int to, nxt;} e[N];
void adde(int u, int v) {e[++cnt].to = v;e[cnt].nxt = head[u];head[u] = cnt;}
void dfs(int u, int fa) {
  int an2 = ans2, pvv = -1, bkk = bk, com = 0, an1 = ans1, fstt = fst;s[++tp] = alp[u];
  if (u == 1 && s[tp] == 0) {
    ans2 = mul(ans2, k);an2 = ans2;combo = 1;finalans ^= mul(ans2, ans1);
  } else if (s[tp] == 0) {
    if (!combo) {pv = tp - 1;pvv = pv;} else {pvv = pv;}
    combo = 1;com = 1;ans2 = mul(ans2, (k - 1));an2 = ans2;finalans ^= mul(ans2, ans1);
  } else {
    bk = tp;bkk = bk;
    if (combo) {
      if (pv == -1 || fst) {ans1 = mul(1, qpow(k - 1, bk - 1));an1 = ans1;
      } else if (s[pv] == s[bk]) {ans1 = mul(ans1, f[1][bk - pv - 1]);an1 = ans1;
      } else {ans1 = mul(ans1, f[0][bk - pv - 1]);an1 = ans1;
	  }
      finalans ^= ans1;
    } else {
      if (fst) {ans1 = qpow(k - 1, tp - 1);an1 = ans1;finalans ^= ans1;
      } else { finalans ^= ans1;
      }
    }
    pv = tp, bk = -1;pvv = pv, bkk = bk;combo = false;com = combo;fstt = fst = 0;ans2 = 1;an2 = ans2;
  }
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs(v, u);
    pv = pvv;ans2 = an2;ans1 = an1;combo = com;bk = bkk;fst = fstt;tp--;
  }
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen("D:/Testcases/in.ac", "r", stdin);
  freopen("D:/Testcases/out.ac", "w", stdout);
#else
#endif
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> alp[i];
  for (int i = 1; i < n; i++) {int x;cin >> x;adde(i + 1, x);adde(x, i + 1);}
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {f[0][i] = (int)add(f[1][i - 1], mul((k - 2), f[0][i - 1]));f[1][i] = (int)mul((k - 1), f[0][i - 1]);}
  dfs(1, 0);
  printf("%lld\n", finalans);
}