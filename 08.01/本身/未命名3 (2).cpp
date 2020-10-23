#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, m, x, q[100001], f[1001][1001];
string s;
inline void floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if(i != j && i != k && j != k) {
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				}
			}
		}
	}
	return;
}
int main() {
	memset(f, INF, sizeof(f));
	scanf("%d %d\n", &m, &n);
	while(m--) {
		int z = 0;
		getline(cin, s);
		for (int i = 0; i < s.length(); ++i) {
			x = 0;
			while(s[i] <= '9' && s[i] >= '0') {
				x = x * 10 + s[i] - '0';
				++i;
			}
			q[++z] = x;
		}
		for (int i = 1; i <= z; ++i) {
			f[i][i] = 0;
			for (int j = i + 1; j <= z; ++j) {
				f[q[i]][q[j]] = 1;
			}
		}
	}
	floyd();
	if(f[1][n] == INF) {
		cout<<"NO";
	} else {
		cout<<f[1][n] - 1;
	}
	return 0;
}

