#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100;
int a[maxn];
int b[maxn];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int Min1 = INT_MAX, Min2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            Min1 = min(a[i], Min1);
            Min2 = min(b[i], Min2);
        }
        unsigned long long ans = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i] - Min1;
            int y = b[i] - Min2;
            ans += max(x, y);
        }
        cout << ans << endl;
    }
}
