#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
int n,k;
int a[N];
int colorto(int c){
    int cnt = 0;
    fo(i,n) {
        if(a[i]!=c) cnt++, i+=(k-1);
    }
    return cnt;
}
void solve(){
    cin>>n>>k;
    fo(i,n) cin>>a[i];
    int ans = 1e8;
    fo(i,100){
        ans = min(ans,colorto(i));
    }
    cout<<ans<<endl;
}
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int T;cin>>T;
    while(T--) solve();
    

}