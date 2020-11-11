
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define inf 1<<30
#define ll long long
using namespace std;
int n;
ll m,ct;
void dfs(int w,ll s)
{
	if(w>n)
	   {if(s==m) ct++;
	    return;
	   }
	ll i,num=s;
	for(i=0;i<=9;i++)
	   {if(m!=0&&i==0) continue;
	    if(m%i!=0||num*i>m) continue;
	    num*=i;
		dfs(w+1,num);
		num/=i;
	   }
}
int main()
{
	freopen("digit.in","r",stdin);
	freopen("baoli.out","w",stdout);
	scanf("%d%lld",&n,&m);
	if(m!=0) dfs(1,1);
	printf("%lld\n",ct);
	return 0;
}
