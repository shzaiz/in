#include <bits/stdc++.h>
using namespace std;
#define N 1005
char ch[N][N];
int solve(){
    int n;cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>ch[i][j];
        }
    }
    int cnt0=0,cnt1=0;
    int a = ch[1][2]-'0';
    if(a==0) cnt0++; else cnt1++;
    int b = ch[2][1]-'0';
    if(b==0) cnt0++; else cnt1++;
    int c = ch[n][n-1]-'0';
    if(c==0) cnt0++; else cnt1++;
    int d = ch[n-1][n]-'0';
    if(d==0) cnt0++; else cnt1++;
    // printf("%d %d %d %d\n", a, b, c, d);
    if(a==b && b!=c && c==d) {printf("0\n");return 0;}
    if(a!=b && c!=d) {
        printf("2\n");
        printf("1 2\n");
        if(c==b) printf("%d %d\n",n,n-1);
        else printf("%d %d\n",n-1,n);
        return 0;
    }
    if((a==b && c!=d)|| (a!=b &&c==d)){ 
        printf("1\n");
        if(cnt0>cnt1){
            if(a==1) printf("2 1\n");
            if(b==1) printf("1 2\n");
            if(c==1) printf("%d %d\n",n-1,n);
            if(d==1) printf("%d %d\n",n,n-1);
        }else{
            if(a==0) printf("2 1\n");
            if(b==0) printf("1 2\n");
            if(c==0) printf("%d %d\n",n-1,n);
            if(d==0) printf("%d %d\n",n,n-1);
        }
        return 0;
    }
    if(a==b && b==c && c==d){
        printf("2\n");
        printf("1 2\n");
        printf("2 1\n");
        return 0;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
    int T;cin>>T;while(T--) solve();
}