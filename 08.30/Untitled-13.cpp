#include <bits/stdc++.h>
#define N 10010
using namespace std;

inline int read(){
	int x;
    x=0;char ch=0;bool sign=false;
    while(ch < '0' || ch > '9'){
        sign|=(ch == '-');
        ch=getchar();
    }
    while(!(ch < '0' || ch > '9')){
        x=x*10+(ch^48);
        ch=getchar();
    }
    x=sign ? -x : x;
    return x;
}

inline void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
struct Edge{
	int from,to,nxt;
	
}e[100010],e2[1000010];
int head[100010],head2[100010],cnt=0,cnt2=0,val[100010];
int start = -1;
void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].from = u;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
#define cnt cnt2
#define head head2
#define e e2
void adde2(int u,int v){
	e[++cnt].to = v;
	e[cnt].from = u;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
#undef cnt
#undef head
#undef e
int far[10010];
int indeg[10010];
#define cnt cnt2
#define head head2
#define e e2

int dfs(int u){
	far[u] = max(far[u],val[u]);
	for(int i = head[u];i;i = e[i].nxt){
		
		int v = e[i].to;
		dfs(v);
		far[u] = max(far[u],val[v]);
		far[u] = max(far[u],far[v]);
		far[u] = max(far[u],val[u]);
	}
}
#undef cnt
#undef head
#undef e
int low[N],dfn[N],s[N],tp=0,scc=0,scccnt[N],sccsz[N],sum=0,vis[N];
void Tarjan(int u){
	low[u] = dfn[u] = ++sum;
	s[++tp] = u;vis[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(vis[v]){
			low[u] = min(dfn[u],low[v]);
		}
	}
	if(dfn[u]==low[u]){
		scc++;
		while (s[tp]!= u){
			scccnt[s[tp]] = scc;
			sccsz[scc]++;
			vis[s[tp]]=0;
			tp--;
		}
		scccnt[s[tp]] = scc;
		sccsz[scc]++;
		vis[s[tp]]=0;
		tp--;
	}
}

int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	val[0] = 0;
	int m=read(),n=read();
	for(int i=1;i<=n;i++){
		int x=read(),y=read();
		adde(x,y);
	}
	memset(far,-1,sizeof far);
	for(int i=1;i<=m;i++) if(!dfn[i]) Tarjan(i);
	for(int i=1;i<=n;i++){
		if(scccnt[e[i].from] == scccnt[e[i].to]){
			val[scccnt[i]] = max(e[i].from,e[i].to);
		}else{
			adde2(scccnt[e[i].from],scccnt[e[i].to]);
			val[scccnt[e[i].from]] = e[i].from;
			val[scccnt[e[i].to]] = e[i].to;
			indeg[scccnt[e[i].to]]++;
			
		}
	}
	for(int i=1;i<=scc;i++) if(indeg[i]==0){
		dfs(i);
	}
	
	for(int i=1;i<=m;i++){
		printf("%d ",far[scccnt[i]]);
	}
	return 0;
}
