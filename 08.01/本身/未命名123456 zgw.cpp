#include <bits/stdc++.h>
#include <iomanip>
#define WARMA 400010
using namespace std;
int n,m,X,Y,Z,id,s,t,u,v;
int to[WARMA],wi[WARMA],ne[WARMA],po[WARMA],vis[WARMA];
double dis[WARMA];
queue<int> q;
void add(int u,int v,int w){
	id++;
	to[id] = v;
	wi[id] = w;
	ne[id] = po[u];
	po[u] = id;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>X>>Y>>Z;
		add(X,Y,Z);
		add(Y,X,Z);
	}
	cin>>t>>s;
	for(int i=0;i<=n+1;i++){
		dis[i] = 99999999999.0;
		
	}
	
	vis[s] = 1;
	dis[s] = 100.0;
	q.push(s);
	
	while(!q.empty()){
		u=q.front();
		q.pop();
		vis[u] = 0;
		for(int i=po[u];i;i = ne[i]){
			v = to[i];
			if(dis[v]>(double)(dis[u])/(1-0.01*wi[i])){
				dis[v] = (double)(dis[u])/(1-0.01*wi[i]);
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	} 
	printf("%.8lf",dis[t]);
} 
