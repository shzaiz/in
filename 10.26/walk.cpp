//  main.cpp
//  T@
//不知道对不对,但是的确会被特殊数据卡成n^2的
//  Created by mac on 2020/10/26.
#include <bits/stdc++.h>
using namespace std;
long double dp[500001];
long double wei[500002];
long double l, a, t, b, r;
long double maxx = 1e9 + 1;
long double fen1, fen2;
long double x;
long long n;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("walk.in"   ,"r",stdin);
    freopen("walk.out   ","w",stdout);
    #endif
    cin >> l >> a >> b >> t >> r;
    cin >> n;
    fen1 = a * t;
    fen2 = a * t + b * r;
    for (int i = 1; i <= n + 1; i++)
        dp[i] = maxx;
    for (int i = 1; i <= n; i++)
        cin >> wei[i];
    wei[n + 1] = l;
    dp[1] = wei[1] / a;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n + 1; j++) {
            x = wei[j] - wei[i];
            if (x >= fen2) {
                dp[j] = min(dp[j], dp[i] + r + (x - b * r) / a);
                break;
            }
            if (x < fen2 && x > fen1) {
                dp[j] = min(dp[j], dp[i] + t + (x - a * t) / b);
                continue;
            }
            if (x <= fen1)
                dp[j] = min(dp[j], dp[i] + x / a);
        }
    printf("%Lf", dp[n + 1]);
}
