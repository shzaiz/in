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
int main()
{
	freopen("Katarina_.in","w",stdout);
	srand((unsigned)time(NULL));

	int i,j,k;
	int a,b,c;

	int n,m;
	n=rands(300000,500000);
	printf("%d %d\n",n,n+15);
	while(n--)printf("d %d\n",rands(0,741));

	fclose(stdout);
	system("std <Katarina_.in >Katarina_.out");
}
