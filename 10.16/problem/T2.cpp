#include <bits/stdc++.h>
#include <iomanip>
#define N 100005
#define D long double
#define eps 1e-9
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x7f7f7f7f7f7f7f7f
D n1[N],n2[N];
int p1=0,p2=0;
inline int phi(int n) {
  int ans = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}
inline int mul(int a, int b, int mod) {
  int ans = 0;
  while (b) {
    if (b & 1) ans = (ans + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return ans;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline void read(int &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  x *= f;
}
inline int qpow(int a, int n, int mod) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = mul(ans, a, mod);
    a = mul(a, a, mod);
    n >>= 1;
  }
  return ans;
}
int solve(){



    #ifndef ONLINE_JUDGE
  //  freopen("D:/Testcases/in.ac","r",stdin);
  //  freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
    int T;cin>>T;
  while (T--) {
    int L;
    read(L);
    if (!L) break;
    int A = L / gcd(L, 7), p = phi(9 * A);
    int ans = INF;
    for (int i = 1; i * i <= p; i++) {
      if (p % i) continue;
      if (qpow(10, i, 9 * A) == 1) {
        ans = i;
        break;
      }
      if (i * i != p && qpow(10, p / i, 9 * A) == 1) ans = p / i;
    }
    if(ans==INF){
        printf("XBZ AK IOI!!!\n");
    }else{
        printf("%lld\n",ans);
    }
    
  }
  return 0;

}

signed main(){
	for(int i = 1;i<=20;i++){
		freopen((to_string(i)+".in").c_str(),"r",stdin);
        freopen((to_string(i)+".out").c_str(),"w",stdout);
		solve();
        fclose(stdin);
        fclose(stdout);
        cin.clear();cout.clear();
	}
}
