#include <bits/stdc++.h>
#define ll long long
#define fo freopen
using namespace std;
ll qpow(ll a,ll b,ll n){ll t,y;t=1; y=a;while (b!=0){if (b&1==1) t=t*y%n;y=y*y%n; b=b>>1;}return t;}
int main(){
	fo("matrix.in","r",stdin);fo("matrix.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ll n,m,x,p;
		scanf("%lld %lld %lld %lld",&n,&m,&x,&p);
		int hangxor = -1;
		for(int i=1;i<=n;i++) if(hangxor==-1) cin>>(hangxor); else {int tmp;cin>>tmp;hangxor ^= tmp;}
		int liexor = -1;
		for(int i=1;i<=m;i++) if(liexor==-1) cin>>(liexor); else {int tmp;cin>>tmp;liexor ^= tmp;}
		if(hangxor != liexor) return 0*printf("0\n"); 
		ll ans = qpow(++x,((n-1))%p*(m-1)%p,p);
		cout<<ans<<endl; 
	}
}
