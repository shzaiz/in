#include <bits/stdc++.h>
#define N 100100
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define mp make_pair
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define fi first
#define se second
#define MOD 1000000009
using namespace std;
struct Edge{
	int to,nxt,w;
}e[N];
int head[N],cnt  =0;
int n,love,hate;
void adde(int u,int v,int w) {
	e[++cnt].nxt = head[u];
	e[cnt].to = v;
	e[cnt].w = w;
	head[u] = cnt;

}
queue<int > Q;int dis[N],vis[N],inq[N];
int spfa(int s,int t){
	fo(i,N-1) dis[i] = 1e9;
	Q.push(s); dis[s] = 0; vis[s] = 1;
	while(!Q.empty()){
		int u = Q.front(); Q.pop(); vis[u] = 0;
		for(int i = head[u];i;i = e[i].nxt){
			int v = e[i].to;
			if(dis[u]+e[i].w<dis[v]){
				dis[v] = dis[u]+e[i].w;
				inq[v]++;
				if(!vis[v]) Q.push(v);
				if(inq[v] == n) return -1;
			}
		}
	} 
	if(dis[t] == 1e9) return -2;
	else return dis[t];
}
int main(){
	freopen("layout.in","r",stdin);
	freopen("layout.out","w",stdout);
	int n,love,hate;
	cin>>n>>love>>hate;
	fo(i, love){
		int x,y,d;cin>>x>>y>>d;
		adde(x,y,d);
	}
	fo(i,hate){
		int x,y,d; cin>>x>>y>>d;
		adde(y,x,-d);
	}
	cout<<spfa(1,n);
	return 0;
}




