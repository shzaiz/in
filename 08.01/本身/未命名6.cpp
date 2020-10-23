#include <iostream>
#define ll long long
using namespace std;
int a[900010],n;
int main(){
	int T;
	cin>>T;
	while(T--){
		ll ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			ans += max(a[i]-a[i+1],0); 
		}
		cout<<ans<<endl;
	}
}
