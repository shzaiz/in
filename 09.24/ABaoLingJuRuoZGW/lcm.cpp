#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M =  246913578;
const ll MOD = 1234567890;
ll mul(ll a,ll b){
	return ((a%MOD)*(b%MOD))%MOD;
}
ll lcm(ll a,ll b){
	return ((a*b)/__gcd(a,b))%MOD;
}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	ll n = 0;
	string s;cin>>s;int len = s.size();
	ll l = len;ll x = 100000000;ll r = 0;
    while(len > 8){
        ll now = 0;
        for(int i = l - len + 1; i <= l - len + 8; i++){
            now=now*10+s[i-1]-'0';
        }
        r = (now +((r*x)%MOD))% MOD;
        len =len-8;
    }
    for(int i=l-len+1;i<=l;i++){
        n=n*10+(s[i-1]-'0');
    }
    n =n%MOD;
    n =((r*x)%MOD+n)%MOD;
    printf("%lld\n",lcm(n M));
    return 0;
}
