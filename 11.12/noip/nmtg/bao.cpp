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
	++n,++m;//��Ϊ��һ��������������������ϵ��ʵ��(n+1,m+1)
	go=n*m;
	ans=go * (go - 1) * (go - 2) / 6 - n * m * (m - 1) * (m - 2) / 6 - m * n * (n - 1) * (n - 2) / 6;//�ǵó���ȡ�����е�ȫ����
	for(R i=1; i<n ;i++)//��Ϊ��ȡ��ԭ�㣬�����൱������ϵ�Ǵ�0��ʼ��
		for(R j=1; j<m ;j++)//ö�������
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
