
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000;
struct node {
    long long a, b, c, s;
} g[maxn];
int n, m;
long long s[maxn];
long long calc(int flag1, int flag2, int flag3, int i)
{
    long long ans = 0;
    if (flag1)
        ans += g[i].a;
    else
        ans -= g[i].a;
    if (flag2)
        ans += g[i].b;
    else
        ans -= g[i].b;
    if (flag3)
        ans += g[i].c;
    else
        ans -= g[i].c;
    return ans;
}

bool cmp(long long a, long long b)
{
    return a > b;
}

long long getMax(int a, int b, int c)
{
    for (int i = 1; i <= n; i++)
        s[i] = calc(a, b, c, i);
    sort(s + 1, s + 1 + n, cmp);
    long long sum = 0;
    for (int i = 1; i <= m; i++)
        sum += s[i];
    return sum;
}
int main()
{
    while (cin >> n >> m) {
        memset(s, 0, sizeof(s));
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> g[i].a >> g[i].b >> g[i].c, g[i].s = g[i].a + g[i].b + g[i].c;
        ans = max(ans, getMax(1, 1, 1));
        ans = max(ans, getMax(1, 1, 0));
        ans = max(ans, getMax(1, 0, 1));
        ans = max(ans, getMax(0, 1, 1));
        ans = max(ans, getMax(1, 0, 0));
        ans = max(ans, getMax(0, 0, 1));
        ans = max(ans, getMax(0, 1, 0));
        ans = max(ans, getMax(0, 0, 0));
        cout << ans << endl;
    }
    return 0;
}