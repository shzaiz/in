#include<bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
#define N 405
int n,m;
char a[N][N];
int sum[N][N];
int main() {
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("stol.in","r",stdin);
    freopen("stol.out","w",stdout);
    #endif
    read(n),read(m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    
    for(int j=1;j<=m;j++) {
        for(int i=1;i<=n;i++) {
            sum[i][j]=sum[i-1][j]+(a[i][j]=='X');
        }
    }
    
    int ans=0;
    
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            int d=0;
            for(int k=1;k<=m;k++) {
                if(sum[j][k]-sum[i-1][k]) d=k;
                else ans=max(ans,(j-i+1+k-d)*2);
            }
        }
    }
    
    printf("%d",ans-1);
    
    return 0;
}