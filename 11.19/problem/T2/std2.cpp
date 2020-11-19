#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 5050
#define int long long
const int MOD = 1000000007;
int f[N][N/2];
int n, m;
int prod[N];
int add(int x,int y){return (x%MOD+y%MOD)%MOD;}
int mul(int x,int y){return (x%MOD*y%MOD)%MOD;}
inline int qpow (int a, int b) {int ret = 1;while(b) {if(b&1) ret = ret*a%MOD;a = a*a%MOD;b >>= 1;}return ret;}
inline int C (int a, int b) {
	return prod[a]*qpow(prod[b]*prod[a-b]%MOD, MOD-2)%MOD;
}
signed main () {
	#ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
	cin>>n>>m;
	if(m == 1 || n == 1) {puts("1");return 0;}
	if(n == 2) {puts("2"); return 0;}
	f[0][0] = 1;f[1][1] = 1;f[2][1] = 1;
	prod[0] = 1;
	fo(i,n) prod[i] = prod[i-1]*i%MOD;
	fo_(i,3,n)fo(j,(i+1)/2)f[i][j] = (f[i-2][j-1]+ f[i-1][j-3])%MOD;
	int ans = 0;
	fo(i,(n+1)/2) {
		if(f[n][i]) ans = (ans+f[n][i]*C(n-i, m-i)%MOD*prod[m]%MOD)%MOD;
		if(f[n-1][i]) ans = (ans+f[n-1][i]*C(n-i, m-i)%MOD*prod[m]%MOD)%MOD;
	}
	cout<<ans;
    return 0;
}