#include <bits/stdc++.h>
using namespace std; 
#define N 100010
#define int long long
#define mod 998244353
int a[N],b[N];
int add(int a,int b){
    return ((a%mod)+(b%mod))%mod;
}
int mul(int a,int b){
    return ((a%mod)*(b%mod))%mod;
}int mu(int a,int b){
    return ((a%mod)-(b%mod)+mod)%mod;
}
signed main(){
    int ans = 0;
    freopen("10.6/wa1.in","r",stdin);
    freopen("10.6/wa1.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    for(int i =1;i<=q;i++){
        ans = 0;
        int op;cin>>op;
        
        if(op==2) {
            int p,x,y;cin>>p>>x>>y;
            a[p] =x;b[p] =y;
        }else{
            int x,y;cin>>x;cin>>y;
            for(int i = x;i<y;i++){
                for(int j = i+1;j<=y;j++){
                    int v1 = mul(a[i],b[j]);
                    int v2 = mul(a[j],b[i]);
                    int subst  = mu(v1,v2);
                    int subst2 = mul(subst,subst);
                   ans = add(ans,subst2);

                    // ans = add(ans,(a[i]*b[j]-a[j]*b[i])*(a[i]*b[j]-a[j]*b[i]));
                }
            }
            cout<<(ans)%mod<<endl; 
        }
        
    }
    return 0;
}