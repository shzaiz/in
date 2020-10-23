#include<bits/stdc++.h>
#define fint register int
#define h 5001
#define p 4375983
using namespace std;
int ans=0;
int a[p],b[p];
bool vis[p];
int f[h][h];
int n;
int maxxs[p];
int main()
{
	freopen("info.in","r",stdin);
	freopen("info.out","w",stdout); 
	cin>>n;
	for(fint i=1;i<=n;i++)
	cin>>a[i];
	for(fint i=1;i<=n;i++)
	cin>>b[i];
	memset(f,0x3f,sizeof(f));
	for(fint i=1;i<=n;i++)
	{
		int now;
	for(fint j=i+1;j<=i+b[i];j++)
	{
		if(j!=n)
		now=j%n;
		else
		now=n;
		f[i][now]=1;
	}
	for(fint j=i-1;j>=i-a[i];j--)
	{
		if(j<=0)
		now=n-j;
		else
		now=j;
		f[i][now]=1;
	}
	}
	for(fint i=1;i<=n;i++)
	f[i][i]=0;
	for(fint k=1;k<=n;k++)
	for(fint i=1;i<=n;i++)
	for(fint j=1;j<=n;j++)
	f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	for(fint i=1;i<=n;i++)
	for(fint j=1;j<=n;j++)
	maxxs[i]=max(f[i][j],maxxs[i]);
	for(fint i=1;i<=n;i++)
	cout<<maxxs[i]<<" ";
	return 0;
}

/*
5
1 3 2 4 1
1 2 1 1 3
*/
