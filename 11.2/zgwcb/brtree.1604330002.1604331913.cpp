#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int f1[N],f2[N];
int p,q,T,mod;
int x,ans1 = 0;
signed main(){
	freopen("brtree.in","r",stdin);
	freopen("brtree.out","w",stdout);
	cin>>p>>q>>T>>mod;
	int tt = __gcd(p,q);
	q /= tt; p/=tt;
	f1[0] = f2[0] = 1;
	f1[2] = 2*p*(q-p);f2[2] = q*q;
	tt = __gcd(f1[2],f2[2]);
	int _a=f1[2],_b=f2[2];
	for(int i = 4;i<=N-2;i+=2){
		f1[i] = f1[i-2] * _a;
		f1[i] %= mod;
		f2[i] = f2[i-2] * _b;
		f2[i] %= mod;
	}
	
	for(int i = 1;i<=T;i++){
		cin>>x;
		x -= ans1;
		ans1 = 0;
		if(x %2 == 1) printf("0 0\n");
		else{
			int fz,fm;
			fz = (p*p+(q-p)*(q-p))%mod;
			fm = q*q;
			int huajian = __gcd(fz,fm);
			fz/= huajian, fm/=huajian;
			int out1,out2;
			out1 = (f1[x-2]*fz)%mod;
			out2 = (f2[x-2]*fm)%mod;
			cout<<out1<<" "<<out2<<endl;
			ans1 = out1;
		}
	}
	return 0;
}
