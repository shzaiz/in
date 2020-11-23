#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++) 
int a[N], mx[N]; 
void solve(int n){
	bool flag = 0;
	fo(i,n) cin>>a[i];
	mx[1] = a[1];
	fo_(i,2,n) mx[i] = max(a[i],mx[i-1]);
	fo_(i,2,n) if(a[i]>mx[i-1]){
		 flag = 1;
	}
	if(flag) cout<<"Y\n"; else cout<<"J\n";
}
int main(){
	freopen("disk.in","r",stdin);
	freopen("disk.out","w",stdout);
	mx[0] = 998244353;
	int n;
	while(cin>>n) solve(n);
	return 0;
}
