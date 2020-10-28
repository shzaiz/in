//1437C - Chef Monocarp
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n;
int t[N];
int dp[505][505];
void solve(){
    for(int i = 0;i<505;i++) for(int j = 0;j<505;j++) dp[i][j] = 998244353;
    dp[0][0] = 0;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>t[i];
    }
    sort(t,t+n);
    for(int i = 0;i<=205;i++){dp[i][0] = 0;}
    for(int i = 1;i<=2*n+1;i++){
        for(int j  =1;j<=n;j++){
            dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]+abs(i-t[j-1]));
        }
    }
    cout<<dp[2*n][n]<<endl;
}
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int T;cin>>T;while(T--) solve();
    
}