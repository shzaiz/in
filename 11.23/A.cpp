#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
int f[2001][2001],ans;
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++)f[1][i]=1;
	for(int i=2;i<=k;i++)
		for(int j=1;j<=n;j++)
			for(int _=1;j*_<=n;_++)
				f[i][j]=(f[i][j]+f[i-1][j*_])%M;
	for(int i=1;i<=n;i++)ans=(ans+f[k][i])%M;
	printf("%lld\n",ans),exit(0);
}
