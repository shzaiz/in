#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
#define int long long
int gcd(int x,int y){
	if(y==0)
	return x;
	else
	return gcd(y,x%y);
}
int ans;
int f[maxn][maxn];
int a[maxn];
signed main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++){
            for(int x=j-1;x<i;x++){
            	f[i][j]=max(f[i][j],gcd(f[x][j-1],a[i]));
			}
			if(j==k)
			ans=max(ans,f[i][j]);
        }
    //cout<<ans<<" "<<k<<endl;
	ans*=k;
	cout<<ans;
} 
