#include<ctime>
#include<cmath>
#include<cstdio>
#include<windows.h>
#include<algorithm>
#define For(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define N 100010
#define maxlongint 2147483647
using namespace std;
int n,m,x,y,f[100],fa[N];
long long a[N];
int Random(int mo)
{
	return (rand()<<15 ^ rand())%mo;
}
int main()
{
	/*f[1]=1;
	FOR(i,2,50)
	{
		f[i]=f[i-1]+f[i-2];
		printf("%d %d\n",i,f[i]);
	}*/
	freopen("tri3.in","w",stdout);
	scanf("%d%d",&n,&m);
	printf("%d %d\n",n,m);
	a[1]=Random(100)+1;
	FOR(i,2,n)
	{
		x=i-Random(5)-1;
		if (x<1) x=1;
		fa[i]=x;
		a[i]=a[x]+a[fa[x]]+Random(10);
		if (a[i]>maxlongint) a[i]=Random(1000)+1;
	}
	For(i,n) printf("%I64d ",a[i]);puts("");
	FOR(i,2,n) printf("%d %d\n",fa[i],i);
	For(i,m)
		if (Random(2))
		{
			x=Random(n)+1;
			a[x]=a[fa[x]]+a[fa[fa[x]]]+Random(10);
			if (a[x]>maxlongint) a[x]=Random(1000)+1;
			printf("1 %d %I64d\n",x,a[x]);
		}
		else
			if (Random(2))
				printf("0 %d %d\n",Random(n)+1,Random(n)+1);
			else
			{
				do{
					x=Random(n)+1;
					y=x+Random(40)+1;
				}while(y>n);
				printf("0 %d %d\n",x,y);
			}
	//while(1);
	return 0;
}
