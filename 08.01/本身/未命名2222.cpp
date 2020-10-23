#include <bits/stdc++.h>
using namespace std;
int a[100100];
int next[100100];

void solve(){
	int n;
	cin>>n;
	int tmp=0;
	cin>>tmp;
	bool f = false;
	for(int i=2;i<=n;i++){
		int q;
		cin>>q;
		if(tmp!=q)f=1;	
	}  
	if(f) cout<<"1\n";
	else cout<<n<<"\n";
}

int main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
