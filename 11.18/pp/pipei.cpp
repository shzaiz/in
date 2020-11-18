#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define int long long
struct Edge{
    int to,nxt;
}e[N];
int cnt = 0, head[N];
void adde(int u,int v){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
int n,val[N],sum[N],vis[N];
void dfs(int u,int fa){
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].to;
        if(v==fa) continue;
        sum[u] += val[v];
        dfs(v,u);
    }
}
int s[N]={0,1,2,3,4},tp = 0;
int s1[N],s2[N],s3[N];

int calc(){
    if(tp<3) return 0;
    fo(i,tp) s1[i] = s1[i-1]+s[i];
    fo(i,tp) {
        s2[i] = s2[i-1]+s1[i-1]*s[i];
    }
    fo(i,tp) {
        s3[i] = s3[i-1]+s2[i-1]*s[i];
    }
    return s3[tp];
} 
int ans = 0;
void bfs2(int st){
    queue<int >Q;
    Q.push(st);
    vis[1] = 1;
    while (!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i = head[u];i ; i =e[i].nxt){
            int v = e[i].to;
            if(vis[v]) continue;
            Q.push(v);
            vis[v] = 1;
            if(sum[v]!=0) s[++tp] = sum[v];
        }
        ans += calc();
        fo(i,tp ) cout<<s[i]<<' ';
        cout<<"-->";
        cout<<calc()<<endl;
        tp = 0;
    }
}
signed main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/baoli.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    tp = 0;
    cin>>n;
    fo(i,n) cin>>val[i];
    fo(i,n-1){
        int x,y;cin>>x>>y;adde(x,y);adde(y,x);
    } 
    dfs(1,0);
    bfs2(1);
    cout<<ans<<endl;
    return 0;
}