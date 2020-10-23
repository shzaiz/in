#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
struct Edge{
	int to,nxt;
}e[MAXN];
int dep[MAXN],fa[100010][20],h[MAXN],w[MAXN],n,m;
int head[MAXN],cnt;
void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void dfs1(int x){
	for(int i=1; (1<<i)<=dep[x]; i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];                           //x的2^i代祖宗就是x的2^{i-1}代祖宗的2^{i-1}代祖宗
	for(int i=head[x]; i; i=e[i].nxt){
		int y=e[i].to;
		if(y==fa[x][0])	continue;                               //如果y是父结点，跳过
		fa[y][0]=x;
		dep[y]=dep[x]+1;
		dfs1(y);
	}
}

int lca(int x,int y){
	if(x==y) return x;
	if(dep[x]>dep[y]) swap(x,y);
	// let dep[x]<dep[y]
	for(int i = 19;i>=0;i--){
		//printf("%d,%d\n",i,fa[y][i]);
		if(dep[fa[y][i]]==0 || dep[fa[y][i]]<dep[x]) continue;
		y = fa[y][i];
		printf("New x:%d",y);
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(dep[fa[x][i]]==0 || fa[y][i]==fa[x][i]) continue;
		x = fa[x][i],y = fa[y][i];
	} 
	return fa[x][0];
}

int main(){
	freopen("D:\\in.txt","r",stdin); 
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adde(u,v);adde(v,u);
	}
	dep[1] = 1;
	fa[1][0] = 0;
	dfs1(1);
	cout<<dep[fa[7][0]]<<" "<<dep[3]<<"!!!\n";
	cout<<lca(7,8);
	return 0;
}
