#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
inline int qpow (int a, int b) {int ret = 1;while(b) {if(b&1) ret = ret*a%MOD;a = a*a%MOD;b >>= 1;}return ret;}
int n = 1;
signed main () {
	#ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
	cin>>n;
	if(n == 1) puts("1");
	else if(n == 2) puts("6");
	else printf("%d\n", (int)((n%MOD*qpow(2, n-1)%MOD+n%MOD*((n-1)%MOD)%MOD*qpow(2, n-2)%MOD)%MOD));
}