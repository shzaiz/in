#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll qpow(ll a, ll b){
	ll ans = 1;
	while(b > 0){
		if(b & 1){
			ans = ans * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1; 
	} 
	return ans;
}
ll n,k,l,ans;
int dp[50][1<<19];
ll dfs(int i,int st){
	if(dp[i][st] != -1) return dp[i][st];
	if(st & (1<<k)) return dp[i][st] = qpow(l+1,n-i+1); // 随便选
	if(i == n+1) return dp[i][st] = st & (1<<k);
	ll ans = 0;
	for(int ii=0;ii<=min(k,l);ii++){  // 枚举能力值=min(k,l)
		ans += (dfs(i+1,st|st<<ii)%MOD);
	}
	if(l>k){
		ans+= (dfs(i+1,st)%MOD)*((l-k)%MOD)%MOD;
	}
	return dp[i][st] = ans%MOD;
}
int main(){
	freopen("basketball2.in","r",stdin); 
	freopen("basketball2.out","w",stdout); 
	memset(dp,-1,sizeof dp);
	cin>>n>>k>>l;
	cout<<dfs(1,1)%MOD;
}
