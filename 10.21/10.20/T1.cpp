#include <bits/stdc++.h>
using namespace std;
#define N 100010
int val[N];
int dp[N][2];
int fat[N];
int ak[N];
int n,m;
struct Edge{
    int to,nxt;
}e[N];
int head[N], cnt = 0;
void adde(int u,int v){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
void dfs(int u,int fa){
    fat[u] = fa;
    for(int i = head[u]; i;i = e[i].nxt){
        int v = e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0],dp[v][1]);
    }
    dp[u][1]+= val[u];
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    #endif
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>val[i];
    }
    int x,y;
    for(int i = 1;i<n;i++){
        cin>>x>>y;
        adde(x,y);adde(y,x);
    }
    dfs(1,0);
    cout<<min(dp[1][0],dp[1][1]);
}