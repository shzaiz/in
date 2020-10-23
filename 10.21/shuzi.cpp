#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
inline int ksm(int a,int b){int r=1;for(;b;a=a*a%mod,b>>=1)if(b&1)r=r*a%mod;return r;}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    #endif
    int n,m;cin>>n>>m;
    if(n>m) swap(n,m);
    if(n==1) cout<<ksm(2,m);
    else if(n == 2)printf("%lld",4*ksm(3,m-1)%mod);
	else if(n == 3)printf("%lld",112*ksm(3,m-3)%mod);
    else if(m == n)printf("%lld",(83*ksm(8,n)%mod+5*ksm(2,n+7)%mod)*190104168%mod);
		else printf("%lld",(83*ksm(8,n)%mod+ksm(2,n+8))*ksm(3,m-n-1)%mod*570312504%mod);
}