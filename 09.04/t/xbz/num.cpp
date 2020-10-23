#include<bits/stdc++.h>
#define fint register int
#define h 5001
#define p 2001
using namespace std;
int a[p];
int f[p][p];
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n<=10)
	{
		int ans=0;
		for(fint i=1;i<=n;i++)
		a[i]=i;
		int tot=0;
		for(fint i=1;i<n;i++)
		if(a[i]<a[i+1])
		tot++;
		if(tot==k)
		ans++;
		while(next_permutation(a+1,a+n+1))
		{
			tot=0;
			for(fint i=1;i<n;i++)
			if(a[i]<a[i+1])
			tot++;
			if(tot==k)
			ans++;
		}
		cout<<ans%2012;
		return 0;
	}
	else
	{
		for(fint i=1;i<=n;i++)
		f[i][0]=1,f[i][i-1]=1;
		for(fint i=2;i<=n;i++)
		for(fint j=1;j<i;j++)
		f[i][j]=max(f[i-1][j-1]*(i-j)+f[i-1][j]*(j+1),f[i][j]),f[i][j]%=2012;
		cout<<f[n][k]%2012;
		return 0;
	}
	return 0;
} 
