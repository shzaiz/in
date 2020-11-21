#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a,he,ge;
char ch;
priority_queue<int,vector<int>,greater<int> >q; 
signed main( )
{
	freopen("Katarina.in","r",stdin);
	freopen("Katarina.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ch>>a;
		if(ch=='d')
		{
			ge++;
			he=he+a;
			q.push(a);
		}
		else
		{
			if(a==0)
			{
				cout<<-1;
				return 0;
			}	
			while(ge>=a)
			{
				int o=q.top( );
				q.pop( );
				ge--;
				he=he-o;
			}
		}
	}
	if(ge>=m)
	{
		cout<<he<<endl;
	}
	else cout<<"-1";
}
