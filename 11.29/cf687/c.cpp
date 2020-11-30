#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 100100
int n,p,k;
char a[N];
int x,y;
void solve(){
    cin>>n>>p>>k>>a>>x>>y;
    int ans = 1e9;
    fo_(i,0,n-p){
        int bans = y*(i);
        for(int j = i+p-1;j<n;j+=k){
            if(a[j]=='0') bans+= x;
        }
        ans = min(bans, ans);
    }
    cout<<ans<<endl;
}
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int T;cin>>T;while(T--) solve();
    return 0;
}