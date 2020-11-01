#include <iostream>
using namespace std;
long long n, x = 0, str = 0, ss = 1, i = 2, t = 1;
int a[10001] = {};
int s[10001] = {};
void jia(int x)
{
    for (int i = 1; i <= t; i++) {
        s[i] = s[i] * x;
    }
    for (int i = 1; i <= t; i++) {
        if (s[i] >= 10) {
            long long add = s[i] / 10;
            s[i + 1] += add;
            s[i] = s[i] % 10;
            if (i + 1 > t)
                t = i + 1;
        }
    }
}
int main()
{
    s[1] = 1;
    cin >> n;
    while (str < n) {
        a[++x] = i;
        str += i;
        i++;
    }
    a[str - n - 1] = 0;
    for (int i = 1; i <= x; i++) {
        if (a[i] != 0)
            cout << a[i] << ' ';
        if (a[i] != 0)
            jia(a[i]);
    }
    cout << endl;
    for (int i = t; i >= 1; i--)
        cout << s[i];
    cout << endl;
    return 0;
}