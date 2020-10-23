#include <bits/stdc++.h>
using namespace std;

int a[100010]={};
void mp(int a[],int k,int n){
	int sz = n/k;
	for(int i = 0;i<sz;i++){
		for(int j = 1;j<k;j++){
			swap(a[i*k+j],a[i*k+j+1]);
		}
	}
	 if(n%k){
		 int s = n/k*k;
		 for(int i = s+1;i<n;i++){
			 swap(a[i+1],a[i]);
		 }
		
	 }
	// for(int i = 1;i<=n;i++){
		// cout<<a[i]<<" ";
	// }
}
int main(){
	int n;cin>>n;
	for(int i = 1;i<=n;i++){
		a[i] = i;
	}
	for(int i = 2;i<=n;i++){
		mp(a,i,n);
	}
	for(int i = 1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	// for(int i = 2;i<=(n);i++){
		// for(int j = 0;j<=(n/i);j++){
			// for(int b = 1;b<=i;b++){
				// swap(a[i*j+b+1],a[i*j+b]);
			// }
			// if(n%i){
				// int s = n/i*i;
				// printf("%d %d\n",s,i);
				// for(int b = s;b<n;b++){
					// swap(a[b+1],a[b]);
				// }
			// }
		// }
	// }
	// for(int i = 0;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}