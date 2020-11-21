#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000 // 点数n+2m
#define M 700000 // 边数4n+14m
#define inf 0x3f3f3f3f
using namespace std;
struct KSD
{
	int v,len,next;
}e[M];
int head[N],cnt;
inline void add(int u,int v,int len)
{
	e[++cnt].v=v;
	e[cnt].len=len;
	e[cnt].next=head[u];
	head[u]=cnt;
}
inline void Add(int u,int v,int len)
{add(u,v,len),add(v,u,len);}
int s,t,d[N];
queue<int>q;
bool bfs()
{
	while(!q.empty())q.pop();
	memset(d,0,sizeof d);

	int i,u,v;
	q.push(s),d[s]=1;
	while(!q.empty())
	{
		u=q.front(),q.pop();
		for(i=head[u];i;i=e[i].next)
		{
			if(!d[v=e[i].v]&&e[i].len)
			{
				d[v]=d[u]+1;
				if(v==t)return 1;
				q.push(v);
			}
		}
	}
	return 0;
}
int dinic(int x,int flow)
{
	if(x==t)return flow;
	int remain=flow,i,v,k;
	for(i=head[x];i&&remain;i=e[i].next)
	{
		if(d[v=e[i].v]==d[x]+1&&e[i].len)
		{
			k=dinic(v,min(remain,e[i].len));
			if(!k)d[v]=0;
			e[i].len-=k,e[i^1].len+=k;
			remain-=k;
		}
	}
	return flow-remain;
}
int n,m,maxflow;
bool build()
{
	int i,j,k;
	int a,b,c;
	int u,v;

	scanf("%d%d",&n,&m);

	if(!m)
	{
		long long ans=0;
		while(n--)
		{
			scanf("%d%d",&a,&b);
			ans+=max(a,b);
		}
		cout<<ans<<endl;
		return 1;
	}

	s=0,t=n+m*2+1,cnt=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		maxflow+=a+b;
		Add(s,i,a),Add(i,t,b);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d%d",&u,&v,&a,&b,&c);
		maxflow+=a+b;
		Add(s,n+i*2-1,b),Add(n+i*2-1,u,b),Add(n+i*2-1,v,b);
		Add(t,n+i*2,a),Add(n+i*2,u,a),Add(n+i*2,v,a);
		Add(u,v,c);
	}
	return 0;
}
int main()
{
	freopen("Eli_.in","r",stdin);
	freopen("Eli_.out","w",stdout);

	if(build())return 0;
	while(bfs())maxflow-=dinic(s,inf);
	printf("%d\n",maxflow);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
