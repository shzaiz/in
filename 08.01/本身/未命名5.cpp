#include<bits/stdc++.h>
#define INF 0x7f7f7f7f
#define MAXN 100005
using namespace std;

vector<int> g[MAXN];
int n,m,f[MAXN],mi[MAXN],c[MAXN];

void dfs(int x,int minx,int pre) {
    int flag=1; 
    minx=min(c[x],minx);
    if (mi[x]>minx) mi[x]=minx,flag=0;
    int maxx=max(f[pre],c[x]-minx);
    if (f[x]<maxx) f[x]=maxx,flag=0;
    if (flag) return;
    for (int i=0;i<g[x].size();i++) dfs(g[x][i],minx,x);
}

int main() {
    cin>>n>>m;
    for (int i=0;i<MAXN;i++) mi[i]=INF;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=m;i++) {
        int t1,t2,t3;
        scanf("%d%d%d",&t1,&t2,&t3);
        g[t1].push_back(t2);
        if (t3==2) g[t2].push_back(t1);
    }
    dfs(1,INF,0);
    cout<<f[n]<<endl;
    return 0;
}
