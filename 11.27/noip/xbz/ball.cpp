#include<bits/stdc++.h>
#define fint register int
#define H 5001
#define N 201
using namespace std;
int f[N];
inline bool pd(int x);
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		puts("1");
		return 0;
	}
	int num=1;
	lb:
	while(1)
	{
		for(fint i=1;i<=n;i++)
		if(pd(num+f[i])||!f[i])
		{
			f[i]=num,num++;
			goto lb;
		}
		break;
	}
	cout<<num-1<<endl;
	return 0;
}

inline bool pd(int x)
{
	int now=(int)sqrt(x);
	if(now*now==x)
	return 1;
	return 0;
}
