#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
void solve(){
int n,m,r,c;
    cin>>n>>m>>r>>c;
    int xt = max(n-r,r-1);
    int yt = max(m-c,c-1);
    cout<<xt+yt<<endl;
}
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int T;cin>>T;while(T--) solve();
    return 0;
}