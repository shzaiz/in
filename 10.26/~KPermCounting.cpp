#include <cstdio>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)

const int N = 2005;
const int P = 924844033;
int n, k, a[N], fac[N];
long long f[N][N][2][2];
bool vis[N];

int main()
{
    scanf("%d%d", &n, &k);
    fac[0] = 1;
    FOR(i, 1, n)
    fac[i] = 1LL * fac[i - 1] * i % P;
    int tot = 0;
    FOR(i, 1, n)
    if (!vis[i]) for (int j = i; j <= n; j += k) vis[j] = 1,
                                                 a[++tot] = j;
    f[0][0][0][0] = 1;
    a[0] = -(1 << 30);
    FOR(i, 1, n)
    {
        f[i][0][0][0] = 1;
        FOR(j, 1, i)
        {
            f[i][j][0][0] = (f[i - 1][j][1][0] + f[i - 1][j][0][0] + (a[i] - a[i - 1] == k) * f[i - 1][j - 1][0][0]) % P;
            f[i][j][0][1] = (a[i + 1] - a[i] == k) * (f[i - 1][j - 1][1][0] + f[i - 1][j - 1][0][0]) % P;
            f[i][j][1][0] = (f[i - 1][j][0][1] + f[i - 1][j][1][1] + (a[i] - a[i - 1] == k) * f[i - 1][j - 1][0][1]) % P;
            f[i][j][1][1] = (a[i + 1] - a[i] == k) * (f[i - 1][j - 1][0][1] + f[i - 1][j - 1][1][1]) % P;
        }
    }
    int ans = 0;
    FOR(i, 0, n)
    {
        int sum = (f[n][i][0][0] + f[n][i][0][1] + f[n][i][1][0] + f[n][i][1][1]) % P;
        if (i & 1)
            (ans += P - 1LL * sum * fac[n - i] % P) %= P;
        else
            (ans += 1LL * sum * fac[n - i] % P) %= P;
    }
    printf("%d\n", ans);
    return 0;
}