/*
 5 7
 3 4 7 1
 1 3 2 20
 1 4 17 18
 4 5 25 3
 1 2 10 1
 3 5 4 14
 2 4 6 5
 */
#include<bits/stdc++.h>
using namespace std;
int dis[1000001];
int head[1000001];
struct cxk
{
    int nxt,to,zhi;
}e[1000001];
int cnt;
void add(int x,int y,int z)
{
    cnt++;
    e[cnt].to=y;
    e[cnt].zhi=z;
    e[cnt].nxt=head[x];
    head[x]=cnt;
}
int ru[1000001];
struct node{
    int zhi,xv,bian;
};
bool operator<(const node &a,const node &b)
{
    return a.zhi>b.zhi;
}
priority_queue<node>q;
int x[1000001],y[1000001],c[1000001],l[1000001];
int read( )
{
    int x=0;
    int f=1;
    char ch=getchar( );
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar( );
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar( );
    }
    return x*f;
}
int n,m;
signed  main( )
{
	freopen("gpsduel.in","r",stdin);
	freopen("gpsduel.out","w",stdout);
    n=read( );
    m=read( );
    for(int i=1;i<=m;i++)
    {
        ru[i]=2;
        int u;
        x[i]=read( );
        y[i]=read( );
        u=read( );
        c[i]=read( );
        add(x[i],y[i],u);
    }
    memset(dis,0x7f,sizeof(dis));
    memset(l,0,sizeof(l));
    node r;
    r.xv=1;
    r.zhi=0;
    r.bian=0;
    while(!q.empty())q.pop( );
    q.push(r);
    dis[1]=0;
    
    while(!q.empty( ))
    {
        
        node o=q.top( );
        q.pop( );
        int qi=o.xv;
        if(l[qi]==1)continue;
        l[qi]=1;
        ru[o.bian]--;
        for(int i=head[qi];i;i=e[i].nxt)
        {
            int to=e[i].to;
            if(l[to]==1)continue;
            if(dis[to]>dis[qi]+e[i].zhi)
            {
                dis[to]=dis[qi]+e[i].zhi;
                node u;
                u.zhi=dis[to];
                u.bian=i;
                u.xv=to;
                q.push(u);
            }
        }
    }
   // cout<<dis[1]<<endl;
    
    
    memset(head,0,sizeof(head));
    cnt=0;
    for(int i=1;i<=m;i++)
        add(x[i],y[i],c[i]);
    memset(dis,0x7f,sizeof(dis));
    memset(l,0,sizeof(l));
    r.xv=1;
    r.zhi=0;
    r.bian=0;
    while(!q.empty())q.pop( );
    q.push(r);
    dis[1]=0;
    
    while(!q.empty( ))
    {
        node o=q.top( );
        q.pop( );
        int qi=o.xv;
        if(l[qi]==1)continue;
        l[qi]=1;
        ru[o.bian]--;
        for(int i=head[qi];i;i=e[i].nxt)
        {
            int to=e[i].to;
            int zhi=e[i].zhi;
            if(l[to]==1)continue;
            if(dis[to]>dis[qi]+e[i].zhi)
            {
                dis[to]=dis[qi]+e[i].zhi;
                node u;
                u.zhi=dis[to];
                u.bian=i;
                u.xv=to;
                q.push(u);
            }
        }
    }
    
    memset(head,0,sizeof(head));
    cnt=0;
    for(int i=1;i<=m;i++)
        add(x[i],y[i],ru[i]);
    memset(dis,0x7f,sizeof(dis));
    memset(l,0,sizeof(l));
    r.xv=1;
    r.zhi=0;
    r.bian=0;
    while(!q.empty())q.pop( );
    q.push(r);
    dis[1]=0;
    
    while(!q.empty( ))
    {
        node o=q.top( );
        q.pop( );
        int qi=o.xv;
        if(l[qi]==1)continue;
        l[qi]=1;
        for(int i=head[qi];i;i=e[i].nxt)
        {
            int to=e[i].to;
            int zhi=e[i].zhi;
            if(l[to]==1)continue;
            if(dis[to]>dis[qi]+e[i].zhi)
            {
                dis[to]=dis[qi]+e[i].zhi;
                node u;
                u.zhi=dis[to];
                u.bian=i;
                u.xv=to;
                q.push(u);
            }
        }
    }
    cout<<dis[n];
}
