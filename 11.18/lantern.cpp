#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 1000
int n,m;
int a[N],f[N][N],h[N][N];
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>n>>m;
    fo(i,n) cin>>a[i];
    a[n+1] = 2e9; a[0] = -2e9;
    fo_(i,0,n) fo_(j,i,n+1) fo_(k,i,j) h[i][j]+= min(a[k]-a[i],a[j]-a[k]);
    memset(f,0x3f,sizeof f);
    f[0][0] = 0;
    fo(i,n) fo(k,m) fo_(j,0,i-1) f[i][k] = min(f[i][k], f[j][k-1]+h[j][i]);
    int ans = 2e9;
    fo(i,n) ans = min(ans,f[i][m]+h[i][n+1]);
    cout<<ans;
    return 0;
}