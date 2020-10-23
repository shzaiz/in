#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a<b) swap(a,b);
	int del = a-b;
	if(del<=c){
		b = a;
		c-=del;
		b+= c/2;
	}else{
		b+=c;
	}
	
	cout<<a<<" "<<b;
	int sum = 0;
	for(int i=0;i<=99999;i++){
		sum =sum+i;
		if(sum>=b) {
			cout<<i-1<<endl;
			break;
		}
	}
	
	
}
