#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define int long long
#define mod (1000000007)
int n,m,r,c,s,ans;
int fac[200005],iv[200005],f[200005];
int C(int a,int b){
	if(b==0)return 1;
	return fac[a]*f[a-b]%mod*f[b]%mod;
}
void solve(int a,int b){
	if(b<0||b>c||b>m)return;
	if((r-a)==1||(c-b)==1)return;
	int t1=(r-a)/2,t2=(c-b)/2;
	int tot=C(n,a)*C(m,b)%mod;
	if(b==0)tot=tot*C(n+t1-1,n-1)%mod*C(m+c-1,m-1)%mod;
	else tot=tot*C(n+t1-1,n-1)%mod*C(m+t2-1,m-1)%mod;
	ans=(ans+tot)%mod;
}
int main(){
	freopen("Caitlyn.in","r",stdin);
	freopen("Caitlyn.out","w",stdout);
	fac[0]=1;fo(i,200004) fac[i]=fac[i-1]*i%mod;
	iv[1]=1;
	fo_(x,2,200004){
		int a=mod/x,b=mod%x;
		iv[x]=(-a*iv[b]%mod+mod)%mod;
	}
	f[0]=1;fo(i,200000)f[i]=f[i-1]*iv[i]%mod;
	cin>>n>>m>>r>>c>>s;
	for(int a=0;a<=r&&a<=n;a++){
		if(n-2*a==0){if(a*m==s&&c%2==0){solve(a,0);continue;}} 
		else if((s-a*m)%(n-2*a)==0) solve(a,(s-a*m)/(n-2*a));
    }
	cout<<ans<<endl;
	return 0;
}