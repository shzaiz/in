#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
const int N=205,M=5e3+5;
int n,m,tot=1,lnk[N],ter[M],nxt[M],val[M],dep[N],cnr[N];

int id(int x,int y) {
    return (x-1)*m+y;
}
void add(int u,int v,int w) {
    ter[++tot]=v,nxt[tot]=lnk[u],lnk[u]=tot,val[tot]=w;
}
void addedge(int u,int v,int w) {
    add(u,v,w),add(v,u,0);
}
int bfs(int s,int t) {
    memset(dep,0,sizeof(dep));
    memcpy(cnr,lnk,sizeof(lnk));
    std::queue<int> q;
    q.push(s),dep[s]=1;
    while(!q.empty()) {
        int u=q.front(); q.pop();
        for(int i=lnk[u];i;i=nxt[i]) {
            int v=ter[i];
            if(val[i]&&!dep[v]) q.push(v),dep[v]=dep[u]+1;
        }
    }
    return dep[t];
}
int dfs(int u,int t,int flow) {
    if(u==t) return flow;
    int ans=0;
    for(int i=cnr[u];i&&ans<flow;i=nxt[i]) {
        cnr[u]=i;
        int v=ter[i];
        if(val[i]&&dep[v]==dep[u]+1) {
            int x=dfs(v,t,std::min(val[i],flow-ans));
            if(x) val[i]-=x,val[i^1]+=x,ans+=x;
        }
    }
    if(ans<flow) dep[u]=-1;
    return ans;
}
int dinic(int s,int t) {
    int ans=0;
    while(bfs(s,t)) {
        int x;
        while((x=dfs(s,t,1<<30))) ans+=x;
    }
    return ans;
}
int main() {
    int s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=n;++i) addedge(i,i+n,1);
    while(m--) {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u+n,v,1<<30);
        addedge(v+n,u,1<<30);
    }
    printf("%d\n",dinic(s+n,t));
    return 0;
}