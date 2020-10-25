#include <bits/stdc++.h>
using namespace std;
int n;
    
void oushu(){
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(j==i || j==n-i+1) printf("1 " );
            else printf("0 ");
        }
        printf("\n");
    }
}
void jishu(){
    int a[105][105];
    memset(a,0,sizeof a);
    for(int i = 1;i<=n;i++){
        a[i][i] = 1;
        a[i+1==n?n:(i+1)%n][i] = 6;
    }
    for(int i  =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}
void solve(){
    cin>>n;
    if(n%2==0) oushu();
    else jishu();
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
    int T;cin>>T;while(T--) solve();
    
}