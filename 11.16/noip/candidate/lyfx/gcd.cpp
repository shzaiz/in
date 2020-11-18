#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int t[5000001];
int a,ans,maxx;
inline int read()
{
	int x=0,f=1;
	char ch;
	ch=getchar( );
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
signed main( )
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
    n=read( );
    m=read( );
    for(int i=1;i<=n;i++)
	{
		a=read();
		t[a]++;
		maxx=max(maxx,a);
	}
	for(int i=maxx;i>=2;i--)
	{
		int ge=0;
		for(int j=i;j<=maxx;j=j+i)
		{
			ge+=t[j];
		}
		if(ge>=m)
		{
			cout<<i*m;
			return 0;
		}
	}
	cout<<m;
	return 0;
	
}
