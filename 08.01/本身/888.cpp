#include <bits/stdc++.h>
#include <iostream>
#define WARMA 10010
using namespace std; 
int head[WARMA];
int dis[WARMA],vis[WARMA];
int u,v;
int cnt=0;
queue<int > Q;
struct Edge{
	int to,nxt,val;
}e[WARMA];
void adde(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
	e[cnt].val = w;
}

void SPFA(int s){
	dis[s] = 0;
	vis[s] = 1;
	Q.push(s);
	while(!Q.empty()){
	//	cout<<"132"<<endl;
		u = Q.front();Q.pop();vis[u] = 0;
		for(int i = head[u];i;i=e[i].nxt){
			v = e[i].to;
			if(dis[v]>dis[u]+e[i].val){
				dis[v] = dis[u]+e[i].val;
				if(vis[v] == 0){
					Q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}

int main(){
	memset(dis,sizeof dis,0x7f);
	int g[WARMA]={};
	int X,Y,Z;
	cin>>X>>Y>>Z;
	for(int i = 1;i<=X;i++){
		cin>>g[i];
	} 
	for(int i=0;i<Z;i++){
		int w,a,r;
		cin>>w>>a>>r;
		adde(w,a,r);
		adde(a,w,r);
		
	}
	long long minn = 168148;
	
	for(int i=1;i<=Y;i++){
	//	cout<<minn<<endl;
		SPFA(i);
		long long ans = 0;
		for(int j = 1;j<X;j++){
			ans += dis[g[j]];
			
		}
		cout<<ans<<endl;
		minn = min(ans,minn);
	}
	
	cout<<minn;
	
}
