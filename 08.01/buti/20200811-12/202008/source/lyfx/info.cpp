#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],b[100001],l[5001][5001],you,zuo,maxx;
int main()
{
	freopen("info.in","r",stdin);
	freopen("info.out","w",stdout);
	cin>>n;
	memset(l,0x3f,sizeof(l));
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			zuo=i-j;
			if(zuo<=0)	zuo=zuo+n;
			l[i][zuo]=1;
		}
		for(int j=1;j<=b[i];j++)
		{
			you=i+j;
			if(you>n)	you=you-n;
			l[i][you]=1;
		}
	}
	for(int i=1;i<=n;i++)	l[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				l[j][k]=min(l[j][k],l[j][i]+l[i][k]);
	for(int i=1;i<=n;i++)
	{
		maxx=0;
		for(int j=1;j<=n;j++)
		{
			maxx=max(maxx,l[i][j]);
		}
		cout<<maxx<<" ";
		
	}
	
}
