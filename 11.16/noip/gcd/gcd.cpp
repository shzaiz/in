#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(register int i = 1;i<=x;++i)
#define fo_(i,b,x) for(register int i = b;i<=x;++i)
#define re(i,x) for(register int i = x;i;i--)
#define N 500005
class subtsk{
    // int b[N][N];
    // int a[N];
    // int n,k;
    // int mian(){
    //     #ifdef XBZAKIOI
    //     freopen("D:/Testcases/in.ac","r",stdin);
    //     freopen("D:/Testcases/out.ac","w",stdout);
    //     #endif
    //     cin>>n>>k;
    //     fo(i,n) cin>>a[i],b[i][1]=a[i];
    //     fo(i,n) fo(j,min(k,i)){
    //         b[i][j] = max(b[i-1][j],__gcd(b[i-1][j-1],a[i]));
    //     }
    //     cout<<b[n][k]*k;

    // }
};
int n,k;
int b[500005];
bool ok(int x){
    int sum=0;
    for(register int i=1;x*i<=500000; ++i)sum+=b[x*i];
    if(sum>=k) return 1;
    return 0;
}
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    #endif
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        ++b[x];
    }
    re(i,500000){
        if(ok(i)){
            cout<<i*k<<endl;
            return 0;
        }
    }
    return 0;
}