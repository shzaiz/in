#include <bits/stdc++.h>
using namespace std;
long long n, a1, a2, b1, b2, ans, go;
int main() {
    std::cin >> n >> a1 >> b1 >> a2 >> b2;
    long double x = b1 * 1.0 / a1, y = b2 * 1.0 / a2;
    if (x < y)
        std::swap(a1, a2), std::swap(b1, b2);
    ans = (n + a2 - 1) / a2 * b2;
    go = a2 / std::__gcd(a1, a2);
    for (long long i = go; i >= 0; i--) {
        long long t = i * b1;
        if (n - i * a1 >= 0)
            t = t + (n - i * a1 + a2 - 1) / a2 * b2;
        ans = std::min(ans, t);
    }
    std::cout << ans;
    return 0;
}
