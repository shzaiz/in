#include <iostream>
using namespace std;
#define ll long long
ll a[200010]={0,1,2,3,4,8,465,0,-1,5,5};
int findmx(int n){
	int tmp = -10100001;
	for(int i=1;i<=n;i++){
		if(tmp<a[i]) tmp = a[i];
	}
	return tmp;
}
int findmi(int n){
	int tmp = 10100001;
	for(int i=1;i<=n;i++){
		if(tmp>a[i]) tmp= a[i];
	}
	return tmp;
}
int main2(){
	cout<<findmi(10);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(k%2==0){
			// ai - dmin
			for(int i=1;i<n;i++) cout<<a[i]-findmi(n)<<" ";
			cout<<a[n]-findmi(n);
			cout<<"\n";
			
		}else{
			//dmax - ai
			for(int i=1;i<n;i++) cout<<findmx(n)-a[i]<<" ";
			cout<<findmx(n)-a[n];
			cout<<endl;
		}
	}
	return 0;
}
