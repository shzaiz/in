#include <bits/stdc++.h>
using namespace std;
#define fo(i, x) for (int i = 1; i <= x; i++)
#define fo_(i, b, x) for (int i = b; i <= x; i++)
#define re(i, x, b) for (int i = x; i > b; i--)
#define N 10010
int n,a[N],m[N],b[N],s[N],ans[N],j,t,k;
int main()
{
    int i;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (i = 1; i <= n; i++) {
        m[i] = min(a[i], b[i]);
        s[i] = i;
    }
    for (i = 1; i <= n - 1; i++)
        for (j = i + 1; j <= n; j++)
            if (m[i] > m[j]) {
                swap(m[i], m[j]);
                swap(s[i], s[j]);
            }
    k = 0;
    t = n + 1;
    for (i = 1; i <= n; i++)
        if (m[i] == a[s[i]]) {
            k++;
            ans[k] = s[i];
        } else {
            t--;
            ans[t] = s[i];
        }
    k = 0;
    t = 0;
    for (i = 1; i <= n; i++) {
        k += a[ans[i]];
        if (t < k)
            t = k;
        t += b[ans[i]];
    }
    cout << t << endl;
    for (i = 1; i <= n; i++) {
        cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}