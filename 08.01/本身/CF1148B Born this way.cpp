#include <bits/stdc++.h>
using namespace std;
int n,m,ta,tb,k;
int a[10010],b[10010],p=0,ans;
int main(){
	cin>>n>>m>>ta>>tb>>k;
	for(int i=1;i<=ta;i++) cin>>a[i];
	for(int i=1;i<=tb;i++) cin>>b[i];
	if(k>=n || k>= m) return 0*printf("-1");
	
	for(int i=0;i<=k;++i){
		while(a[i+1]+ta>b[p]&&p<=m) p++;
		if(p+k-i>m){
			ans=-1;
			break;
		}
		ans=max(ans,b[p+k-i]+tb);
	}
	cout<<ans;
	return 0;
}
