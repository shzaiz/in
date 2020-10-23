#include <bits/stdc++.h>
#define fint register int
#define N 347598
#define int long long
using namespace std;
const int mods = 1e9 + 7;
const int mods2 = 998244353;
int a[N], b[N];
inline int gcd(int a, int b);
inline int fpow(int b, int pp, int k);
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    #endif
    int n, q;
    cin >> n >> q;
    for (fint i = 1; i <= n; i++)
        cin >> a[i];
    for (fint i = 1; i <= n; i++)
        cin >> b[i];
    while (q--) {
        int op;
        cin >> op;
        int i, x, y, p, l, r, ll, rr;
        if (op == 1)
            cin >> i >> x >> y, a[i] = x, b[i] = y;
        if (op == 2) {
            //1
            cin >> p >> l >> r >> ll >> rr;
            int aa = 0, bb = 0;
            for (fint i = l; i <= r; i++)
                for (fint j = i+1; j <= r; j++)
                    aa += (a[i] * b[j] - a[j] * b[i]) * (a[i] * b[j] - a[j] * b[i]), aa %= mods;
            for (fint i = ll; i <= rr; i++)
                for (fint j = i+1; j <= rr; j++)
                    bb += (a[i] * b[j] - a[j] * b[i]) * (a[i] * b[j] - a[j] * b[i]), bb %= mods;
            cout << fpow(p, gcd(aa*2LL, bb*2LL), mods2) - 1 << endl;
            //2 
            
        }
    }
}

inline int fpow(int b, int pp, int k)
{
    int ans = 1;
    while (pp) {
        if (pp & 1LL)
            ans = ans * b % k;
        b = b * b % k;
        pp >>= 1LL;
    }
    return ans;
}

inline int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}