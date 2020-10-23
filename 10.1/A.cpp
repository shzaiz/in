
#include <bits/stdc++.h>
using namespace std;
int solve(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	int len = s.size();
	if(len==1 && s=="2") {
		if(k==0) cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	int p = (s[len-1]-'0')%2==0?0:1;
	if(p == 1&& k==0){
		cout<<"0"<<"\n";
		return 0;
	}else if(p == 0&& k==1){
		cout<<"1"<<"\n";
		return 0;
	}else if(p == 1&& k==1){
		cout<<"1"<<"\n";
		return 0;
	}else if(p == 0&& k==0){
		cout<<"1"<<"\n";
		return 0;
	}
	return 0;
}
int main(){
	int T;cin>>T;while(T--) solve();
	return 0;
}
