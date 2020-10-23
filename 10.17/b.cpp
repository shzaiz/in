#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
struct Edge{
    int to,nxt;
}e[N];
int head[N],cnt;
int out[N];
int dp[1000][1000];
void adde(int u,int v){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] =cnt;
}

void dfs(int u,int fa){
    dp[u][0] =1;
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        for(int j = 1;j<999;j++){
            dp[u][j] += dp[v][j-1];
        }
    }
}

int solve(){
    int n,a,b;cin>>n>>a>>b;
    for(int i = 1;i<n;i++){
        int x,y;cin>>x>>y;adde(x,y);adde(y,x);
    }
    dfs(1,0);
    printf("%d\n",dp[1][a]+dp[1][b]);

}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
    memset(e,0,sizeof(e));
    memset(head,0,sizeof(head));cnt = 0;memset(out,0,sizeof(out));
    memset(dp,0,sizeof(dp));
    solve();
}