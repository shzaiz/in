#include <bits/stdc++.h>
#define N 100010
#define MAXN 100010
#define D double
using namespace std;
struct Edge{
	int from,to,nxt;
	double l,f;
	
}e[100010];
int head[100010],cnt=0,w[100010];
void adde(int u,int v,D l,D f){
	e[++cnt].to = v;
	e[cnt].from = u;
	e[cnt].nxt = head[u];
	e[cnt].l = l;
	e[cnt].f = f;
	head[u] = cnt;
}

struct EDGE{
	int to,nxt,w;
}e2[100010];
int head2[MAXN],cnt2=0;
#define head head2
#define cnt cnt2
#define e e2
void adde2(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	e[cnt].w = w;
	head[u] = cnt;
}
#undef head
#undef cnt
#undef e

int dfn[N],low[N],sum,vis[N],st[N],scc=0,tp,sccsz[N],scccnt[N];
void Tarjan(int u){
	dfn[u] = low[u] = ++sum;
	st[++tp] = u;vis[u] = 1;
	for(int i=head[u];i;i=e[i].nxt){
		int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(dfn[v] && vis[v]){
			low[u] = min(dfn[u],low[v]);
		}
	}
	if(low[u]==dfn[u]){
		++scc;
		while(st[tp]!=u){
			scccnt[st[tp]] = scc;
			sccsz[scc]++;
			vis[st[tp]] = 0;
			tp--;
		}
		scccnt[st[tp]] = scc;
		sccsz[scc]++;
		vis[st[tp]] = 0;
		tp--;
	}
}
#define vis vis2
#define Q Q2
#define e e2
#define head head2
#define cnt cnt2
queue <int > Q;
int vis[N],dis[N];
void spfa(int s){
	memset(dis,0xffff,sizeof dis);
	Q.push(s);vis[s] = 1;dis[s] =0;
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		vis[u] = 0;
		for(int i=head[u];i;i=e[i].nxt){
			int v = e[i].to;
			if(dis[v]<dis[u]+e[i].w+w[v]){
				dis[v] = dis[u]+e[i].w+w[v];
				if(!vis[v]) Q.push(v);vis[v] = 1;
			}
		}
	}
	
}
#undef vis
#undef Q
#undef e
#undef head
#undef cnt

int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		int x,y;D l,f;
		cin>>x>>y>>l>>f;
		adde(x,y,l,f);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
	for(int i=1;i<=m;i++){
		if(scccnt[e[i].to] == scccnt[e[i].from]){
			int id = scccnt[e[i].to];
			int t = e[i].l;
			while(t){
				w[id] += t;
				t =(int) t*e[i].f;
			}
		}else{
			int x = scccnt[e[i].from],y=scccnt[e[i].to];
			adde2(x,y,e[i].l);
		}
	}
	int start;cin>>start;
	spfa(start);
	int ans = 0;
	for(int i=1;i<)
	return 0;
}