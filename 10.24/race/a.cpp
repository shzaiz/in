#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,m,k;
int ans = 0;
int fat[1005][1005];
struct Edge{
    int to,nxt;
}e[N];
int dep[N],mk[N];
int head[N],cnt = 0;
void adde(int u,int v){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
void mark(int u,int fa,int cur,int dep){
    if(cur>dep) return ;
    mk[u] = 1;
    printf("%d ",u);
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].to;
        if(v==fa) continue;
        mark(v,u,cur+1,dep);
    }
}
void dfs(int u,int fa){
    printf("--> %d %d\n",u,mk[u]);
    dep[u] = dep[fa]+1;
    for(int i = 1;i<1000;i++){
        fat[u][i+1] = fat[fat[u][i]][i];
    }
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
    if(mk[u]==0 && fat[u][k]!=0){printf("Coloring %d\n",fat[u][k]);mark(fat[u][k],fat[u][k],0,k); ans++;}
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
    
    cin>>n>>m>>k;
    for(int i = 1;i<=n-1;i++){
        int x,y;cin>>x>>y;
        // printf("%d <--> %d\n",x,y);
        adde(x,y);adde(y,x);
    }
    mark(m,0,0,k);
    dfs(m,0);

    printf("%d",ans);
}