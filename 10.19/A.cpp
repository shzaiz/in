#include <bits/stdc++.h>
using namespace std;
int dp[5] = {0,1,3,6,10};
void solve(){
    string s;cin>>s;
    int l = s.length();
    int f = s[0]-'0';
    int ans =0;
    ans+= (f-1)*10;
    ans+= dp[l];
    cout<<ans<<endl;
}
int main(){
    int T;cin>>T;while(T--) solve();
}