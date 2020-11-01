#include <bits/stdc++.h>
using namespace std;
int _a[100000];
int main()
{
    int t, n, a;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> a;
        memset(_a, 0, sizeof(_a));
        _a[0] = 1;
        int l = 1;
        for (int j = 2; j <= n; j++) {
            int w = 0;
            for (int k = 0; k < l; k++) {
                _a[k] = _a[k] * j + w;
                w = _a[k] / 10;
                _a[k] %= 10;
            }
            while (w > 0) {
                _a[l] = w % 10;
                l++;
                w /= 10;
            }
        }
        int sum = 0;
        for (int j = 0; j < l; j++)
            if (_a[j] == a)
                sum++;
        cout << sum << endl;
    }
}