#include <cmath>
#include <iostream>
using namespace std;
int a[31], i = 0, j;
long long s = 0;
int main()
{
    while (cin >> a[i++])
        ;
    for (j = 0; j < i; j++) {
        s += a[j];
    }
    s *= pow(2, i - 2);
    cout << s;
    return 0;
}
