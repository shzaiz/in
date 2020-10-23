#include <bits/stdc++.h>
using namespace std;
void solve(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int dx = abs(x2-x1); int dy = abs(y2-y1);
    int ans = dx+dy;
    if(dy==0 || dx==0) {printf("%d\n",ans);}
    else{
        printf("%d\n",ans+2);
    }


}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    #endif
    int T;cin>>T;while(T--) solve();
}