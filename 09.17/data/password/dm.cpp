#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int N = 20, K = 5, M = 3;
bool vis[10010];


int main() {
	freopen("password4.in", "w", stdout);
	int i, j;
	srand(time(0));
	printf("%d %d %d\n", N, K, M);
	for(i = 1; i <= K; ++i) {
		int tmp = rand() % N + 1;
		while(vis[tmp]) tmp = rand() % N + 1;
		vis[tmp] = 1;
		printf("%d ", tmp);
	}
	puts("");
	for(i = 1; i <= M; ++i)
		printf("%d ", rand() % N + 1);
	puts("");
	return 0;
}
