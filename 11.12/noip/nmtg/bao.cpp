#include<bits/stdc++.h>
using namespace std;
#define R register int
#define LL long long
LL n,m,ans,go;

int gcd(int x,int y)
{
	if(!y) return x;
	else return gcd(y,x%y);
}

void work()
{
	scanf("%lld%lld",&n,&m);
	++n,++m;//因为是一个网格，所以真正的坐标系其实有(n+1,m+1)
	go=n*m;
	ans=go * (go - 1) * (go - 2) / 6 - n * m * (m - 1) * (m - 2) / 6 - m * n * (n - 1) * (n - 2) / 6;//记得除掉取出数列的全排列
	for(R i=1; i<n ;i++)//因为是取了原点，所以相当于坐标系是从0开始了
		for(R j=1; j<m ;j++)//枚举这个点
			ans-=(LL)2 * (LL)(gcd(i,j) - 1) * (LL)(n - i) * (LL)(m - j); 
	printf("%lld\n",ans);
}

int main()
{
	freopen("nmtg.in","r",stdin);
	freopen("baoli.out","w",stdout);
	work();
	fclose(stdin);
	return 0;
}
