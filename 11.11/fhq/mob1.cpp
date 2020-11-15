#include<bits/stdc++.h>
using namespace std;
const int mod=20101009,N=10000005;
int f[N],pr[N],is[N],s[N];
int n,m,tot,ans,div2;
int qm(int x) {return x>=mod?x-mod:x;}
void init() {
    f[1]=1;
    for(int i=2;i<=n;++i) {
        if(!is[i]) pr[++tot]=i,f[i]=qm(mod+1-i);
        for(int j=1;j<=tot&&i*pr[j]<=n;++j) {
            int k=i*pr[j]; is[k]=1;
            if(i%pr[j]) f[k]=1LL*f[i]*f[pr[j]]%mod;
            else {f[k]=f[i];break;}
        }
    }
    for(int i=1;i<=n;++i) f[i]=qm(f[i-1]+1LL*f[i]*i%mod);
    for(int i=1;i<=m;++i) s[i]=qm(s[i-1]+i);
}
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
   	scanf("%d%d",&n,&m);
   	if(n>m) swap(n,m);
   	init();
   	for(int i=1,j;i<=n;i=j+1) {
   		j=min(n/(n/i),m/(m/i));
   		ans=qm(ans+1LL*qm(f[j]-f[i-1]+mod)*s[n/i]%mod*s[m/i]%mod);
   	}
   	printf("%d\n",ans);
    return 0;
}