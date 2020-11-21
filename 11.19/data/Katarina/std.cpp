#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#define N 1001000
const int oo = 1000000000;
using namespace std;

struct case1
{
	int v;
};
char a[N][3];
int b[N],c[N],rec[N];
priority_queue<case1> h;

bool operator < (case1 x,case1 y)
{ 
	return b[x.v]>b[y.v];
}
int n,m;
int main()
{
	int o=0,ans=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		scanf("%s%d",a[i],&b[i]);
	c[n+1]=oo;
	for (int i=n;i;i--)
	{
		c[i]=c[i+1];
		if (a[i][0]=='p')
			c[i]=min(c[i],b[i]-1);
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i][0]=='d')
			h.push((case1){i});
		while (h.size()>c[i])
			h.pop();
	}
	while (h.size())
	{
		rec[++o]=h.top().v;
		ans+=b[rec[o]];
		h.pop();
	}
	if (o>=m)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
