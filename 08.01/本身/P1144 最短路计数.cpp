#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 0x7fffffff;
int n, m, x, y,u,v;
int vis[1000010],dis[1000010], ans[1000010];
vector<int> g[1000010];
queue<int> q;
inline void spfa(int x) {
	for (int i=1; i<=n; i++)dis[i] = maxn;
	q.push(x);
	vis[x] = 1;
	ans[x] = 1;
	dis[x] = 0;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 0; i < g[u].size(); i++) {
			v = g[u][i];
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				ans[v] = ans[u];
				if (!vis[v])
								                                vis[v] = 1, q.push(v);
			} else if (dis[v] == dis[u] + 1)
						                        ans[v] = (ans[v] + ans[u]) % 100003;
		}
		vis[u] = 0;
	}
}
int main() {
	cin >> n >> m;
	while (m--) {
		cin >> x >> y;
		g[x].push_back(y),g[y].push_back(x);
	}
	spfa(1);
	for (int i = 1; i <= n; i++)
		        cout << ans[i] << endl;
	return 0;
}
