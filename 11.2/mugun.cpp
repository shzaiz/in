#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int mod = 1e9 + 7;
int n, a[N], f[N], sum;
int s = 1e9, e = -1e9;
long long ans;
int main()
{
#ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s = min(s, a[i]);
        e = max(e, a[i]);
        f[a[i]]++;
    }
    for (int i = s + 1; i <= e; i++) {
        if (f[i] <= 1)
            continue;
        for (int j = s; j <= i / 2; j++)
            if (f[j] && f[i - j])
                if (j != i - j)
                    ans = ans + ((f[i] * (f[i] - 1) >> 1) * f[j] * f[i - j]) % mod;
                else if (f[j] >= 2)
                    ans = ans + ((f[i] * (f[i] - 1) >> 1) * (f[j] * (f[j] - 1) >> 1) % mod) % mod;
    }
    printf("%lld\n", ans % mod);
    return 0;
}