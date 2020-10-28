// #include <bits/stdc++.h>
// using namespace std;
// #define N 75
// int a[N][N];
// int f[N][N][N][N];
// #define fo(i,n) for(int i =1;i<=(int)n;i++) 
// #define fo0(i,n)for(int i =0;i<=(int)n;i++) 
// int main(){
//     #ifdef FUCKCCF
//     freopen("D:/Testcases/in.ac","r",stdin);
//     freopen("D:/Testcases/out.ac","w",stdout);
//     #endif
//     int n,m,u;cin>>n>>m>>u; 
//     fo(i,n) fo(j,m) cin>>a[i][j];
//     fo(i,n+1) fo(j,n) fo0(k,n) fo0(l,n) f[i][j][k][l] = -998244353;
//     f[1][1][0][0] = 0; 
//     f[1][2][0][0] = 0;
//     fo(i,n)fo(j,m)fo0(k,(m/2))fo0(l,u-1){
//         // if(f[i][j][k][l] == -998244353) continue;
//         fo(x,j){
//             f[i][j][k][l] = max(f[i][j][k][l],f[i][x][k][l]);
//             if(k<=(m/2)){
//                 if(k==0)fo(df,u-1) f[i][j][0][df] = 0;
//                 f[i][j][k][(l+a[i][x])%u] = max(f[i][j][k][(l+a[i][x])%u],f[i][x][k-1][l]+a[i][x]); 
//             }
//         }
//         f[i+1][1][0][l] = max(f[i][j][k][l],f[i+1][1][0][l]);
//         printf("f[%d][%d][%d][%d] = %d.\n",i,j,k,l,f[i][j][k][l]);
//     }
//     printf("%d\n",f[n+1][1][0][0]);
// }

//
/*


Fuck ! Why this is std!!!???!

*/
//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=75;
int g[N][N];
int n,m,K;
int f[N][N][N][N];//
int main(){
    scanf("%d%d%d",&n,&m,&K);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        scanf("%d",&g[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int l=1;l<m/2&&l<=j;l++){
                for(int k=0;k<K;k++)
                {
                    f[i][j][l][k]=max(f[i][j-1][l][k],f[i][j][l][k]);
                    f[i][j][l-1][k]=max(f[i][j-1][l-1][k],f[i][j][l-1][k]);
               

                }
                for(int k=0;k<K;k++){
                    if((l==1&&k==0)||f[i][j-1][l-1][k]){
                        f[i][j][l][(k+g[i][j])%K]=max(f[i][j][l][(k+g[i][j])%K],f[i][j-1][l-1][k]+g[i][j]);
                    }
                }

            }
        }
        //转移到下一行
        for(int j=1;j<=m;j++)
            for(int k=0;k<K;k++)
                for(int l=0;l<=m/2&&l<=j;l++){
                    f[i+1][0][0][k]=max(f[i][j][l][k],f[i+1][0][0][k]);
                }
    }
    cout<<f[n+1][0][0][0];
}