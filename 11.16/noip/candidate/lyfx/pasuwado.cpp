#include<bits/stdc++.h>
using namespace std;
#define int long long
long long m,la;
string aa; 
string ans;
int lian[100001],head[27],a[1000001];
int lowbit(int x){return x&(-x);}
void add(int x,int k)
{
	while(x<=la)
	{
		a[x]+=k;
		x=x+lowbit(x);
	}
	return ;
}
int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans=ans+a[x];
		x=x-lowbit(x); 
	}
	return ans;
}
signed main( )
{
	freopen("pasuwado.in","r",stdin);
	freopen("pasuwado.out","w",stdout);
	cin>>m;
	cin>>aa;
	la=aa.size( );
	for(int i=la;i>=1;i--)
	aa[i]=aa[i-1];
	for(int i=la;i>=1;i--)
	{
		lian[i]=head[aa[i]-'a'+1];
		head[aa[i]-'a'+1]=i;
	} 
	for(int i=1;i<=la;i++)
	{
		for(int j=1;j<=26;j++)
		{
			if(head[j]!=0)
			{
				int cha=sum(head[j]);
				if(m>=head[j]-cha-1)
				{
					m-=(head[j]-cha-1);
					ans=ans+char(j-1+'a');
					add(head[j],1);
					head[j]=lian[head[j]];
					break;
				}
			}
		}
	}
	cout<<ans;
}
