#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int to,nxt;
}e[500010];
int head[500010],cnt=0;
int dep[500010] , fa[500010][20],val[500010],start[500010],end[500010];
int t[500010];
void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

int dfs1(int x){
	for(int i = 1;(1<<i)<dep[x];i++) fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i = e[i].nxt){
		int v = e[i].to;
		if(v==fa[x][0] ) continue;
		dep[v] = dep[x]+1;
		fa[v][0] = x;
		dfs1(v);
	}
}

int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	// Let dep[x] < dep[y]. 
	for(int i = 19;i>=0;i--){
		if(dep[fa[y][i]]==0|| dep[fa[y][i]]<dep[x]) continue;
		y = fa[y][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(dep[fa[y][i]]==0 || fa[y][i] == fa[x][i]) continue;
		y = fa[y][i];x = fa[x][i];
	}
	return fa[y][0];
}

int task0(){
	
	int n; int m;
	cin>>n>>m;
	dep[1] = 1;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		adde(x,y);adde(y,x);
	}
	dfs1(1);
	for(int i=1;i<=n;i++) {
		cin>>t[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		int turn = lca(x,y);
		int time = 0;
		while(x!=turn){
//			printf("%d\n",time);
			if(t[x] == time){
				val[x]++;
			}
			time++;
			x = fa[x][0];
		}
		if(t[turn]==time) val[x]++;
		int time2 = time+(dep[y]-dep[turn]);
		while(y!=turn){
//			printf("%d\n",y);
			if(t[y] == time2){
				val[y]++;
			}
			time2--;
			y = fa[y][0];
		}
	} 
	for(int i=1;i<=n;i++){
		printf("%d ",val[i]);
	}
}


int main(){
	freopen("D:\\in.txt","r",stdin);
	
}
