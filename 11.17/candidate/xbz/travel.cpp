#include<bits/stdc++.h>
#define fint register int
#define H 5001
#define N 457984
#define int long long
using namespace std;
struct point
{
	int num;
	int tim;
}
;
struct node
{
	int to;
	int nxt;
	int val;
}
e[N];
int cnt;
int head[N];
int n,m,t,ss,tt,ts,cir;
int dis[52][N];
inline int SPFA();
inline void adds(int u,int v,int w);
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(head,0,sizeof(head));
		cnt=0;
		cin>>n>>m>>t;
		ss=0,tt=0;
		int x,y,z;
		for(fint i=1;i<=m;i++)
		cin>>x>>y>>z,adds(x+1,y+1,z),adds(y+1,x+1,z);
		ts=t,t%=cir;
		if(!ss||!tt||!SPFA())
		puts("Impossible");
		else
		puts("Possible");
	}
	return 0;
}

inline void adds(int u,int v,int w)
{
	if(u==v)
	return ;
	if(u==1||v==1)
	ss=1;
	if(u==n||v==n)
	tt=1;
	if(u==1&&!cir)
	cir=(w<<1LL);
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	e[cnt].val=w;
	head[u]=cnt;
	return ;
}

inline int SPFA()
{
	queue <point>q;
	memset(dis,0x3f3f3f,sizeof(dis));
	dis[1][0]=0;
	q.push((point){1,0});
	while(!q.empty())
	{
		point hea=q.front();
		q.pop();
		for(fint i=head[hea.num];i;i=e[i].nxt)	
		if(dis[e[i].to][(e[i].val+hea.tim)%cir]>dis[hea.num][hea.tim]+e[i].val)
		dis[e[i].to][(e[i].val+hea.tim)%cir]=dis[hea.num][hea.tim]+e[i].val,q.push((point){e[i].to,(e[i].val+hea.tim)%cir});	
	} 
	if(dis[n][t]<=ts)
	return 1;
	return 0;
}
