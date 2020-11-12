#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;

typedef long long LL;

inline bool fuck(LL a, LL b, LL c)
{
	if(b < a) return 1;
	if(a * a + b * b < c * c) return 1;
	return 0;
}
inline bool shit(LL a, LL c)
{
	if(a * a + (c - 1) * (c - 1) < c * c) return 1;
	return 0;
}

int N, L, a, b, c;

int main()
{
	freopen("sbtg1.in", "w", stdout);
	srand(time(NULL));
	int T = 10; printf("%d\n", T);
while(T--)
{
	N = 100000;
	L = rand()%800000+200000;
	printf("%d %d\n", N, L);
	for(int i = 1; i <= N; ++i)
	{
		c = rand()%1000000;
		while(c <= 4) c = rand()%1000000;
		
		a = rand()%min(c, 10000);
		while(shit(a, c))
			a = rand()%min(c, 10000);
			
		b = rand()%c;
		while( fuck(a, b, c) ) b = rand()%c;
		printf("%d %d %d\n", a, b, c);
	}
}

	return 0;
}
