#include <bits/stdc++.h>
using namespace std;
int dp[5] = {0,1,3,6,10};
void solve(){
    int n,k;cin>>n>>k;
    int ans = 0;
    while(n--){
        int sb;cin>>sb;
        ans+=sb;
    }
    if(ans==k) printf("YES\n");
    else printf("NO\n");
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
    int T;cin>>T;
    while(T--) solve();
}