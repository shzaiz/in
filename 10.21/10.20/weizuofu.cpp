#include <bits/stdc++.h>
#define fint register int
#define h 5001
#define N 364578
using namespace std;
const double gd = (sqrt(5) + 1) / 2;
string ans[] = { "lyfx yyds!", "xbz yyds!" };
int f[N], vis[N], sg[N];
inline string dos_a(int a, int b)
{
    return ans[!(sg[a] ^ sg[b])];
}

inline string dos_b(int a, int b)
{
    if (a < b)
        swap(a, b);
    return ans[b == (int)((a - b) * (double)gd)];
}

inline void pre(int n)
{
    for (fint i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        for (fint j = 1; f[j] <= i && j <= n; j++)
            vis[sg[i - f[j]]] = 1; 
        for (fint j = 0;; j++)
            if (!vis[j]) {
                sg[i] = j;
                break;
            }
    }
    return;
}
int main()
{
    int T;
    cin >> T;
    memset(sg, -1, sizeof(sg));
    f[1] = 1, f[2] = 1;
    for (fint i = 3; i <= 100; i++)
        f[i] = f[i - 1] + f[i - 2];
    pre(10010);
    for (fint i = 1; i <= T; i++) {
        int a, b;
        cin >> a >> b;
        if (i & 1)
            cout << dos_a(a, b);
        else
            cout << dos_b(a, b);
        cout << endl;
    }
    return 0;
}

