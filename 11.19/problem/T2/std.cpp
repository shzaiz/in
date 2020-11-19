#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
const int MAXN = 5050;
int f[MAXN][MAXN/2];
int n, m;
int prod[MAXN];
inline int advPow (int a, int b) {
	int ret = 1;
	while(b) {
		if(b&1) ret = ret*a%MOD;
		a = a*a%MOD;
		b >>= 1;
	}
	return ret;
}
inline int C (int a, int b) {
	return prod[a]*advPow(prod[b]*prod[a-b]%MOD, MOD-2)%MOD;
}
signed main () {
	#ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
	cin>>n>>m;
	if(m == 1 || n == 1) {
		puts("1");
		return 0 ;
	}
	if(n == 2) {
		puts("2");
        return 0;
	}
	f[0][0] = 1;
	f[1][1] = 1;
	f[2][1] = 1;
	prod[0] = 1;
	for(int i = 1; i<=n; i++) prod[i] = prod[i-1]*i%MOD;
	for(int i = 3; i<=n; i++)
		for(int j = 1; j<=((i+1)/2); j++)
			f[i][j] = (f[i-2][j-1]+ f[i-1][j-3])%MOD;
	int ans = 0;
	for(int i = 1; i<=((n+1)/2); i++) {
		if(f[n][i]) ans = (ans+f[n][i]*C(n-i, m-i)%MOD*prod[m]%MOD)%MOD;
		if(f[n-1][i]) ans = (ans+f[n-1][i]*C(n-i, m-i)%MOD*prod[m]%MOD)%MOD;
	}
	cout<<ans;
}