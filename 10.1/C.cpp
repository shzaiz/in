#include <bits/stdc++.h>
using namespace std;
#define D double
#define N 100010
struct car{
	D id,x0,a;
}c[N];
struct ask{
	D t,rk;
}a[N];
struct ans{
	D id,s;
}Ans[N];
bool cmpw(ans a,ans b){
	if(a.s>=b.s) return 1;
	else return 0;
}
bool cmp(ask a,ask b){
	if(a.t<=b.t) return 1;
	else return 0;
}
int main(){
	int n;cin>>n;
	for(int i = 1;i<=n;i++){
		int x,y;cin>>x>>y;
		c[i] = (car){(D)i,(D)y,(D)x};
	}
	int t;cin>>t;
	for(int i = 1;i<=t;i++){
		int t,r;
		cin>>t>>r;
		a[i] = (ask){(D)t,(D)r};
	}
	sort(a+1,a+1+n,cmp);
	// for(int i =1;i<=t;i++){
		// cout<<a[i].t<<" "<<a[i].rk<<endl;
	// }
	for(int i = 1;i<=t;i++){
		memset(Ans,0,sizeof Ans);
		for(int j  =1;j<=n;j++){
			Ans[j] = (ans){(D)j,c[j].x0+c[j].a*a[i].t};
		}
		sort(Ans+1,Ans+1+n,cmpw);
		// for(int i =1;i<=t;i++){
			// cout<<Ans[i].id<<" "<<Ans[i].s<<endl;
		// }
		cout<<Ans[(int)a[i].rk].id<<endl;
		// cout<<"----\n";
	}
	
	return 0;
}