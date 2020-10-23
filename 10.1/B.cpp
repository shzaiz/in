#include <bits/stdc++.h>
using namespace std;
set<int > hh;set<int > hl;set<int > sh;set<int > sl;

#define ll long long
ll ans = 0;int n,m,k,x,y,z;
void ran(int x,int y,int z){
	if(x==0 && z==0){
			hl.erase(y);hh.insert(y);ans = ans+m-sh.size();
		}else if(x==0 && z==1){
			hh.erase(y);hl.insert(y);ans = ans-m+sl.size();
		}else if(x==1 && z==0){
			sl.erase(y);sh.insert(y);ans = ans+n-hh.size();
		}else if(x==1 && z==1){
			sh.erase(y);sl.insert(y);ans = ans-n+hl.size();
		}
}
int main(){
	
	
	cin>>k>>n>>m;
	ans = 0;
	for(int i =1;i<=m;i++){
		ran(0,i,0);
	}
	for(int _=1;_<=k;_++){
		cin>>x>>y>>z;
		ran(x,y,z);
		cout<<ans<<endl;
	}
	cout<<(m*n-ans)<<endl;
	
}