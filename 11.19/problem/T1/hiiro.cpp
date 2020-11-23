#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i  =  1;i<= n;i++)
#define fo_(i,b,n) for(int i  =  b;i<= n;i++)
#define re(i,n,b) for(int i  =  n;i>b;i--)
#define N 200005
#define DD 998244353
#define __ long long
#define sgn signed
#define main main
#define rtn  return
#define inn cin
#define a >>
#define ot cout
#define aa  <<
__ anti[200005],n,k;
__ dp[55][200005];
__ add(__ n,__ k){ rtn ((n % DD)  + (k % DD)) % DD;}
__ mul(__ n,__ k){ rtn  (n % DD  * k % DD) % DD;}
sgn main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    inn a n a k;
    fo(i,n) inn a anti[i];
    fo(i,n) dp[0][i]  =  anti[i];
    fo(i,n) dp[1][i] =  add(dp[1][i-1],dp[0][i]);
    fo_(i,2,k)fo(j,n){
        dp[i][j] =  add(dp[i][j-1],mul(dp[i-1][j-1],dp[0][j]));
    }
    ot aa  dp[k][n];
    rtn (0^0);
}