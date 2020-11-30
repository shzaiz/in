#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 1;i<=n;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define fl(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define N 10005
#define fi first
#define D double
#define se second
int k = 1,n;
D fu[1001][1001] ={};
D f(int n,int m){
	if(n<=0 && m<=0) return 0.5;
	if(n<=0 ) return 1;
	if(m<=0) return 0;
	if(fu[n][m]) return fu[n][m];
	return fu[n][m] = 0.25*(f(n-k,m-3*k)+f(n-2*k,m-2*k)+f(n-3*k,m-k)+f(n-4*k,m));
}
int main(){
	fl("tea");
	memset(fu,0,sizeof fu);
	cin>>n>>k;
	n = ceil(n/k); k = 1;
	cout<<f(n,n);
	
}
