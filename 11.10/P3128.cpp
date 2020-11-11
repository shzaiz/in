#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define fog(i,x) for(int i = head[x];i;i = e[i].nxt)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
struct Edge{
	int to,nxt;
}e[N];
int head[N],cnt = 0,d[N],val[N];

void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
int n,k;
int dep[N], fa[N][20]; 
void dfs1(int u,int f){
	fa[u][0] = f;
	dep[u] = dep[f ]+1;
	for(int i = 1;i<20;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	fog(i,u){
		int v = e[i].to;
		if(v == f) continue;
		dfs1(v,u);
	}

} 

int lca(int u,int v){
	if(dep[u]>dep[v]) swap(u,v); 
	for(int i =19;i>=0;i--){
		if(dep[u]>dep[fa[v][i]] || fa[v][i]==0) continue;
		v = fa[v][i];
	}
	if(u==v) return u;
	for(int i = 19;i>=0;i--){
		if(fa[u][i] == fa[v][i] || fa[u][i]==0 || fa[v][i]==0) continue;
		v =fa[v][i];
		u = fa[u][i];
	}
	return fa[u][0];
}
 
void dfs(int u,int f){
	val[u] += d[u]; 
	fog(i,u){
		int v = e[i].to;
		if(v == f) continue;
		dfs(v,u);
		val[u] += val[v]; 
	}
}
int main(){
	realfl freopen("P3128.in","r",stdin);
	realfl freopen("P3128.out","w",stdout);
	cin>>n>>k;
	fo(i,n-1){
		int x,y;cin>>x>>y;adde(x,y);adde(y,x);
	}
	dfs1(1,0);
	fo(i,k){
		int s,t;
		cin>>s>>t;
		d[s]++; d[t]++; d[lca(s,t)]--; d[fa[lca(s,t)][0]]--;
	}
	int maxxx = -1,s;
	dfs(1,0);
	for(int i = 0;i<=n;i++){
		if(val[i]>maxxx) s = i, maxxx = val[i];
	}
	s =s;
	cout<<maxxx<<endl; 
}
