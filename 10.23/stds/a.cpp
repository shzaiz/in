#include <bits/stdc++.h>
#define maxn 100010
#define int long long
using namespace std;
int n,ans,S;
struct C{
    int t,d;
}a[maxn];
int cmp(const C &x,const C &y){
    return x.t*y.d<x.d*y.t;
}
signed main(){
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
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