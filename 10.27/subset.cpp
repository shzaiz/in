#include <bits/stdc++.h>
using namespace std;
#define N 75
int a[N][N];
int f[N][N][N][N];
#define fo(i,n) for(int i =1;i<=(int)n;i++) 
#define fo0(i,n)for(int i =0;i<=(int)n;i++) 
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int n,m,u;cin>>n>>m>>u; 
    fo(i,n) fo(j,m) cin>>a[i][j];
    fo(i,n+1) fo(j,n) fo0(k,n) fo0(l,n) f[i][j][k][l] = -998244353;
    f[1][1][0][0] = 0; 
    f[1][2][0][0] = 0;
    fo(i,n)fo(j,m)fo0(k,(m/2))fo0(l,u-1){
        // if(f[i][j][k][l] == -998244353) continue;
        fo(x,j){
            f[i][j][k][l] = max(f[i][j][k][l],f[i][x][k][l]);
            if(k<=(m/2)){
                if(k==0)fo(df,u-1) f[i][j][0][df] = 0;
                f[i][j][k][(l+a[i][x])%u] = max(f[i][j][k][(l+a[i][x])%u],f[i][x][k-1][l]+a[i][x]); 
            }
        }
        f[i+1][1][0][l] = max(f[i][j][k][l],f[i+1][1][0][l]);
        printf("f[%d][%d][%d][%d] = %d.\n",i,j,k,l,f[i][j][k][l]);
    }
    printf("%d\n",f[n+1][1][0][0]);
}