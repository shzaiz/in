#include <bits/stdc++.h>
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define fl(x) freopen("#x.in","r",stdin);freopen("#x.out","w",stdout)
#define mod 1000000007
using namespace std;
struct Mat{
	int a[2][2];
	Mat operator *(const Mat &b) const{
		Mat res;
		fo_(i,0,1) fo_(j,0,1) fo_(k,0,1) res.a[i][j] = (a[i][k]*b.a[k][j])%mod;
		return res;
	}
	void unit(){
		a[0][0] = 1, a[0][1] = 0, a[1][0] = 0, a[1][1] = 1;
	}
}ans,base;

void qp(int b){
	while(b){
		if(b&1) ans = ans*base;
		base=base*base;
		b>>=1;
	}
}
int n;
int main(){
	cin>>n;
	base.unit();
	if(n<=2){
		cout<<"1";
		return 0;
	}
	qp(n-2);
	cout<<ans.a[0][0];
	return 0;
}
