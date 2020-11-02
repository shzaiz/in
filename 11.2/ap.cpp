#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, x, tot1, tot2, l, r;
double a[100005], b[100005], y, z;
char c;
int main()
{
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c >> x;
        if (c == 'T')
            a[++tot1] = x;
        else
            b[++tot2] = x;
    }
    sort(a + 1, a + 1 + tot1);
    sort(b + 1, b + 1 + tot2);
    x = 1;
    l = 1;
    r = 1;
    for (int i = 1; i <= n; i++)
        if ((r > tot2 || (b[r] - y) * x + z >= a[l]) && (l <= tot1)) {
            if ((a[l] - z) / x + y > 1000)
                break;
            y += (a[l] - z) / x;
            z = a[l];
            x++;
            l++;
        } else {
            if (b[r] > 1000)
                break;
            z += (b[r] - y) * x;
            y = b[r];
            x++;
            r++;
        }
    cout << int((1000 - y) * x + z + 0.499999);
}