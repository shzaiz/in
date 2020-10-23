#include <bits/stdc++.h>
using namespace std;
#define N 1000010
struct Edge{
    int to,nxt;
}e[N];
int dis[N];
priority_queue<pair<int ,int> > Q;
void dij(int s){
    Q.push(make_pair(s,dis[s]));
    while(!Q.empty()){
        pair<int ,int>top = Q.top();
        int u = top.first;
         vis[v] = true;
        for(int i = head[u];i;i = e[i].nxt){
            int v = e[i].to;
            if(vis[v]) continue;
            if(top.second+e[i].w>dis[v]){
               
                dis[v] = top.second+e[i].w;
            }
        }
    }
}