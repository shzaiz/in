#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int frm,nxt;
	float rate;
}e[10010];
int head[10010] = {};
int rate[10010] = {};
int vis[10010] = {};
float dis[10010] = {};
int cnt = 0;

int EDGES = 3;
int NODES = 3;

void adde(int u,int v,int w){
	e[++cnt].frm = u;
	e[cnt].nxt = head[u];
	head[u] = cnt;
	e[cnt].rate = (float)1.00-(float)w/100;
}

void dijk(int s,int e){
	vis[s] = 1;
	rate[s] = 1;
	int minn = 999999;
	int nod = s;
	while(!vis[s]){
		for(int i=nod;;i=e[nod].nxt){
			if(!vis[e[i].nxt] && (dis[e[i].nxt]>dis[i]*e[i].rate)){
				dis[e[i].nxt] = dis[e[i]]*e[i].rate;
			}
		}
		
		for(int i=0;i<NODE;i++){
			if(!vis[i]&&minn>dis[i]){
				minn = dis[i];
				curr = i;
			}
		}
	}
	
}

int main(){
	memset(rate,sizeof(rate),0x7f);
	adde(1,2,1);
	adde(2,3,2);
	adde(1,3,3);
	dijk(1,3);
	cout<<dis[3];
} 
