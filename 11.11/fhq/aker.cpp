#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 20101009;
const ll maxn = 1e7 + 10;
ll np[maxn], pr[maxn], num, mu[maxn], S[maxn];
ll n, m; 
ll get(ll n, ll m){
    return (n * (n + 1) / 2) % mod * (m * (m + 1) / 2 % mod) % mod;
}
ll anss(ll x, ll y){
    ll ans = 0;
    for (ll l = 1, r; l <= x; l = r + 1) {
        r = min(x / (x / l), y / (y / l));
        ans = (ans + (S[r] - S[l - 1] + mod) % mod * get(x / l, y / l) % mod) % mod;
    }
    return ans;
}

ll solve(){
    ll ans = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = min((n / (n / l)), m / (m / l));
        ans = (ans + (l + r) * (r - l + 1) / 2 % mod * (anss(n / l, m / l)) % mod) % mod;
    }
    return ans;
}

int main(){
    mu[1] = 1;
    for (ll i = 2; i < maxn; ++i) {
        if (!np[i])
            pr[++num] = i, mu[i] = -1;
        for (ll j = 1; j <= num; ++j) {
            if (i * pr[j] >= maxn)
                break;
            np[i * pr[j]] = 1;
            if (i % pr[j] == 0) {
                mu[i * pr[j]] = 0;
                break;
            }
            mu[i * pr[j]] = -mu[i];
        }
    }
    for (ll i = 1; i < maxn; ++i) {
        S[i] = (S[i - 1] + (mu[i] * i + mod) % mod * i % mod) % mod;
    }

    scanf("%lld%lld", &n, &m);
    if (n > m)
        swap(n, m);
    cout << solve() << "\n";
    return 0;
}