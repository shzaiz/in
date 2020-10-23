#include"bits/stdc++.h"
using namespace std;
struct EDGE
       {
           int next;
           int to;
           int cs;
       }e[99999];
int head[99999];
int num=1;
int d[100000];
int q[999999];
int vis[999999];
int mvp[999999];
int f;
int n,m,w;
int s,e1,t;
void add(int x,int y,int cs)
{
    e[num].next=head[x];
    e[num].to=y;
    e[num].cs=cs;
    head[x]=num;
    num++;
}
int spfa(int st)
{
    d[st]=0;
    int h=1,en=2;
    q[h]=st;vis[st]=1;
    mvp[st]++;
    while(h<=en)
    {
        int v=q[h];vis[v]=0;
        for(int i=head[v];i!=-1;i=e[i].next)
        {
            if(d[e[i].to]>d[v]+e[i].cs)
            {
                d[e[i].to]=d[v]+e[i].cs;
                if(vis[e[i].to]==0)
                {
                    q[en]=e[i].to;
                    en++;
                    mvp[e[i].to]++;
                    vis[e[i].to]=1;
                }
                if(mvp[e[i].to]>n)return 1;
            }
        }h++;
    }
    return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    #endif
    cin>>f;
    for(int i=1;i<=f;i++)
    {
        memset(head,-1,sizeof(head));
        memset(e,0,sizeof(e));
        memset(mvp,0,sizeof(mvp));
        memset(q,0,sizeof(q));
        memset(vis,0,sizeof(vis));
        num=1;
        for(int j=1;j<=99999;j++)d[j]=1e9;
        cin>>n>>m>>w;
        for(int j=1;j<=m;j++)
        {
            cin>>s>>e1>>t;
            add(s,e1,t);
            add(e1,s,t);
        }
        for(int j=1;j<=w;j++)
        {
            cin>>s>>e1>>t;
            t=t*-1;
            add(s,e1,t);
        }
        if(spfa(1)==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
