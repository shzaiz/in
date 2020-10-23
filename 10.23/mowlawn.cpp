#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
ll n,k,x,s[maxn],f[maxn],ans,q[maxn],tp,bk;
ll max(ll a,ll b){
    return a>b?a:b;
}
void add(ll x){
    while(tp<bk&&f[q[bk]-1]-s[q[bk]]<f[x-1]-s[x])
        bk--;
    q[++bk]=x;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("mowlawn.in","r",stdin);
    freopen("mowlawn.out","w",stdout);
    #endif
    // int n,_k;
    // cin>>n>>_k;
    // for(int i = 1;i<=n;i++){
    //     cin>>a[i];
    // }
    // f[1][0] = 0;f[1][1] = a[1];
    // for(int i =2;i<=n;i++){
    //     for(int j = 1;j<=n;j++){
    //         f[i][j] = max(f[i][j],f[i-1][j-1]+a[i]);
    //         for(int k = 0;k<=n;k++){
    //             f[i][0] = max(f[i-1][k],f[i][0]);
    //         }
    //     }
    // }
    // printf("%d\n", f[n][_k]);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x;s[i]=s[i-1]+x;
    }
    add(1);
    for(int i=1;i<=n;i++){
        if(i-q[tp]>k)tp++;
        ll p=q[tp];
        f[i]=f[p-1]+s[i]-s[p];
        ans=max(ans,f[i]);
        add(i+1);
    }
    cout<<ans<<endl;
    return 0;    
}