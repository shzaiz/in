#include<bits/stdc++.h>
using namespace std;
string a; 
stack<char>q;
char b,c;
long long n,l,m;
int main()
{
	freopen("type.in","r",stdin);
	freopen("type.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		if(b=='T')
		{
			cin>>c; 
			a[l]=c;
			l++;
		}
		if(b=='Q')
		{
			cin>>m;
			cout<<a[m-1]<<endl;
		}
		if(b=='U')
		{
			cin>>m;
			l=l-m;
		}
	}
}
