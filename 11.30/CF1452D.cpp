#include <bits/stdc++.h>
using namespace std;
int qp(int base,int b){
	int ans=  1;
	while(b){
		if(b&1) ans = ans*base;
		base = base*base;
		b>>=1;
	}
	return ans;
}
int main(){
	cout<<qp(3,3);
} 
