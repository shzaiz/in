#include<bits/stdc++.h>
#define maxn 2048
#define ll long long
#define re register int
using namespace std;
int n,a[maxn],b[maxn],sum[maxn];
int f[maxn][maxn+200],g[maxn][maxn+200],ans;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n;
	for(re i=1;i<=n;i++)
	cin>>a[i];
	for(re i=1;i<=n;i++)//µ¹¹ýÀ´ 
	b[i]=a[n-i+1];
	for(re i=1;i<=n;i++){
		for(re j=0;j<=maxn;j++)
			f[i][j]=sum[j^a[i]];
		f[i][a[i]]++;
		for(re j=0;j<=maxn;j++)
			sum[j]+=f[i][j];
	}
	memset(sum,0,sizeof(sum));
	for(re i=0;i<n;i++){
		for(re j=0;j<=maxn;j++)
			g[i+1][j&b[i+1]]+=sum[j];
		g[i+1][b[i+1]]++;
		for(re j=0;j<=maxn;j++)
			sum[j]+=g[i+1][j];
	}
	memset(sum,0,sizeof(sum));
	for(re i=1;i<n;i++){
		for(re j=0;j<maxn;j++)
			sum[j]+=f[i][j];
		for(re j=0;j<maxn;j++)
			ans+=sum[j]*g[n-i][j];
	}
	cout<<ans;
	return 0;
}
