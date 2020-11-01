#include <bits/stdc++.h>
using namespace std;
int high[20005];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> high[i];
    }
    sort(high, high + n, cmp);
    int sum = 0, ans = 0;
    while (sum < b) {
        sum += high[ans];
        ans++;
    }
    cout << ans;
    return 0;
}