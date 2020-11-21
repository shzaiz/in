#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 100010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
#define int long long
struct Node{
	int a=0, b=0, s=0;
};
Node operator+(Node x,Node y){
	Node n;
	n.a = x.a+y.a;
	n.b = x.b+y.b;
	n.s = x.s+y.s+x.a*y.b;
	return n;
}
struct Edge{
	int to,nxt;
}e[N];
int head[N],cnt = 0;
int n,m;
void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
Node d[N][25],u[N][25];
int fa[N][25],dep[N];
int lca(int x,int y){
	if(dep[x]>dep[y] ) swap(x,y);
	for(int i = 19;~i;i--){
		if(dep[y]<dep[x] || fa[y][i]==0 ) continue;
		y = fa[y][i];
	}
	if(x == y) return x;
	for(int i = 19;~i;i--){
		if(y==x || fa[y][i]==0 || fa[x][i]==0) continue;
		x = fa[x][i]; y = fa[y][i];
	}
	return fa[x][0];
}
Node up(int x,int dis){
	Node tmp;
	for(int i=16;~i;i--)
		if((dis>>i)&1){
			tmp=tmp+u[x][i];
			x=fa[x][i];
		}
	return tmp;
}
Node dn(int x,int dis){
	Node tmp;
	for(int i=16;~i;i--)
		if((dis>>i)&1){
			tmp=d[x][i]+tmp;
			x=fa[x][i];
		}
	return tmp;
}
int Q(int x,int y){
	int t = lca(x,y);
	if(t==y) return up(x,dep[x]-dep[y]+1).s;
	if(t==x) return dn(y,dep[y]-dep[x]+1).s;
	return (up(x,dep[x]-dep[t]+1)+dn(y,dep[y]-dep[t])).s;
}
signed main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);

	cin>>n>>m;
	fo_(i,2,n) cin>>fa[i][0];
	fo(i,n) {
		cin>>u[i][0].a;
		d[i][0].a = u[i][0].a;
	}
	fo(i,n) {
		cin>>d[i][0].b;
		u[i][0].b = d[i][0].b;
	}
	for(int i=1;i<=n;i++){
		dep[i]=dep[fa[i][0]]+1;
		for(int j=1;j<19;j++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
			u[i][j]=u[i][j-1]+u[fa[i][j-1]][j-1];
			d[i][j]=d[fa[i][j-1]][j-1]+d[i][j-1];
		}
	}
	int x,y;
	while(m--){
		cin>>x>>y;
		cout<<Q(x,y)<<endl;
//		cout<<x<<" "<<y<<"LCA="<<lca(x,y)<<endl;
	}
	return 0;
} 
