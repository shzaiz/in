// 所谓闭包,就是直接相关系的一些内容.
// 可以用Floyd轻松维护.

#include <bits/stdc++.h>
using namespace std;
#define N 300
int g[N][N];
int main(){
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int x,y;cin>>x>>y;
        g[x][y] = 1;
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                g[i][j] |= (g[i][k]&g[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        int a = 1;
        for(int j = 1;j<=n;j++){
            if(i==j){continue;}
            else a = a&& (g[i][j] || g[j][i] );
        }
        ans+=a;
    }
    cout<<ans;
    return 0;
}