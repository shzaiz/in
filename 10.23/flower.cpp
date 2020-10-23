#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define int unsigned long long
struct C{
    int id,t,d;
}a[N];
int n,ans,S;
bool cmp(C x, C y){
    // if(x.t<y.t){
    //     return true;
    // }else if(x.t>y.t){
    //     return false;
    // }else if(x.t==y.t){
    //     if(x.d<y.d){
    //         return false;
    //     }else return true;
    // }
    return x.t*y.d<x.d*y.t;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].t;
        cin>>a[i].d;
        S+=a[i].d;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        S-=a[i].d;
        ans+=2*S*a[i].t;
    }
    cout<<ans;
    return 0;
}