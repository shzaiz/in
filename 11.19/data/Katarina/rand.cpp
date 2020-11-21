#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 500000
using namespace std;
bool randq(int x)
{
	double gailv=(double)x*x/4.1*100;
	int y=rand()%10001;
	if(y<gailv)return 1;
	else return 0;
}
long long rands(int l,int r)
{return (long long)rand()*rand()*rand()%(r-l+1)+l;}
int n,m,cnt;
int seq[N<<2];
int val[N<<2];
int main()
{
	freopen("Katarina_.in","w",stdout);
	srand((unsigned)time(NULL));

	int i,j,k;
	int a,b,c;
	int now=rand()%5+1;
	seq[cnt=1]=now,n=rands(N,N);
	val[now]=rands(1,now);
	memset(val,-1,sizeof val);
	while(now<n)
	{
		now+=rand()%16+5;
		if(now<=n)
		{
			seq[++cnt]=now;
			k=now-seq[cnt-1];
			val[now]=val[seq[cnt-1]]+rands(k*2/5,k*3/2);
		}
	}
	for(i=1;i<cnt;i++)
	{
		int l=3,r=(seq[i+1]-seq[i])*2/3;
		if(r<l)r=l;
		int L=val[seq[i]],R=val[seq[i+1]];
		now=seq[i]+rands(l,r);
		if(randq(seq[i+1]-seq[i]))
		{
			while(now<seq[i+1])
			{
				val[now]=rands(L,(R-L)*2+R);
				now+=rands(l,r);
			}
		}
		else {
			while(now<seq[i+1])
			{
				val[now]=rands(R+1,(R-L)*3+R+1);
				now+=rands(l,r);
			}
		}
	}
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(val[i]+1)cnt=min(cnt,val[i]-1);
		else cnt++;
	}
	printf("%d %d\n",n,rands(0,cnt)); // 这里的m要注意。大于cnt则为-1

	for(i=1;i<=n;i++)
	{
		if(val[i]+1)printf("p %d\n",val[i]);
		else printf("d %d\n",rands(0,1000));
	}

	fclose(stdout);
	system("std <Katarina_.in >Katarina_.out");
}

/*
先随机个单升序列出来，两点之间差5~20
然后两两之间插大值。
之后从1到n扫一遍看能取到多少法强
然后随机一下1/7概率出-1
*/

/*
细节，
大值中间插的数随机一下，

*/