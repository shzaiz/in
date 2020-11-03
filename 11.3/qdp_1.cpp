#include <bits/stdc++.h>
using namespace std;
#define N 105
int n,m,t,dp[3][N][5998][3];
#define fo(i,x) for(register int i = 1;i<=(x);i++)
bool col[N][N];
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        char c[N];
        scanf("%s",c+1);
        for(int j=1;j<=m;j++)
            col[i][j]=c[j]-'0';
    }
    fo(i,n) fo(j,m) fo(k,t){
        if(j==1){
            dp[i&1][j][k][0]=max(dp[(i-1)&1][m][k][1],dp[(i-1)&1][m][k][0]);
            dp[i&1][j][k][0]=max(dp[i&1][j][k][0],dp[(i-1)&1][m][k][2]);
            dp[i&1][j][k][1]=max(dp[(i-1)&1][m][k-1][1],dp[(i-1)&1][m][k-1][0]);
            dp[i&1][j][k][1]=max(dp[i&1][j][k][1],dp[(i-1)&1][m][k-1][2]);
            dp[i&1][j][k][2]=max(dp[(i-1)&1][m][k-1][1],dp[(i-1)&1][m][k-1][0])+1;
            dp[i&1][j][k][2]=max(dp[i&1][j][k][2],dp[(i-1)&1][m][k-1][2]+1);
        }else{
            if(col[i][j] == col[i][j-1]){
                dp[i&1][j][k][2]=dp[i&1][j-1][k][2]+1;
                dp[i&1][j][k][1]=max(dp[i&1][j-1][k][1],dp[i&1][j-1][k-1][0]);
                dp[i&1][j][k][0]=max(dp[i&1][j-1][k][0],dp[i&1][j-1][k][1]);
            }else{
                dp[i&1][j][k][2]=max(dp[i&1][j-1][k][1],dp[i&1][j-1][k-1][0])+1;
                dp[i&1][j][k][2]=max(dp[i&1][j-1][k-1][2]+1,dp[i&1][j][k][2]);
                dp[i&1][j][k][1]=max(dp[i&1][j-1][k][2],dp[i&1][j-1][k-1][0]);
                dp[i&1][j][k][0]=max(dp[i&1][j-1][k][0],dp[i&1][j-1][k][2]);
            }
        }
    }
    printf("%d",max(max(dp[n&1][m][t][0],dp[n&1][m][t][1]),dp[n&1][m][t][2]));
    return 0;
}