#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int solve(){
    int q,a,b,p;
    cin>>q>>a>>b>>p;
    int x = __gcd(a,b);
    cout<<(qpow(q,x,p)+p-1)%p<<endl;
}
signed main() {
    // freopen("10.6/wa1.in","r",stdin);
    // freopen("10.6/wa1.out","w",stdout);
    int T;cin>>T;while(T--) {solve();}
}