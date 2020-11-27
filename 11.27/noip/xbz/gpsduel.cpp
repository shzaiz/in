#include<bits/stdc++.h>
#define fint register int
#define H 5001
#define N 500001
#define AK cout<<"ZGW and LYFX AK IOI easily"
using namespace std;
struct point
{
	int x;
	int y;
	int z;
}
a[N],b[N];
struct node
{
	int to;
	int nxt;
	int val;
}
e[N];
int cnt;
int head[N];
int dis[N],pre[N][3];
bool vis[N];
inline void adds(int u,int v,int w);
inline void SPFA(int x,int num);
inline void spfa(int x);
inline int read();
int main()
{
	freopen("gpsduel.in","r",stdin);
	freopen("gpsduel.out","w",stdout);
	int n,m;
	n=read(),m=read();
	int x,y,za,zb;
	for(fint i=1;i<=m;i++)
	{
		cin>>x>>y>>za>>zb;
		a[i]=(point){x,y,za};
		b[i]=(point){x,y,zb};
	}
	for(fint i=1;i<=m;i++)
	adds(a[i].y,a[i].x,a[i].z);
	SPFA(n,1);
	memset(head,0,sizeof(head));
	cnt=0;
	for(fint i=1;i<=m;i++)
	adds(b[i].y,b[i].x,b[i].z);
	SPFA(n,2);
	memset(head,0,sizeof(head));
	cnt=0;
	for(fint i=1;i<=m;i++)
	adds(a[i].x,a[i].y,2);
	spfa(1);
	cout<<dis[n];
	return 0;
}

inline void adds(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	e[cnt].val=w;
	head[u]=cnt;
	return ;
}

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

inline void SPFA(int x,int num)
{
	queue <int>q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0,vis[x]=1;
	q.push(x);
	while(!q.empty())
	{
		int hea=q.front();
		q.pop();
		vis[hea]=0;
		for(fint i=head[hea];i;i=e[i].nxt)
		if(dis[e[i].to]>dis[hea]+e[i].val)
		{
			dis[e[i].to]=dis[hea]+e[i].val;
			pre[e[i].to][num]=i;
			if(!vis[e[i].to])
			vis[e[i].to]=1,q.push(e[i].to);
		}
	}
	return ;
}

inline void spfa(int x)
{
	queue <int>q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0,vis[x]=1;
	q.push(x);
	while(!q.empty())
	{
		int hea=q.front();
		q.pop();
		vis[hea]=0;
		for(fint i=head[hea];i;i=e[i].nxt)
		{
			int ans=0;
			if(i==pre[hea][1])
			ans--;
			if(i==pre[hea][2])
			ans--;
			if(dis[e[i].to]>dis[hea]+e[i].val+ans)
			{
				dis[e[i].to]=dis[hea]+e[i].val+ans;
				if(!vis[e[i].to])
				vis[e[i].to]=1,q.push(e[i].to);
			}
		}
	}
	return ;
}

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
