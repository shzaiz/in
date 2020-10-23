#include <bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;
int n,k,l,t,stan,note[27]={0},f[23][1550007]={0};
ll qpow(ll a, ll b){
	ll ans = 1;
	while(b > 0){
		if(b & 1){
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b >>= 1; 
	} 
	return ans;
}
int dfs(int v,int ff){
    if(f[v][ff]!=-1) return f[v][ff]; 
    if(ff&t) return f[v][ff]=qpow(l+1,n-v+1);
    if(v==n+1) return f[v][ff]=(ff&t);
    int ans=0;
    ll temp;
    
    for(int i=0;i<=min(k,l);i++) {
        temp=((ll)dfs(v+1,(ff|(ff<<i))&stan))%mod;
        ans=(ans+temp)%mod;
    }
    if(l>k)
    {
        temp=(((ll)((ll)dfs(v+1,ff)%mod*(ll)(l-k))%mod))%mod;
        	
        ans=(ans+temp)%mod;//返回
    }
    return f[v][ff]=ans%mod;
}
int main()
{
    scanf("%d%d%d",&n,&k,&l);//输入
    memset(f,-1,sizeof(f));//备忘录初始化
    note[0]=1;
    for(int i=1;i<=n;i++) note[i]=(ll)((ll)note[i-1]*(ll)(l+1))%mod;
    //递推计算(l+1)的i次方
    t=(1<<k);//取与判断是否能得到k的标准
    stan=(1<<(k+1))-1;//用于去与防止左移后 超出n的范围 的标准
    printf("%d\n",dfs(1,1)%mod);
    return 0;
}