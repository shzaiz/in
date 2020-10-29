#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define inf 0x7fffffff
using namespace std;
ll a[1010], b[1010], c[1010];
vector<ll> v, v1;
int main()
{
    int i, j, k, n, m, x, y, z, w;
    scanf("%d%d%d%d", &x, &y, &z, &w);
    for (i = 0; i < x; i++) {
        scanf("%lld", &a[i]);
    }
    for (i = 0; i < y; i++) {
        scanf("%lld", &b[i]);
    }
    for (i = 0; i < z; i++) {
        scanf("%lld", &c[i]);
    }
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            v.push_back(a[i] + b[j]);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    v.resize(w);
    for (i = 0; i < v.size(); i++) {
        for (j = 0; j < z; j++) {
            v1.push_back(v[i] + c[j]);
        }
    }
    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    for (i = 0; i < w; i++) {
        printf("%lld\n", v1[i]);
    }
    return 0;
}
