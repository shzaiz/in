#include <bits/stdc++.h>
using namespace std;
int m,n,q;
int find(int x,int y,int p){
	if(x==y) return p;
	if(y/x>=2) return p;
	else return find(y-x,x,p^1);
}
int main(){
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>m>>n;
		if(m>n) swap(m,n);
		if(find(m,n,0)==0) cout<<"Stan wins"<<endl;
		else cout<<"Ollie wins"<<endl;
	}
	return 0;
}
