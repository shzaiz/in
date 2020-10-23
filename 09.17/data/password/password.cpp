#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 10010
#define MaxS 2000010

using namespace std;

int N, K, M, X[MaxN], Size[MaxN];
int seq[MaxN], Dist[25][25], num[MaxN], ti;
int Que[MaxN], Qhead, Qtail, Dis[MaxN], oo = 1000000000, f[MaxS], g[MaxS];
bool vis[MaxN];

int Min(int a, int b) {
	return a < b ? a : b;
}

void Bfs(int s) {
	int i, j;
	memset(vis, 0, sizeof(vis));
	vis[Que[Qhead = Qtail = 1] = s] = 1;
	Dis[s] = 0;
	for( ; Qhead <= Qtail; ++Qhead) {
		int now = Que[Qhead];
		for(i = 1; i <= M; ++i) {
			if(now + Size[i] <= N && !vis[now + Size[i]]) {
				vis[Que[++Qtail] = now + Size[i]] = 1;
				Dis[now + Size[i]] = Dis[now] + 1;
			}
			if(now - Size[i] > 0 && !vis[now - Size[i]]) {
				vis[Que[++Qtail] = now - Size[i]] = 1;
				Dis[now - Size[i]] = Dis[now] + 1;
			}
		}
	}
	for(i = 1; i <= N; ++i)
		if(num[i]) {
			if(!vis[i])
				Dist[num[s]][num[i]] = oo;
			else
				Dist[num[s]][num[i]] = Dis[i];
		}
}

void DP() {
	int i, j;
	for(i = 0; i < (1 << ti); ++i) {
		if(i == 0) continue;
		f[i] = oo; g[i] = g[i >> 1] + (i & 1);
		if(g[i] & 1) continue;
		int start = 0;
		for(j = 0; j < ti; ++j)
			if(i & (1 << j)) {
				if(!start)
					start = j + 1;
				else {
					f[i] = Min(f[i], f[i - (1 << (start - 1)) - (1 << j)] + Dist[start][j + 1]);
				}
			}
	}
	printf("%d\n", f[(1 << ti) - 1] >= oo ? -1 : f[(1 << ti) - 1]);
}

int main() {
	freopen("password10.in", "r", stdin);
	freopen("password10.out", "w", stdout);
	int i, j;
	scanf("%d%d%d", &N, &K, &M);
	for(i = 1; i <= K; ++i) {
		scanf("%d", &X[i]);
		seq[X[i]] = 1;
	}
	for(i = 1; i <= M; ++i) scanf("%d", &Size[i]);
	for(i = N + 1; i; --i) seq[i] ^= seq[i - 1];
	++N;
	for(i = 1; i <= N; ++i)
		if(seq[i])
			num[i] = ++ti;
	for(i = 1; i <= N; ++i)
		if(seq[i])
			Bfs(i);
	DP();
	return 0;
}
