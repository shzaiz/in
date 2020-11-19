#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define mod 19260817
#define int long long
int a[N],n,k;
int s[30005][55];
signed main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>n>>k;
    fo(i,n) cin>>a[i];
    fo(i,n) s[0][i] = a[i];
    fo(i,n) s[1][i]=s[1][i-1]+s[0][i];
    fo_(i,2,k)fo(j,n){
        s[i][j]=(s[i][j-1]%mod+(s[i-1][j-1]%mod*s[0][j]%mod)%mod)%mod;
    }
    cout<< s[k][n]<<endl;
    return 0;
}