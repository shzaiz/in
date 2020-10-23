#include<bits/stdc++.h>
using namespace std;
long long a[1001][1001],n,k;
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	a[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)
		{
			a[i][j]=(a[i-1][j]*(j+1)%2012+a[i-1][j-1]*(i-j)%2012)%2012;
		}
	cout<<a[n][k];
}
