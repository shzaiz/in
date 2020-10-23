#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define MOD 998244353
#define ll long long
bool deb = 1;
int f[2][N];
int alp[N];
int s[N] = {}, tp = 0;
ll pv = -1;
ll bk = -1;
ll ans1 = 1;
ll ans2 = 1;
bool combo = false;
int n, k;
ll finalans = 0;
ll add(ll a, ll b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}
ll mul(ll a, ll b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}
ll qpow(ll u, ll v) {
	ll rep = 1;
	while (v > 0) {
		if (v & 1) {
			rep = mul(rep, u);
		}
		u = mul(u, u);
		v >>= 1;
	}
	return rep;
}
ll sub(ll a, ll b) {
	return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
ll divi(ll a, ll b) {
	return mul(a, qpow(b, MOD - 2));
}
struct Edge {
	int to, nxt;
} e[N];
int head[N], cnt = 0;
void adde(int u, int v) {
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

void dfs(int u, int fa) {
	ll an2 = ans2, pvv = -1, bkk = -1, com = 0, an1 = ans1;
	s[++tp] = alp[u];
	if (u == 1 && s[tp] == 0) {
		ans2 = mul(ans2, k);
		an2 = ans2;
		if(deb) printf("pos[%d] :%d  ...(1)\n", u, mul(ans2, ans1));
		finalans ^= mul(ans2, ans1);
	} else if (s[tp] == 0) {
		if (!combo) {
			pv = tp - 1;
			pvv = pv;
		}else{
            pvv= pv;
        }
		combo = 1;
		com = 1;
		ans2 = mul(ans2, (k - 1));
		an2 = ans2;
		if(deb)  printf("pos[%d] :%d   ...(2)\n", u, mul(ans2, ans1));
		finalans ^= mul(ans2, ans1);
	} else {
        // if(pv==-1){pv = tp; pvv = pv;}
        
		bk = tp;
        bkk = bk;
		if (combo) {
			if (pv == -1) {
                // printf("Ouch\n");
				//  printf("%d %d\n",k-1,bk-2);
				ans1 = mul(1, qpow(k - 1, bk - 1));
				an1 = ans1;
			} else if (s[pv] == s[bk]) {
				ans1 = mul(ans1, f[1][bk - pv - 1]);
				an1 = ans1;
			} else {
				ans1 = mul(ans1, f[0][bk - pv - 1]);
				an1 = ans1;
			}
			if(deb)  printf("pos[%d] :%d   ...(3)\n", u, ans1);
			finalans ^= ans1;
			ans2 = 1;
			an2 = ans2;

		} else {
			if(deb) printf("pos[%d] :%d   ...(4)\n", u, ans1);
			finalans ^= ans1;
		}
		pv = tp, bk = -1;
		pvv = pv, bkk = bk;
		combo = false;
		com = combo;
	}
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == fa)
			continue;
		dfs(v, u);
		pv = pvv;
		ans2 = an2;
		ans1 = an1;
		combo = com;
		bk = bkk;
		tp--;
	}

}

int main() {
#ifndef ONLINE_JUDGE
freopen("D:/Testcases/in.ac","r",stdin);
freopen("D:/Testcases/out2.ac","w",stdout);
#else
freopen(".in","r",stdin);
freopen(".out","w",stdout);
#endif
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> alp[i];
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		adde(i+1, x);
		adde(x, i+1);
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		// Since the mod value is 998244353 so there will not be
		// overflow things. Casts are ok.
		f[0][i] = (int)add(f[1][i - 1], mul((k - 2), f[0][i - 1]));
		f[1][i] = (int)mul((k - 1), f[0][i - 1]);
	}
	dfs(1, 0);
	printf("%lld\n", finalans);
}