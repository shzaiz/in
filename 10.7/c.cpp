#include <bits/stdc++.h>
#define int long long
#define mod 998244353
long long a,b,ans;
void read(long long &x){
	int f=1;x=0;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
	while(s<='9'&&s>='0'){x=x*10%mod+(s-'0')%mod;s=getchar();}//改成了取模~~
    x=x%mod*f;
}
long long ksm(long long x,long long p){
	long long res=1;
	for(;p;p>>=1,x=x*x%mod)
		if(p&1)res=res*x%mod;
	return res;
}
int k;
signed main(){
    // freopen("10.7/wa1.in","r",stdin);
    // freopen("10.7/wa1.out","w",stdout);
	read(k);read(a);read(b);
    a = k*a;
	ans=a*ksm(b,mod-2);
	printf("%lld",(ans%mod+mod)%mod);  
}