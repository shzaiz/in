#include <bits/stdc++.h>
#define ull unsigned long long
#define fo freopen
ull qpow(ull a,ull b){ull t,y;t=1; y=a;while (b!=0){if (b&1==1) t=t*y;y=y*y; b=b>>1;}return t;}
int a[25] = {};
ull n=10;
using namespace std;
ull nxt(ull s){
	s = s+1;
	cout<<s;
	for(ull i=10;i<=(ull)2*n+(ull)1;i*=(ull)10){
		for(int j=1;j<20;j++){
			cout<<(s%i)/(i/10)<<endl;
			if((s%i)/i>=2){
				s -= 2*qpow(10,(i-1));
				s += 1*qpow(10,i);
			} 
		}
	}
}
int main(){
	fo("D:\\binary.in","r",stdin);fo("binary.out","w",stdout);
	cout<<-1;
//	cin>>n;
}
