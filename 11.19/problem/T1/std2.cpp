#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 200005
#define mod 19260817
#define int long long
int a[200005],n,k;
int s[55][200005];
int add(int x,int y){return (x%mod+y%mod)%mod;}
int mul(int x,int y){return (x%mod*y%mod)%mod;}
signed main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>n>>k;
    fo(i,n) cin>>a[i];
    fo(i,n) s[0][i] = a[i];
    fo(i,n) s[1][i]=add(s[1][i-1],s[0][i]);
    fo_(i,2,k)fo(j,n){
        s[i][j]=add(s[i][j-1],mul(s[i-1][j-1],s[0][j]));
    }
    cout<< s[k][n]<<endl;
    return 0;
}