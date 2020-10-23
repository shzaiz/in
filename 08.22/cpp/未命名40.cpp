#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int to,nxt;
}e[10010];
int n,m;
int cnt,head[10010];
int dep[10010],fa[10010][20];
void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
void dfs1(int u){
	for(int i=1;(1<<i)<=dep[u];i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i=head[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(v==fa[u][0]) continue;
		dep[v] = dep[u]+1;
		fa[v][0]=u;
		dfs1(v);
	}
}

int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	// dep[x] < dep[y]
	for(int i=19;i>=0;i--){
		if((fa[y][i]==0)||(dep[fa[y][i]])<dep[x]) continue;
		y = fa[y][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(fa[x][i]==fa[y][i] || dep[fa[x][i]]==0) continue;
		y = fa[y][i],x = fa[x][i];
	}
	return fa[x][0];
}

int main(){
	freopen("D:\\in.txt","r",stdin);
	int n; int m; int k;
	cin>>n>>m>>k;
	dep[1] = 1;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		adde(x,y);adde(y,x);
	}
	dfs1(1);
	
	
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<endl;
	} 
}
