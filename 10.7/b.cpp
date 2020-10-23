#include<bits/stdc++.h>
using namespace std;
const int N = 200505;
#define MOD 998244353
#define int long long
int n,m,k;
struct Edge{
	int to,nxt,w;
	
}e[N];
int head[N],cnt=0;
int b[N];
int add(int a,int b){
    return ((a%MOD)+(b%MOD)%MOD);
}
int qpow(int a,int x,int mod){
  int ans=1,base=a;
  while(x>0){
  	if(x%2==1)
  	  ans=(ans*base)%mod;
  	base=(base*base)%mod;
  	x/=2;
  }
  return ans;
}
void adde(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
	e[cnt].w= w;
}
void dfs(int u,int len){
    // printf("%d\n",u);
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].to;
        b[v] =add(b[v],qpow((len+1),k,MOD)) ;
        dfs(v,len+1);
    }
}
signed main(){
    // freopen("10.7/wa1.in","r",stdin);
    // freopen("10.7/wa1.out","w",stdout);
	cin>>n>>m>>k;
    for(int i = 0;i<m;i++){
        int x,y;cin>>x;cin>>y;
        adde(x,y,0);
    }
    dfs(1,0);

	for(int i = 1;i<=n;i++){
        cout<<b[i]<<endl;
    }
	// toposort();
	return 0 ;
} 