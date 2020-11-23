#include<bits/stdc++.h>
#define fint register int
#define H 5001
#define N 3000001
using namespace std;
struct node
{
	int val;
	int id;
}
a[N];
int t[N];
int n,b[N];
inline int read();
inline int query(int x);
inline void print(int x);
inline int lowbit(int x);
inline void adds(int x,int y);
inline bool cmp(node aa,node bb);
inline void adds(int u,int v,int w);
int main()
{
	freopen("disk.in","r",stdin);
	freopen("disk.out","w",stdout);
	cl:
	while(cin>>n)
	{
		memset(t,0,sizeof(t));
		for(fint i=1;i<=n;i++)
		cin>>a[i].val,a[i].id=i;
		sort(a+1,a+n+1,cmp);
		for(fint i=1;i<=n;i++)
		b[a[i].id]=i;//ÀëÉ¢»¯
		int j;
		for(fint i=1;i<=n;i++)
		{
			if(query(b[i]))
			goto lb;
			j=i+1;
			for(j=i+1;j<=n;j++)
			{
				if(b[j]>=b[j-1])
				break;
				if(query(b[j]))
				goto lb;	
			}
			adds(b[j-1],1),adds(b[i],-1);
			i=j-1;
		}
		goto bl;
		lb:
		puts("J");
		goto cl;
		bl:
		puts("Y");
	}
	return 0;
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

inline void print(int x)
{
	if(x<0)
	putchar('-'),x=-x;
	if(x>9)
	print(x/10);
	putchar(x%10+'0');
	return ;
}

inline bool cmp(node aa,node bb)
{
	return aa.val<bb.val;
}

inline int lowbit(int x)
{
	return x&(-x);
}

inline void adds(int x,int y)
{
	for(fint i=x;i<=n;i+=lowbit(i))
	t[i]+=y;
	return ;
}

inline int query(int x)
{
	int tot=0;
	for(fint i=x;i;i-=lowbit(i))
	tot+=t[i];
	return tot;
}
