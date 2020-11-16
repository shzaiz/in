#include<bits/stdc++.h>
#define fint register int
#define N 1000001
#define int long long
using namespace std;
int a[N],vis[N];
signed main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(fint i=1;i<=n;i++)
	cin>>a[i],vis[a[i]]++;
	for(fint i=500000;i>=1;i--)
	{
		int tot=0,sum=k;
		for(fint j=i;j<=500000;j+=i)
		{
			if(vis[j])
			tot+=vis[j];
			if(tot>=k)
			{
				cout<<k*i;
				goto lb;
			}
		}
	}
	cout<<0;
	lb:
	return 0;
} 
