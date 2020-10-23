#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int t,n,m,x,p;
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n>>m>>x>>p;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		if(n==m){
			cout<<n;
		}
		else{
			cout<<(n+m)/2;
		}
}
return 0;
}
