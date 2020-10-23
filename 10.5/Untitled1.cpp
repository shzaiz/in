#include <bits/stdc++.h>
using namespace std;
#define N 300505
#define ll long long
int a[N];
int n;
int main(){
	cin>>n;
//	for(int i = 1;i<=n;i++){
//		cin>>a[n-i+1];
//	}
//	ll mint =1e17;
//	for(int i = 1;i<n;i++){
//		for(int j =i+1;j<=n;j++){
//			ll ds = a[j]-a[i];
//			ll dv = j-i;
//			if(ds%dv==0){
//				mint = min(mint,ds/dv);
//			}
//		}
//	}
//	cout<<mint<<endl;
	cin>>a[1];
	ll ans = 1e7;
	for(int i = 2;i<=n;i++){
		cin>>a[i];
		ans = min(ans,(ll)a[i-1]-a[i]);
	}
	cout<<ans;
	return 0;
} 
