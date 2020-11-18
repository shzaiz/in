#include<bits/stdc++.h>
#define fint register int
#define N 467955
#define H 5001
using namespace std;
int a[N],b[N],ans=0,n;
inline void dfs(int x,int y);
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	freopen("21.in","r",stdin);
//	freopen("21.out","w",stdout);
	cin>>n;
	for(fint i=1;i<=n;i++)
	cin>>a[i];
	dfs(1,1);
	cout<<ans;
	return 0;
}

inline void dfs(int x,int y)//截取序列长度，当前遍历位置 
{
	if(y>n)
	{
		for(int i=1;i<x-1;i++)
		{
			int s1=b[1],s2=b[i+1];
			for(int j=2;j<=i;j++)
			s1^=b[j];
			for(int j=i+2;j<=x-1;j++)
			s2&=b[j];
			if(s1==s2)
			ans++;
		}
		return ;
	}
	b[x]=a[y];//暂存截取的序列 
	dfs(x+1,y+1),dfs(x,y+1);
	return ;
}
