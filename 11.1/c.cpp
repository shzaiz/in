#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int x,int y){
    if(x%y != 0){
        cout<<x<<endl;
    }else {
        cout<<(x/__gcd(x,y))<<endl;
    }
}
signed main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int T;cin>>T;while(T--) {int x,y;cin>>x>>y;solve(x,y);}
    return 0;
}