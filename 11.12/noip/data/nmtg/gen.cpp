#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;

int main()
{
	freopen("nmtg10.in", "w", stdout);
	srand(time(NULL));
	
	int x = rand()%100+901;
	int y = rand()%200+801;
	
	printf("%d %d\n", x, y);
	
	return 0;
}
