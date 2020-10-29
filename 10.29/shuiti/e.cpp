#include <iostream>
using namespace std;
int n, ans = 1;
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        ans += 1;
        ans *= 2;
    }
    cout << ans << endl;
}