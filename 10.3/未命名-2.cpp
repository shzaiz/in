#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ull unsigned long long
ull mul(ull a,ull b){
	return ((a%MOD)*(b%MOD))%MOD;
}
ull qpow(ull a, ull n){
	if(n==0) return 1;
	if(n<0) return 1;
    ull ans = 1;
    while(n){
        if(n&1)ans = mul(ans,a);
        a = mul(a,a);
        n >>= 1;
    }
    return ans;
}
ull add(ull a,ull b){
	return ((a%MOD)+(b%MOD)%MOD);
}
ull divv(ull a,ull b){
	return ((a%MOD)*(qpow(b,MOD-2)%MOD))%MOD;
}
int main(){
	int N;
	cin>>N;
	if(N==1){
		string s;cin>>s;
		int len = s.size();
		ull cnt0=0,cnt1=1;
		for(int i = 0;i<len;i++){
			if(s[i]=='1'){
				cnt1++;
			}else{
				cnt0++;
			}
		}
		if(len==1){
			if(s[0]=='0'){printf("318608048\n0");}
			else {printf("0\n318608048");}
			return 0;
		}
		ull mo = 318608048%len;
		ull cc1=0,cc0=0;
		if(mo!=0){
			for(int i = 0;i<mo;i++){
				if(s[i]=='1'){
					cc1++;
				}else{
					cc0++;
				}
			}
		}
		cout<<add(mul(divv(318608048,len),cnt0),cc0)<<endl;
		cout<<add(mul(divv(318608048,len),cnt1),cc1);
	}
}