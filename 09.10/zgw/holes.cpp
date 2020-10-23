#include <bits/stdc++.h>
#define MAXN 5005<<2
using namespace std;
struct Edge{
	int to,nxt,w;
}e[MAXN];
int cnt = 0,head[MAXN];
int dis[MAXN],vis[MAXN];
void adde(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	e[cnt].w = w;
	head[u] = cnt;
}
queue <int > Q;
void SPFA(int s){
	memset(vis,0,sizeof vis);
	Q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while(!Q.empty()){
		int u = Q.front();Q.pop();vis[u] = 0;
		for(int i=head[u];i;i=e[i].nxt){
			
			int v = e[i].to;
			if(!vis[v] && dis[u]+e[i].w<dis[v]){
				dis[v] = dis[u]+e[i].w;
				vis[v] = 1;
				Q.push(v);
			}
		}
	}
}
int b[MAXN>>1],w[MAXN>>1],s[MAXN>>1];
int N,M;
int main(){
	freopen("holes.in","r",stdin);
	freopen("holes.out","w",stdout);
	for(int i=0;i<MAXN;i++) dis[i] = 99999999;
	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>b[i]; 
	for(int i=1;i<=N;i++) cin>>w[i]; 
	for(int i=1;i<=N;i++) cin>>s[i];
	cout<<w[1]<<w[2]<<endl;
	for(int cn = 1;cn<=M;cn++){
		int x,y,z;
		cin>>x>>y>>z;
		if(b[x]==0 && b[y]==0){
			adde(x +5000,y,z);
			adde(x,y +5000,z);
		}
		else if(b[x]==1 && b[y]==1){
			adde(x +5000,y ,z);
			adde(x,y+5000,z);
		}
		else if(b[x]==0 && b[y]==1){
			int d = abs(w[x]-w[y]);
			adde(x+5000,y+5000 ,z+d);
			adde(x ,y,max(z+d,0));
		}
		else if(b[x]==1 && b[y]==0){
			int d = abs(w[x]-w[y]);
			adde(x+5000,y+5000 ,z+d);
			adde(x ,y,max(z-d,0));

		}
	} 
	for(int i=1;i<=N;i++){
		adde(i,i+5000,0);
        adde(i+5000,i,s[i]);
	}
	SPFA(1);
	cout<<min(dis[N],dis[N +5000]);
	return 0;
}

