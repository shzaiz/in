#include <bits/stdc++.h>
using namespace std;
int a[10010], x = 1, n = 4;
bool bs()
{
    int left = 0;
    int right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (a[mid] < x) {
            left = mid + 1;
        } else
            right = mid;
    }
    if (left > 0 && a[left - 1] == x) {
        return 1;
    } else
        return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int ans = 0;
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    while (next_permutation(a, a + n)) {
        if (bs()==1)
            ans++;
    }
    printf("%d\n", ans);
}