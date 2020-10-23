#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,m;
int a[10010];
ll qpow(ll a,ll b,ll n){ll t,y;t=1; y=a;while (b!=0){if (b&1==1) t=t*y%n;y=y*y%n; b=b>>1;}return t;}
const long long MOD = 998244353;
void input(){
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
}
void sub3(){
	// SUBTEST 3 PASS
	ll ans = qpow(k-1,n-1,MOD);
	cout<<ans;
	return;
}
void sub4(){
	int f[101010][2] = {};
	f[0][0] = 1;f[0][1] =0;
	for(int i=1;i<=n;i++){
		f[i][0] = (f[i-1][0]+(k-2)*f[i-1][1])%MOD;
		f[i][1] = ((k-1)*f[i-1][0])%MOD;
	} 
	if(a[1]==a[n]) cout<<f[n][0];
	else cout<<f[n][1];
}


int main(){
	freopen("D:\\in.txt","r",stdin);
	input();
	sub3();
} 
