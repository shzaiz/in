#include <bits/stdc++.h>
using namespace std;
int a[10010],N,T;
int main(){
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=1;i<=N;i++) cin>>a[i];
		sort(a+1,a+1+N);
		bool okay = true;
		for(int i=1;i<N;i++){
			if(a[i+1]-a[i]>1) {okay=false;break;}
		}
		if(okay) cout<<"YES\n"; else cout<<"NO\n";
	}
	
}
