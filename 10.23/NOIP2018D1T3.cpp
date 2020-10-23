#include<bits/stdc++.h>
using namespace std;
#define N 100010
int m,n;
struct Edge{
    int to,nxt,w;
}e[N];
int head[N],cnt = 0,ans = -1;
void adde(int u,int v,int w){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    e[cnt].w = w;
    head[u] = cnt;
}
int dp1[N],dp2[N];
void dfs(int u,int fa){
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        int fans = e[i].w+dp1[v];
        if(fans>dp1[u]) {
            dp2[u] = dp1[u];
            dp1[u] = fans;
        }else if(fans>dp2[u]) {
            dp2[u] = fans;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    #endif
    cin>>m>>n;
    for(int i = 1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;
        adde(x,y,z);adde(y,x,z);
    }
    dfs(1,0);
    cout<<dp1[1]+dp2[1];
}