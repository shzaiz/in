#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 500001
#define int long long
struct Edge{
    int to,nxt;
}e[N];
int cnt = 0, head[N], fat[N];
void adde(int u,int v){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
int n,val[N],sum[N],vis[N],dep[N];
void dfs(int u,int fa){
    dep[u] = dep[fa]+1;
    fat[u] = fa;
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].to;
        if(v==fa) continue;
        dfs(v,u);
        sum[u] += val[v];
    }
}
int s[N]={0},tp = 0;
int s1[N],s2[N],s3[N];

int calc(){
     memset(s1,0,sizeof(s1)) ; memset(s2,0,sizeof(s2)) ;memset(s3,0,sizeof(s3)) ;
    
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
    for(int u = 1;u<=n;u++){
        int s1=val[fat[fat[u]]];
        if(u>1) s1+=sum[fat[u]]-val[u];
        int s2 = 0;
        for(int i = head[u];i;i = e[i].nxt){
            int v = e[i].to;
            if(v==fat[u]) continue;
            s[++tp] = sum[v];
            ans+=s2*sum[v];
            s2+=s1*sum[v];
            s1+=sum[v];
        }
    }
    cout<<ans<<endl;
    return 0;
}