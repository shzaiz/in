#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[110][110],b[7];
signed main(){
	int t;cin>>t;
	while(t--){
		int n,m,ans=0;cin>>n>>m;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)cin>>a[i][j];
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				b[1]=a[i][j],b[2]=a[n-i+1][j],b[3]=a[n-i+1][m-j+1],b[4]=a[i][m-j+1];
				sort(b+1,b+5);
				ans+=b[4]+b[3]-b[1]-b[2];
			}
		cout<<ans/4<<endl;
	}
	return 0;
}