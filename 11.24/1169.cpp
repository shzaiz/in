#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 1001
#define left lefffgff
#define right erfsrfsdfds

using namespace std;
int up[N][N],left[N][N],right[N][N],ansa,ansb,a[N][N],m,n;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            up[i][j]=1,left[i][j]=j,right[i][j]=j,scanf("%d",&a[i][j]);
            
    for(int i=1;i<=n;i++)
        for(int j=2;j<=m;j++)
            if(a[i][j]^a[i][j-1])
                left[i][j]=left[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=m;j>1;j--)
            if(a[i][j]^a[i][j-1])
                right[i][j-1]=right[i][j];
                
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(i>1&&a[i][j]^a[i-1][j])
                up[i][j]=up[i-1][j]+1,left[i][j]=max(left[i][j],left[i-1][j]),right[i][j]=min(right[i][j],right[i-1][j]);
            int a=right[i][j]-left[i][j]+1;
            int b=min(a,up[i][j]);
            ansa=max(ansa,b*b);
            ansb=max(ansb,a*up[i][j]);
        }
    printf("%d\n%d",ansa,ansb);
} 