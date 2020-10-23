#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
#define ou (i % 2 == 0 ? 1 : 0)
#define ji (i % 2 == 1 ? 1 : 0)
ll n, m, x[2], y[2], g, ans;
ll qpow(ll a){ll res = 1, k = MOD - 2;while (k) { if (k & 1)res = res * a % MOD;a = a * a % MOD;k >>= 1;}return res;}
ll inv2 = qpow(2);
ll inv4 = qpow(4);
void up(ll x, ll h){
    x %= MOD;h %= MOD;
    ans += (m * h % MOD) + ((x * x * m % MOD) * qpow(4 * h)) % MOD;ans %= MOD;
}
void down(ll x, ll h){
    x = x % MOD;h = h % MOD;
    ans += (x * x * m % MOD) * qpow(4 * h);ans %= MOD;
}
void ping(ll x){
    x %= MOD;
   // ans +=0;
   ans += (x * m*1*1 % MOD) * inv2;ans %= MOD;
}
int main(){
#ifdef XBZAKIOIISTRUE
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
    freopen("jump.in", "r", stdin);
    freopen("jump.out", "w", stdout);
#endif
    cin >> n >> m >> g;
    cin >> x[1];
    cin >> y[1];
    for (int i = 2; i <= n; i++) {
        cin >> x[ji];cin >> y[ji];
        if (y[ji] > y[ou])up(x[ji] - x[ou], y[ji] - y[ou]);
        if (y[ji] < y[ou])down(x[ji] - x[ou], y[ou] - y[ji]);
        if (y[ji] == y[ou])ping(x[ji] - x[ou]);
        //printf("%lld",ans);
    }
    ll anss = ans * g % MOD;
    printf("%lldJ",anss );
    return 0;
}