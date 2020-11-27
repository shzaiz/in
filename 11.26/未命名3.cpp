#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int s,t,flow;
int a[1005];
int pre[1005];
int head[1005];
int n,p,q,cnt=1;

struct Edge{
    int to,nxt,flow;
}edge[1000005];

void add(int x,int y,int z){
    edge[++cnt].to=y;
    edge[cnt].nxt=head[x];
    edge[cnt].flow=z;
    head[x]=cnt;
}

bool bfs(){
    queue<int> q;
    memset(a,0,sizeof a);
    a[s]=0x3f3f3f3f;
    q.push(s);
    while(q.size()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=edge[i].nxt){
            int to=edge[i].to;
            if(!edge[i].flow) continue;
            if(a[to]) continue;
            a[to]=min(a[u],edge[i].flow);
            pre[to]=i;
            q.push(to);
        }
    }
    if(!a[t]) return 0;
    flow+=a[t];
    return 1;
}

void update(){
    int m=t;
    for(;pre[m];m=edge[pre[m]^1].to)
        edge[pre[m]].flow-=a[t],edge[pre[m]^1].flow+=a[t];
}

signed main(){
    freopen("1402.in","r",stdin);
	scanf("%d%d%d",&n,&p,&q);
    s=2*n+q+p+1,t=s+1;
    for(int i=1;i<=n;i++){
        for(int x,j=1;j<=p;j++){
            scanf("%d",&x);
            if(x^1) continue;
            add(j,p+i,1);
            add(p+i,j,0);
        }
    }
    for(int i=1;i<=n;i++){
        for(int x,j=1;j<=q;j++){
            scanf("%d",&x);
            if(x^1) continue;
            add(p+n+q+i,p+n+j,1);
            add(p+n+j,p+n+q+i,0);
        }
    }
    for(int i=1;i<=n;i++) add(p+i,p+n+q+i,1),add(p+n+q+i,p+i,0);
    for(int i=1;i<=p;i++) add(s,i,1),add(i,s,0);
    for(int i=p+1+n;i<=p+n+q;i++) add(i,t,1),add(t,i,0);
    while(bfs()) update();
    printf("%d",flow);
    return 0;
}

