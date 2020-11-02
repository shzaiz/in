#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N, s[12], b[12], mi = 2000000001;
int main()
{
#ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &s[i], &b[i]);
    for (int i = 1; i < (1 << N); i++) {
        int S = 1, B = 0;
        for (int j = 0; j < N; j++)
            if ((i >> j) & 1) {
                S *= s[j];
                B += b[j];
            }
        mi = min(mi, abs(S - B));
    }
    printf("%d", mi);
    return 0;
}