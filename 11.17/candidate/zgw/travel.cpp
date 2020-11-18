#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define mem(x) memset(x,0,sizeof x)
#define is cin 
#define os cout 
const ll INF = 1e18 + 5;
ll dis[55][200005],T;
bool vis[55][200005];
int n,m,u,v;
int cnt,head[55];
ll mod,t,w;
struct Edge{
    int v,nxt;
    ll w;
}e[205];
void adde(int u,int v,ll w){
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
void spfa(){
    fo_(i,0,n-1) fo_(j,0,n-1) dis[i][j] = INF;
    mem(vis);
    dis[0][0] = 0;
    pair<int , int> u;
    u.fi = u.se = 0;
    queue<pair<int,int> > q;
    q.push(u);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        int x = u.fi,y = u.se;
        vis[x][y] = false;
        for(int i = head[x]; i; i = e[i].nxt) {
            int v = e[i].v;
            ll d = e[i].w + dis[x][y];
            int mo = d % mod;
            if(dis[v][mo] > d) {
                dis[v][mo] = d;
                if(!vis[v][mo]) {
                    vis[v][mo] = true;
                    q.push(mp(v,mo));
                }
            }
        }
    }
}
void solve(){
    cin>>n>>m>>t;
        while(m--) {
            is>>u>>v>>w;
            adde(u,v,w);
            adde(v,u,w);
            if(mod > w && (u == 0 || v == 0)) mod = w;
        }
        if(mod == 1e8) {
            os<<"Impossible\n";
            return;
        }
        mod *= 2;
        spfa();
        if(dis[n - 1][t % mod] <= t) os<<"Possible\n";
        else os<<"Impossible\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    #endif
    
    cin>>T;
    while(T--) {
        cnt = 0;mem(head);
        mod = 1e8;
        solve();
    }
    return 0;
}