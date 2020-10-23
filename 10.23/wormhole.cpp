#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define M(x) memset(x, 0, sizeof(x))
#define int long long
int dis[N],vis[N],cntof[N];
int n,m,w;
struct Edge{
    int to,nxt,w;
}e[N];
int head[N],cnt = 0;
void adde(int u,int v,int w){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    e[cnt].w = w;
    head[u] = cnt;
}
queue<int > Q;
bool spfa(int u){
    bool has = 0;
    memset(dis,1000000009,sizeof dis);
    dis[u] = 0;
    vis[u] = 1;
    Q.push(u);
    while(!Q.empty()){
        int u = Q.front(); Q.pop(); vis[u] =0;
        for(int i = head[u];i ;i = e[i].nxt){
            int v = e[i].to;
            if(dis[u]+e[i].w<dis[v]){
            	// printf("Push%d\n",v); 
                dis[v] = dis[u]+e[i].w;
                if(!vis[v]){
                    Q.push(v);
                    vis[v] =1;
                    cntof[v]++;
                }
                if(cntof[v]>n) return 1;
            }
        }
    }
    return has;
}

void solve(){
    cin>>n>>m>>w;
    for(int i = 1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;
        adde(x,y,z);adde(y,x,z);
    }
    for(int i =1;i<=w;i++){
        int x,y,z;cin>>x>>y>>z;
        adde(x,y,-z);
        
    }
    if(spfa(1)) printf("YES\n");else printf("NO\n");
    
}

signed main(){
   #ifndef ONLINE_JUDGE
   freopen("D:/Testcases/in.ac","r",stdin);
   freopen("D:/Testcases/out.ac","w",stdout);
   #else
   freopen("wormhole.in","r",stdin);
   freopen("wormhole.out","w",stdout);
   #endif
    int T;cin>>T;
    while(T--){
        M(e);M(head);cnt = 0;M(cntof);M(dis);M(head);M(vis);
        solve();
    }
    
}
