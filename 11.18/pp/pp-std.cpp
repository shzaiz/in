#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<cstdlib>
#include<bitset>
#include<stack>
#include<ctime>
#include<fstream>
#define dd double
#define ll long long
#define mp make_pair
#define pb push_back
#define N 1000010
#define M 1010
using namespace std;
int n,u,v,a[N];
int s,to[N*2],ne[N*2],pre[N];
int fa[N],f[N];
ll ans;
void add(int u,int v)
{
	to[++s]=v;
	ne[s]=pre[u];
	pre[u]=s;
}
void dfs(int k)
{
	for(int i=pre[k];i;i=ne[i])
	if(to[i]!=fa[k])
	{
		int x=to[i];
		fa[x]=k;
		dfs(x);
		f[k]+=a[x];
	}
}
int main()
{
	//freopen("./match/match1.in","r",stdin);
	//freopen("./match/match1.out","w",stdout);
	#ifdef XBZAKIOI
    freopen("D:/Testcases/baoli.ac","r",stdin);
    freopen("D:/Testcases/duipai.ac","w",stdout);
    #endif
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		ll s1=a[fa[fa[i]]];
		if(i>1) s1+=f[fa[i]]-a[i];
		ll s2=0; 
		for(int j=pre[i];j;j=ne[j])
		if(to[j]!=fa[i])
		{
			int x=to[j];
			ans+=s2*f[x];
			cout<<s2*f[x]<<endl;
			s2+=s1*f[x];
			s1+=f[x];
		}
	}
	cout<<ans<<endl;
}