#include <bits/stdc++.h>
#define N 100010
using namespace std;
#define int long long
int phi(int n){
    int ret=1,i;
    for (i=2;i*i<=n;i++)
        if (n%i==0){
            n/=i,ret*=i-1;
            while (n%i==0)
                n/=i,ret*=i;
        }
    if (n>1)
        ret*=n-1;
    return ret;
}
int qpow(int a,int x,int mod){
  int ans=1,base=a;
  while(x>0){
  	if(x%2==1)
  	  ans=(ans*base)%mod;
  	base=(base*base)%mod;
  	x/=2;
  }
  return ans;
}
int qp(int base,int pow,int mod){
    int pw = pow%phi(mod)+phi(mod);
    qpow(base,pw,mod);
}
void solve(){
    int q,a,b,p;cin>>q>>a>>b>>p;
    int A = ((qp(q,a,p)+p-1))%p;int B = (qp(q,b,p)+p-1)%p;
    cout<<A<<" " <<B<<" "<<" "<<__gcd(A,B)<<endl;
}
signed main(){
    freopen("10.6/wa1.in","r",stdin);
    freopen("10.6/wa1.out","w",stdout);
    int T;cin>>T;while (T--) solve();
    return 0;
}