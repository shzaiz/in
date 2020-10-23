#include <bits/stdc++.h>
using namespace std;
#define N 10010
int a[N] = {};
int dp[203][203][203];
int dist (int x, int y){
    if(x>y) swap(x,y);
    return a[y] - a[x];
}
int main(){
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int i=1,j=-1,k=0;
    memset(dp,8,sizeof(dp));
    for(i = 1 ; i<n;i++){
        for(j = k;j<=i;j++){
            for(int k = 1;k<=m;k++){
                dp[i+1][i][k] = min((dp[i][j][k]+dist(i,i+1)),dp[i+1][i][k]);
                dp[i+1][j][k] = min((dp[i][j][k]+dist(j,i+1)),dp[i+1][j][k]);
            }
        }
    }
    int ans  = 0;
    for(int i = 1;i<=n;i++){
        ans = min(ans, dp[n][i][m]);
    }
    cout<<ans<<endl;


}
