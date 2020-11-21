#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 10000
#define M 40000
#define L 1000
using namespace std;


int main()
{
	freopen("Eli_.in","w",stdout);

	srand((unsigned)time(NULL));
	int i,j,k;
	int a,b,c;
	int n,m;

	n=N,m=M;
	printf("%d %d\n",n,m);

	for(i=1;i<=n;i++)
	{
		printf("%d %d\n",rand()%L+1,rand()%L+1);
	}
	while(m--)
	{
		do{i=rand()%n+1,j=rand()%n+1;}while(i==j);
		printf("%d %d %d %d %d\n",i,j,rand()%L+1,rand()%L+1,rand()%L+1);
	}
	fclose(stdout);
	system("bf <Eli_.in >Eli_.out");
	return 0;
}
