#include <bits/stdc++.h>
#define N 1000005
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int n, m, Q, F[N];
int head[N], pre[N<<1], to[N<<1], sz, inde[N];
ll a[N];
inline void addedge(int u, int v) {
	pre[++sz] = head[u]; head[u] = sz; to[sz] = v; inde[v]++;
}

struct oper {
	int tp, p;
	ll v, mul, sum; 
} b[N];

queue<int> q;
int ord[N], bnbn;
void topo() {
	for (int i = 1; i <= m; i++) if (!inde[i]) q.push(i);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		ord[++bnbn] = x;
		for (int i = head[x]; i; i = pre[i]) {
			int y = to[i];
			inde[y]--;
			if (!inde[y]) q.push(y);
		}
	}
}

void getmul() {
	for (int i = m; i; i--) {
		int x = ord[i];
		for (int j = head[x]; j; j = pre[j]) {
			int y = to[j];
			b[x].mul = b[x].mul * b[y].mul % mod;
		}
	} 
}

void getsum() {
	for (int i = 1; i <= m; i++) {
		int x = ord[i]; ll now = 1;
		for (int j = head[x]; j; j = pre[j]) {
			int y = to[j];
			b[y].sum = (b[y].sum + b[x].sum * now % mod) % mod;
			now = now * b[y].mul % mod;
		}
	}
}

int main() {
	cin>>n; 
	for (int i = 1; i <= n; i++) cin>>a[i]; 
	cin>>m;
	for (int i = 1; i <= m; i++) {
		cin>>b[i].tp;
		if (b[i].tp == 1) {
			cin>>b[i].p>>b[i].v ;
			b[i].mul = 1;
		} else if (b[i].tp == 2) {
			cin>>b[i].v ; b[i].mul = b[i].v;
		} else {
			cin>>b[i].p; b[i].mul = 1;
			for (int j = 1, x; j <= b[i].p; j++) {
				cin>>x ;
				addedge(i, x);
			}
		}
	}
	topo(); 
	getmul();
	cin>>Q; ll now = 1;
	for (int i = 1; i <= Q; i++) cin>>F[i] ;
	for (int i = Q; i; i--) {
		int x = F[i]; b[x].sum = (b[x].sum + now) % mod;
		now = now * b[x].mul % mod;
	}
	getsum();
	for (int i = 1; i <= n; i++) a[i] = a[i] * now % mod;
	for (int i = 1; i <= m; i++) {
		if (b[i].tp == 1) {
			a[b[i].p] = (a[b[i].p] + b[i].v * b[i].sum % mod) % mod;
		}
	}
	for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
	return 0; 
} 

