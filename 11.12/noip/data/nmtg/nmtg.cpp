#include<iostream>
#include<cstdio>
using namespace std;
int N, M; long long ans, C[1000010][4];
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main()
{
	freopen("nmtg.in", "r", stdin);
	freopen("nmtg.out", "w", stdout);
    cin >> N >> M; ++N; ++M;
    for(int i = 0; i <= N*M; ++i)
    {
        C[i][0] = 1;
        for(int j = 1; j <= min(3, i); ++j)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
    ans = C[N*M][3] - N * C[M][3] - M * C[N][3];
    for(int i = 1; i < N; ++i)
        for(int j = 1; j < M; ++j)
            ans -= 2 * (gcd(i, j) - 1) * (N - i) * (M - j);
    cout << ans << endl;
    return 0;
}
