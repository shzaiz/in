#include <bits/stdc++.h>
using namespace std;
#define it map<int, pair<int, int> >::iterator
#define fi first
#define se second
#define mp make_pair
#define N 100010
map<int, pair<int, int> > s;
int t, n;
int a[100], b[10000], cnt;
// int a[21] = { 0, 1, 2, 4, 8, 16, 21, 42, 51, 102, 112, 224, 235, 470, 486, 972, 990, 1980, 2002, 4004, 4027 };
class dabiao {
    int a[N], b[N];
    int mex[N];
    int n = 20;
    int mian()
    {
        a[1] = 1;
        a[2] = 2;
        for (int i = 3; i <= n; i++) {
            if (i % 2 == 1) {
                a[i] = 2 * a[i - 1];
            } else {
                memset(mex, 0, sizeof(mex));
                for (int j = 1; j <= i - 1; j++) {
                    for (int k = 1; k <= i - 1; k++) {
                        mex[abs(a[j] - a[k])]++;
                    }
                }
                int bi;
                for (int j = 0; j <= 1000000; j++) {
                    if (mex[j] == 0) {
                        bi = j;
                        break;
                    }
                }
                a[i] = a[i - 1] + bi;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ",";
        }
    }
};
void solve()
{
    int x;
    cin >> x;
    for (int i = 1; i < 20; i++) {
        for (int j = i + 1; j <= 20; j++) {
            // printf("%d %d\n", a[i], a[j]);
            if (a[j] - a[i] == x) {
                printf("%d %d\n", j, i);
                return;
            }
        }
    }
}
void zhengjiesolve()
{
    int x;
    scanf("%d", &x);
    it i = s.find(x);
    if (i != s.end()) {
        cout<<(i->se.fi)<<" "<<(i->se.se)<<"\n";
    } else {
        int y = lower_bound(b + 1, b + cnt + 1, x) - b - 1;
        cout<<(n + (x - y) * 2)<<" "<<(n + (x - y) * 2 - 1)<<"\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
#endif
    a[1] = 1, a[2] = 2;
    s[1] = mp(2, 1);
    for (n = 3;; n++) {
        if (n %2== 1)
            a[n] = a[n - 1] * 2;
        else {
            for (int j = 1;; j++) {
                if (!s.count(j)) {
                    a[n] = a[n - 1] + j;
                    break;
                }
            }
        }
        for (int j = 1; j < n; j++) {
            s[a[n] - a[j]] = mp(n, j);
        }
        if ((!(n & 1)) && a[n] > 1000000000)
            break;
    }
    for (it i = s.begin(); i != s.end(); i++) {
        b[++cnt] = i->fi;
    }
    cin >> t;
    while (t--) {
        zhengjiesolve();
    }
}