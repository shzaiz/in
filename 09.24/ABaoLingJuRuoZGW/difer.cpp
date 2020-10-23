#include<bits/stdc++.h>
using namespace std;
const int MOD=100007;
int f[1001][1001];
int main(){
	freopen("difer.in","r",stdin);
	freopen("difer.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>f[0][i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=(f[i-1][j]%MOD-f[i-1][j-1]%MOD)%MOD;
		}
	
	}
	for(int i=1;i<=n;i++){
		cout<<(f[m][i]+MOD)%MOD<<endl;
	}
	
	return 0;
}
