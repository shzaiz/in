#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<cmath>
#include<utility>
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while((ch>'9'||ch<'0')&&ch!='-')
		ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
    	x=x*10+ch-'0';
    	ch=getchar();
	}
	return x*f;
}
const int N=1010;
int cost[N],head[N],nxt[2*10*N];
int to[2*10*N],edge[2*10*N];
int dp[N][102];
bool visit[N][102];
int c,s,e,n,m,q,tot=-1;
void add(int x,int y,int z)
{
	to[++tot]=y;
	nxt[tot]=head[x];
	edge[tot]=z;
	head[x]=tot;
	return ;
}
struct iny
{
	int d,u,p;
	iny(int x,int y,int z):u(x),d(y),p(z){}
	friend bool operator < (iny a,iny b)
	{
		return a.p>b.p;
	}
};
priority_queue < iny > que;
bool judger(int u,int d)
{
	if(d+1<=c&&!visit[u][d+1]&&(dp[u][d+1]>dp[u][d]+cost[u]))
		return 1;
	return 0;
}
bool afford(int d,int v,int p,int pi)
{
  if(d>=p&&!visit[v][d-p]&&dp[v][d-p]>pi)
		return 1;
	return 0;
}
int BFS()
{
	while(!que.empty())
		que.pop();
	memset(visit,false,sizeof(visit));
	memset(dp,0x3f,sizeof(dp));
	dp[s][0]=0;
	que.push(iny(s,0,0));
	while(!que.empty())
	{
		iny pre=que.top();
		que.pop();
		int ui=pre.u;
		int di=pre.d;
		int pi=pre.p;
		visit[ui][di]=true;
		if(ui==e)
			return pi;
		if(judger(ui,di))
		{
			dp[ui][di+1]=dp[ui][di]+cost[ui];
			que.push(iny(ui,di+1,dp[ui][di+1]));
		}
		for(int i=head[ui];i!=-1;i=nxt[i])
		{
			int v=to[i],p=edge[i];
			if(afford(di,v,p,pi))
			{
				dp[v][di-p]=pi;
				que.push(iny(v,di-p,pi));
			}
		}
	}
	return -1;
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();m=read();
	for(int i=0;i<n;i++)
		cost[i]=read();
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		x=read();
		y=read();
		z=read();
		add(x,y,z);
		add(y,x,z);
	}
	q=read();
	while(q--)
	{
		c=read();
		s=read();
		e=read();
		int ans=BFS();
		if(ans==-1)
			printf("impossible\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}