#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
int add(int a,int b){return (a%mod+b%mod)%mod;}
int mul(int a,int b){return (a%mod*b%mod)%mod;}
int sub(int a,int b){return (a%mod-b%mod+mod)%mod;}
int inv2=mod-mod/2;
signed main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int A,B,C;cin>>A>>B>>C;
    int ans1 = mul(add(1,A),sub(A,0));
    ans1=mul(ans1,inv2);
    int ans2 = mul(add(1,B),sub(B,0));
    ans2=mul(ans2,inv2);
    int ans3 = mul(add(1,C),sub(C,0));
    ans3=mul(ans3,inv2);
    int ans = mul(mul(ans1,ans2),ans3);
    cout<<ans;
    return 0;
}
