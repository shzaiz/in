#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define L 32000
#define R 50000
#define LL 80000
#define RR 100000
using namespace std;
int Rand(){return rand()%(R-L+1)+L;}
int RAND(){return rand()%(RR-LL+1)+L;}
int main()
{
	freopen("Caitlyn_.in","w",stdout);
	srand((unsigned)time(NULL));

	int n=Rand(),m=Rand();
	printf("%d %d %d %d ",n,m,RAND(),RAND());
	cout<<(long long)RAND()*RAND()*RAND()%(n*m+1)<<endl;

	fclose(stdout);
	system("Caitlyn < Caitlyn_.in >Caitlyn_.out");
	return 0;
}
