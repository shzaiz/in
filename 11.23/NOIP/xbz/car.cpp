#include<bits/stdc++.h>
#define fint register int
#define H 5001
#define N 3000001
using namespace std;
int x[N],y[N];
bool vis[35][35][35][35];
inline int read();
inline void print(int x);
inline int pd(int i,int j,int k,int l);
inline int deng(int a,int b,int c,int d);
int main()
{
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	int n;
	cin>>n;
	for(fint i=1;i<=n;i++)
	cin>>x[i]>>y[i];
	int ans=0;
	for(fint i=1;i<=n;i++)
	for(fint j=i+1;j<=n;j++)
	for(fint k=j+1;k<=n;k++)
	for(fint l=k+1;l<=n;l++)
	if(pd(i,j,k,l))
	ans++;
	print(ans);
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

inline int pd(int i,int j,int k,int l)
{
	int now[5]={0};
	now[1]=i,now[2]=j,now[3]=k,now[4]=l;
	for(fint ii=1;ii<=4;ii++)
	for(fint jj=1;jj<=4;jj++)
	for(fint kk=1;kk<=4;kk++)
	for(fint ll=1;ll<=4;ll++)
	{
		if(deng(now[ii],now[jj],now[kk],now[ll]))
		return 1;
	}
	return 0;
}

inline int deng(int a,int b,int c,int d)
{
	if(a==b||a==c||a==d||b==c||b==d||c==d)
	return 0;
	int lena=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
	int lenb=(x[c]-x[d])*(x[c]-x[d])+(y[c]-y[d])*(y[c]-y[d]);
	if(lena!=lenb)
	return 0;
	if((y[a]-y[b])*(y[c]-y[d])==-(x[a]-x[b])*(x[c]-x[d]))
	{
		if((y[a]-y[c])*(y[c]-y[b])==-(x[a]-x[c])*(x[c]-x[b])&&(y[a]-y[d])*(y[b]-y[d])==-(x[a]-x[d])*(x[b]-x[d])&&(y[c]-y[b])*(y[b]-y[d])==-(x[c]-x[b])*(x[b]-x[d])&&(y[a]-y[c])*(y[a]-y[d])==-(x[a]-x[c])*(x[a]-x[d]))
		return 1;
	}
	else
	return 0;
	return 0;
}

