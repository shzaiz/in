#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, pos;
const int mod = 1e9 + 7;

int mul(int a, int b) { return ((a % mod) * (b % mod)) % mod; }
int A(int n, int m)
{
    if (n < m)
        return 1;
    int tmp = 1;
    for (int i = 0; i < m; i++) {
        tmp = mul(tmp, n - i);
    }
    return tmp;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    cin >> n >> m >> pos;
    int l = 0;
    int r = n;
    int big = 0, small = 0;
    while (l < r) {
        int mid = (l + r) / 2;
        if (pos+1 >= mid) {
            big++;
            l = mid + 1;
            if(mid==pos) big--;
        } else {
            small++;
            r = mid;
            if(mid==pos) small--;
        }
        
    }
    int ans = 1;
    ans = mul(ans, A(m-1, small));
    ans = mul(ans, A(n - m, big));
    ans = mul(ans, A(n - big - small-1, n - big - small-1));
    cout<<ans;
}