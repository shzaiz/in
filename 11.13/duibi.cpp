#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define int long long
void exgcd(int a,int b ,int &x,int &y){
    if(b==0) {x = 1, y = 0;return;}
    exgcd(b,a%b,x,y);
    int z = x;x = y,y = z-y*(a/b);
}
int n, a[16],m[16],Mi[16],mu =1,ans;
signed main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>n;
    fo(i,n){
        int x;cin>>x;m[i] = x;
        mu*=x;
        cin>>a[i];
    }
    fo(i,n){
        Mi[i] = mu/m[i];
        int x = 0, y = 0;
        exgcd(Mi[i],m[i],x,y);
        int inv = (x<0?x+m[i]:x);
        ans += a[i]*Mi[i]*inv;
        // cout<<x<<" "<<y<<endl;
    }
    cout<<ans%mu<<endl;
    return 0;
}