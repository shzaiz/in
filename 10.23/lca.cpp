#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct Edge{
    int to,nxt;
}e[N];
int fa[N][20],dep[N];
int head[N],cnt = 0;
void adde(int u,int v){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void dfs(int u,int fat){
    fa[u][0] = fat; dep[u] = dep[fat]+1;
    for(int i = head[u];i ; i = e[i].nxt){
        int v = e[i].to;
        if(v==fat) continue;
        dfs(v,u);
       
    }
    for(int i = 20;i>=0;i--){
        fa[u][i] = fa[fa[u][i]][i-1];    
    }
}
int main(){

}