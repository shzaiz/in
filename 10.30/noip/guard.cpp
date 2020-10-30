#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define D double
#define fo(i,x) for(int i = 1;i<=(x);i++)
#define fo0(i,x) for(int i = 0;i<=(x);i++)
#define fo2(i,x) for(int i = 2;i<=(x);i++)
int n,l,k;
D p[N];int a[N];
D f[500][500][500];
int sum = 0;
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    #endif
    cin>>n>>l>>k;
    fo(i,n) {cin>>p[i];p[i]/=100;} 
    fo(i,n) {cin>>a[i];if(a[i]!=-1) sum+=a[i];}
    f[1][0][k]  =1;
    fo(i,n-1) fo0(j,i) fo0(k,sum){
        f[i+1][j][k] += ((D)1-p[i])*f[i][j][k];
        if(a[i]!=-1)f[i+1][j+1][k+a[i]] += p[i]*f[i][j][k];
        else f[i+1][j+1][k-1] += p[i]*f[i][j][k];
    }
    D ans = 0;
    for(int i = l;i<=n;i++) fo0(j,sum){
        ans+= f[n][i][j];
    }
    cout<<ans;
    
}
