#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1005
int n,MOD;
int f[N];
ll C[N][N];
void Cc(){
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=((ll)C[i-1][j-1]+C[i-1][j])%MOD;
	}
}
int main(){
	freopen("irrev.in","r",stdin);
	freopen("irrev.out","w",stdout);
	cin>>n>>MOD;
	if(n==1){
		cout<<1<<endl;
		return 0;
	} 
	Cc();
	f[0]=1;
	// f[i] = f[i]+ f[j-1]*[i-j]*C_{i-1}^{j-1}
	for(int i=1;i<=n;i++){
		f[i]=0;
		for(int j=1;j<=i;j=j+2)
			f[i]=(f[i]+((ll)f[j-1]*f[i-j])%MOD*C[i-1][j-1]%MOD)%MOD;
	}
	// g[0]=1;
	// for(int i=1;i<=n;i++){
		// g[i]=0;
		// for(int j=1;j<=i;j+=2)
			// g[i]=(g[i]+((ll)g[j-1]*g[i-j])%MOD*C[i-1][j-1]%MOD)%MOD;
	// }
	int ans=(f[n]+f[n])%MOD;
	printf("%d\n",ans);
	return 0;
}
