#include <bits/stdc++.h>
using namespace std;
#define int long double
signed main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("pour.in","r",stdin);
    freopen("pour.out","w",stdout);
    #endif
    int a,b;cin>>a>>b;
    if(a<b) swap(a,b);
    cout<<(b*ceil(a/b)-a)<<endl<<1<<" "<<(ceil(a/b));
}