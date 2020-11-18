#include<bits/stdc++.h>
#define fint register int
#define H 5001
#define N 100001
using namespace std;
string a[N];
int st[N],ts[N];
map <string,int>mp;
int main()
{
	freopen("answer.in","r",stdin);
	freopen("answer.out","w",stdout);
//	freopen("11.in","r",stdin);
//	freopen("11.out","w",stdout);
	int n,m,p,q;
	cin>>n>>m>>p>>q;
	for(fint i=1;i<=n;i++)
	cin>>a[i],mp[a[i]]++;
	if(p!=0&&q==0)
	{
		sort(a+1,a+n+1);
		for(fint i=1;i<=n;i++)
		if(mp[a[i]]==p)
		{
			cout<<a[i];
			return 0;
		}
	}
	else
	if(p==0&&q!=0)
	{
		sort(a+1,a+n+1);
		for(fint i=1;i<=n;i++)
		if(mp[a[i]]==q)
		{
			for(fint j=0;j<m;j++)
			if(a[i][j]=='Y')
			cout<<'N';
			else
			cout<<'Y';
			return 0;
		}
	}
	else
	if(p!=0&&q!=0)
	{
		sort(a+1,a+n+1);
		int tops=0,spot=0;
		for(fint i=1;i<=n;i++)
		{
			if(mp[a[i]]==p)
			st[++tops]=i;
			if(mp[a[i]]==q)
			ts[++spot]=i;
		}
		for(fint i=1;i<=tops;i++)
		if(mp[a[st[i]]]==p)
		{
			for(fint j=1;j<=spot;j++)
			if(mp[a[ts[j]]]==q)
			{
				for(fint k=0;k<m;k++)
				if(a[st[i]][k]==a[ts[j]][k])
				goto lb;
				cout<<a[st[i]];
				return 0;
			}
			lb:
			continue;
		}
	}
	else
	if(p==0&&q==0)
	{
		srand(time(NULL));
		sort(a+1,a+n+1);
		string sa="";
		for(fint i=0;i<m;i++)
		sa+="N";
		if(!mp[sa])
		{
			cout<<sa;
			return 0;
		}
		int cnt=0;
		while(1)
		{
			cnt++;
			int pos=rand()%m,to=rand()%n+1;
			char chan=a[to][pos];
			pos=rand()%m;
			sa[pos]=chan;
			if(!mp[sa])
			{
				cout<<sa;
				return 0;
			}
			if(cnt==100000000)
			break;
		}
	}
	puts("-1");
	return 0;
}

