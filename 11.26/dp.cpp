#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
#define ll long long
#define maxn 110
#define mod 9999973


int n, m;
int C(int _){
    return _ * (_ - 1) / 2;
}
ll f[maxn][maxn][maxn];
int main(){
    cin >> n >> m;
    f[0][0][0] = 1;
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            for(int k = 0; j + k <= m; ++k)
                if(f[i][j][k]){
                    f[i + 1][j][k] = (f[i][j][k] + f[i + 1][j][k]) % mod;
                    if(j >= 1) f[i + 1][j - 1][k + 1] = (f[i + 1][j - 1][k + 1] + f[i][j][k] * j) % mod;
                    if((m - k - j) >= 1) f[i + 1][j + 1][k] = (f[i + 1][j + 1][k] + f[i][j][k] * (m - k - j)) % mod;
                    if(j >= 2) f[i + 1][j - 2][k + 2] = (f[i + 1][j - 2][k + 2] + f[i][j][k] * C(j)) % mod;
                    if((m - j - k) >= 2) f[i + 1][j + 2][k] = (f[i + 1][j + 2][k] + f[i][j][k] * C(m - j - k)) % mod;
                    if((m - k - j) >= 1 && j >= 1) f[i + 1][j][k + 1] = (f[i + 1][j][k + 1] + f[i][j][k] * (m - k -  j) * j) % mod;
                }
    ll ans = 0;
    for(int i = 0; i <= m; ++i){
        for(int j = 0; i + j <= m; ++j){
            ans = (ans + f[n][i][j]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
