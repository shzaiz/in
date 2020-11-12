#include<cmath>
#include<cstdio>
#include<algorithm>
#define For(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define N 100010
using namespace std;
int n,m,x,u,v,l,r,sz,a[N],en[N],pre[N],g[N],q[N],fa[N],d[N];
long long b[N];
void BFS()
{
	q[l=r=1]=1;
	for(;l<=r;l++)
	{
		x=q[l];
		for(int i=en[x];i;i=pre[i])
		{
			v=g[i];
			fa[v]=x;
			d[v]=d[x]+1;
			q[++r]=v;
		}
	}
}
bool Query()
{
	sz=0;
	while (u!=v && sz<50)
		if (d[u]>d[v]) b[++sz]=a[u],u=fa[u];
				  else b[++sz]=a[v],v=fa[v];
	b[++sz]=a[u];
	if (sz>=50) return 1;
	sort(b+1,b+sz+1);
	For(i,sz-2)
	    if (b[i]+b[i+1]>b[i+2]) return 1;
	return 0;
}
int main()
{
	freopen("sdtg.in","r",stdin);
	freopen("sdtg.out","w",stdout);
	scanf("%d%d",&n,&m);
	For(i,n) scanf("%d",&a[i]);
	For(i,n-1)
	{
		scanf("%d%d",&u,&v);
		pre[i]=en[u];en[u]=i;g[i]=v;
	}
	BFS();
	For(qq,m)
	{
		scanf("%d%d%d",&l,&u,&v);
		if (l==1) a[u]=v;
		else if (Query()) puts("Y"); else puts("N");
	}
	return 0;
}
