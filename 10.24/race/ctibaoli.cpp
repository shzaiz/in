#include <bits/stdc++.h>
using namespace std;
#define N 100010

int a[21] = { 0, 1, 2, 4, 8, 16, 21, 42, 51, 102, 112, 224, 235, 470, 486, 972, 990, 1980, 2002, 4004, 4027 };
class dabiao {
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
#include<bits/stdc++.h>

using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
#endif
    int a[N], b[N];
    int mex[N];
    int n = 20;

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
            b[i-1] = bi;
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
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=n;j++){
            printf("%d ",a[j]-a[i]);
        }
        printf("\n");
    }
}