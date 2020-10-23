#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct Edge{
    int to,nxt;
}e[N];
int n;
int ind[N],vis[N];
int head[N],cnt = 0;
void adde(int u,int v){
    ind[v] ++;
    e[++cnt].nxt = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}
queue<int > Q;
bool topo(){
    for(int i = 0;i<=n;i++){
        if(ind[i]==0) {Q.push(i);vis[i] = 1; break;}
    }
    while(!Q.empty()){
        int u = Q.front(); Q.pop(); vis[u] =1;
        for(int i = head[u];i;i = e[i].nxt){
            int v = e[i].to;
            if(vis[v]) return 0; //has a cycle
            ind[v]--;
            if(ind[v]==0) {Q.push(v);vis[v] = 1;}
        }
    }
}
