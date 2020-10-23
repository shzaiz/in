#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int n,la[200001],lb[200001],lc[200001],ans[200001],lbb[200001];
int main()
{
	freopen("midstr.in","r",stdin);
	freopen("midstr.out","w",stdout);
	cin>>n;
	cin>>a>>b;
	for(int i=1;i<=n;i++)
	{
		la[i]=a[i-1]-97;
		lb[i]=b[i-1]-97;
		lbb[i]=b[i-1]-97;
	}
	for(int i=n;i>=1;i--)
	{
		if(lb[i]<la[i])
		{
			lb[i]=lb[i]+26;
			lb[i-1]--;
		}
		lc[i]=lb[i]-la[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(lc[i]%2==1)	lc[i+1]=lc[i+1]+26;
		lc[i]=lc[i]/2;
	}
	for(int i=n;i>=1;i--)
	{
		if(lbb[i]<lc[i])
		{
			lbb[i]=lbb[i]+26;
			lbb[i-1]--;
		}
		ans[i]=lbb[i]-lc[i];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<char(ans[i]+97);
	}
}
