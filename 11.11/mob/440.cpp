#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
int mu[N],npr[N],cnt = 0, pr[N];const ll INF = 2 * 1e9; int T; ll k; 
void getmu(int n){
	mu[1] = 1;
	fo_(i,2,n){
		if(!npr[i]){
			pr[++cnt] =i;
			mu[i] = -1;
		}
		for(j = 1;j<=cnt && i*pr[j]<=n){
			npr[i*pr[j]] = 1;
			if(i%pr[j]==0){
				mu[i] = 0;
				break;
			}
			mu[pr[j]] = -mu[i];
		}
	}
} 
inline bool check(ll n) {
  ll ret = 0; 
  for(ll d = 1; d * d <= n; d++) 
    ret += (n / (d * d)) * mu[d];
  return ret >= k;  
}
int main() {

  scanf("%d", &T); prework(); 
  while(T--) {
    scanf("%lld", &k); 
    ll l = 0, r = k * 2, ans; 
    while(l <= r) {
      ll mid = (l + r) / 2; 
      if(check(mid)) r = mid - 1, ans = mid;
      else l = mid + 1; 
    } printf("%lld\n", ans);
  }
  return 0; 
}
