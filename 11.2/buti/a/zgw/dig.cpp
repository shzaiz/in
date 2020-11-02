#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
#define ll long long
int S[N], T[N], n, m, bn, an;
#define D double
const D eps = 1e-5;
char s[10];
int main()
{
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("dig.in","r",stdin);
    freopen("dig.out","w",stdout);
    #endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int t;
        cin >> t;
        if (s[0] == 'T')
            T[++bn] = t;
        else {
            if (t < m)
                S[++an] = t;
        }
    }
    sort(S + 1, S + 1 + an);
    sort(T + 1, T + 1 + bn);
    int i = 1, j = 1;
    D pos = 0, ans = 0;
    while (i <= an && j <= bn) {
        D sp = (1.0 / (D)(i + j - 1));
        D at = ((D)S[i] - pos) * (i + j - 1) + ans;
        if (at < (D)(T[j])) {
            pos = S[i++];
            ans = at;
        } else {
            pos += sp * ((D)T[j] - ans);
            if (pos + eps > m)
                break;
            ans = (D)T[j++];
        }
    }
    while (i <= an && (pos + eps) <= m) {
        ans += ((D)S[i] - pos) * (D)(i + j - 1);
        pos = S[i++];
    }
    while (j <= bn && (pos + eps) <= m) {
        pos += (1.0 / (D)(i + j - 1)) * ((D)T[j] - ans);
        ans = (D)T[j++];
    }
    if (pos + eps <= m)
        ans += (D)(m - pos) * (D)(i + j - 1);
    printf("%lld\n", (ll)(ans + eps));
    return 0;
}