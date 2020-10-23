#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 7;
int a[N];
signed main(){
    int t;
    scanf("%lld", &t);
    while (t--) {
        int n, mx = 0;
        scanf("%lld", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            mx = max(mx, a[i]);
        }
        int f = 1, lst = a[1];
        for (int i = 2; i <= n && f; ++i)
            if (a[i] != lst)
                f = 0;
        if (f) {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= n && !f; ++i)
            if (a[i] == mx && i != 1 && a[i - 1] < a[i]) {
                printf("%lld\n", i);
                f = 1;
            } else if (a[i] == mx && a[i + 1] != mx && i != n) {
                printf("%lld\n", i);
                f = 1;
            }

        for (int i = 1; i <= n; ++i)
            a[i] = 0;
    }

    return 0;
}