#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
int N,K;
int f(int x){if(x<2 || x>(2*N)) return 0; if(x>N+1) return 2*N-x+1;else return x-1;}
signed main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    
    cin>>N>>K;
    int ans = 0;
    for(int i = 0;i<=2*N+1;i++){
        int tmp = f(i)*f(i-K);
        ans+= (tmp);
        // printf("%lld %lld %lld\n",i,i-K,ans);
        // printf("%lld %lld %lld\n",f(i),f(i-K),ans);
        // printf("\n");
    }
    cout<<ans;
    return 0;
}