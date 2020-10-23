#include <bits/stdc++.h>
using namespace std;
const int N = 300005, P = 1000000007;

int n, mx, m;
int a[N], b[N], f[N];
int cnt, p[N], vis[N], phi[N];

void init(int n) {
	cnt = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {
			p[++cnt] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= cnt && p[j] * i <= n; ++j) {
			vis[p[j] * i] = 1;
			if (i % p[j] == 0) {
				phi[p[j] * i] = phi[i] * p[j];
				break;
			} else {
				phi[p[j] * i] = phi[i] * (p[j] - 1);
			}
		}
	}
}

int main() {
	cin>>n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin>>x;
		++a[x];
		mx = std::max(mx, x);
	}
	m = 0;
	while ((1 << m) <= mx) {
		++m;
	}
	init(1 << m);
	f[0] = 1, b[0] = 0;
	for (int i = 1; i < (1 << m); ++i) {
		b[i] = b[i >> 1] << 1 | 1;
		if (a[i]) {
			int mask = b[i] ^ i;
			for (int S = mask; ; S = (S - 1) & mask) {
				f[S | i] = (f[S | i] + 1ll * f[S] * a[i]) % P;
				if (!S) {
					break;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << m); ++i) {
		ans = (ans + 1ll * f[i] * phi[i + 1]) % P;
	}
	for (int i = 0; i < a[0]; ++i) {
		ans = 2 * ans % P;
	}
	printf("%d\n",ans);
}
