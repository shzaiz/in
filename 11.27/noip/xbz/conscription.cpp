#include<bits/stdc++.h>
#define fint register int
#define H 5001
#define N 500001
using namespace std;
struct node
{
	int x;
	int y;
	int z;
}
a[N];
int f[N];
inline int read();
inline int findx(int x);
inline bool cmp(node aa,node bb);
int main()
{
	freopen("conscription.in","r",stdin);
	freopen("conscription.out","w",stdout);
	int T;
	T=read();
	while(T--)
	{
		int n,m,r;
		cin>>n>>m>>r;
		int x,y,z;
		for(fint i=1;i<=r;i++)
		cin>>x>>y>>z,a[i]=(node){x+1,y+1+n,z};
		for(fint i=1;i<=n+m;i++)
		f[i]=i;
		sort(a+1,a+r+1,cmp);
		int tot=0,ans=0;
		for(fint i=1;i<=r;i++)
		{
			if(findx(a[i].x)!=findx(a[i].y))
			f[findx(a[i].x)]=findx(a[i].y),ans+=a[i].z,tot++;
			if(tot==n+m-1)
			break;
		}
		cout<<(n+m)*10000-ans<<endl;
	}
	return 0;
}

inline bool cmp(node aa,node bb)
{
	return aa.z>bb.z;
}

inline int findx(int x)
{
	if(f[x]==x)
	return x;
	return f[x]=findx(f[x]);
}

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

/*
2
5 5 8
4 3 6831
1 3 4583
0 0 6592
0 1 3063
3 3 4975
1 3 2049
4 2 2104
2 2 781
5 5 10
2 4 9820
3 2 6236
3 1 8864
2 4 8326
2 0 5156
2 0 1463
4 1 2439
0 4 4373
3 4 8889
2 4 3133

*/
