#include <bits/stdc++.h>
#define int long long
#define MAXN 600009
using namespace std;
int n;
int z[MAXN],val[MAXN],in[MAXN],f[MAXN],fa[MAXN],ans = 0,mx = -214674;
struct Edge{
	int to,nxt;
}e[3*MAXN];
int cnt = 0,head[MAXN];
void adde(int u,int v){
	in[v]++;
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
void dfs(int u){
//	cout<<u<<endl;
	int cntb = 0;
	for(int i = head[u];i;i = e[i].nxt){
//		printf("%d\n",cntb);
		z[++cntb] = val[e[i].to];
	} 
	for(int i=1;i<=cntb;i++){
		for(int j=i+1;j<=cntb;j++){
			mx = max(mx,z[i]*z[j]);
			ans+= (z[i]%10007*z[j]%10007)%10007;
			ans%=10007;
		}
	}
//	cout<<"\n";
}
signed main(){
//	freopen("D:\\in.txt","r",stdin);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;adde(x,y);adde(y,x);
	}
	int ind=-1;
	for(int i=1;i<=n;i++){
		cin>>val[i];
		
	}
	for(int i=1;i<=n;i++){
//		printf("%d\n",in[i]);
		if(in[i]==1) {
			ind = i;break;
		}
	}
	
	
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	cout<<mx<<" "<<(ans*2)%10007;
	
}
