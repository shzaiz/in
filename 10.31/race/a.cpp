#include <bits/stdc++.h>
using namespace std;
#define N 5005
int a[N],b[N],c[N];
int h,n;
int dp[2][N];
#define maxx(x,y) x = max(x,y)
#define fo(i,x) for(int i = 1;i<=(x);i++)
#define fo2(i,a,x) for(int i = a;i<=(x);i++)
#define rep(i,a,x) for(int i =(x);i>=(a);i--)
// int dfs(int i,int cap){
//     if(i==n) return 0;
//     return dfs(i+1,cap-a[i])
// }

int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>n>>h;
    fo(i,n) cin>>a[i];
    fo(i,n) cin>>b[i];
    fo(i,n) c[i] = a[i]-b[i];
    fo(i,n) rep(j,c[i],h){
        //  printf("%d %d\n",i,j);
        if(j-a[i]<0) {dp[i&1][j]=max(dp[(i-1)&1][j],dp[(i)&1][j]);} 
        else dp[i&1][j] = max(dp[(i-1)&1][j],dp[(i-1)&1][j-c[i]]+1);
        // printf("dp[%d][%d] = %d , dp[%d][%d] = dp[%d][%d] =%d \n",i,j,dp[i&1][j],(i)&1,j-a[i]+b[i],(i)&1,j,dp[(i)&1][j]);
    }
    printf("%d\n",dp[n&1][h]);
    return 0;
}