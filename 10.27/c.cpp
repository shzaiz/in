#include <bits/stdc++.h>
using namespace std;
#define tm fuckccf
#define clock nmsl
#define N 100010
int n,k1,k2;
struct Edge{
    int to,nxt;
}e[N];
int head[N],cnt = 0;
void adde(int u,int v){
    e[++cnt].to = v;
    e[cnt].nxt= head[u] ;
    head[u] =cnt;
}
int clock = 0;
int vis[N],tm[N];
void dfs(int u){
    vis[u] = 1; tm[u] = ++clock;
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].to;
        if(vis[v]) continue;
        dfs(v); 
    }
}
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("dizzy.in","r",stdin);
    freopen("dizzy.out","w",stdout);
    #endif
    cin>>n>>k1>>k2;
    for(int i = 1;i<=k1;i++){
        int a,b;cin>>a>>b;
        adde(a,b);
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    for(int i = 1;i<=k2;i++){
        int a,b;cin>>a>>b;
        if(tm[a]>tm[b] ) printf("%d %d\n",b,a);
        else printf("%d %d\n",a,b);
    }
    return 0;
}