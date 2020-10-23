#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define MOD 1000000007
int ans,a[1005],dp1[1025][1025],dp2[1025][1025],sum[1025],sum3[1025],sum2[1025];
int add(int a,int b){
	return ((a%MOD)+(b%MOD))%MOD;
}
int mul(int m,int n){
	return ((m%MOD)*(n%MOD))%MOD;
}
int main(){
	freopen("basketball1.in","r",stdin); 
	freopen("basketball1.out","w",stdout); 
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//从前往后选择xor
	for(int i=1;i<n;i++){
		for(int j = 0;j<1024;j++){
			dp1[i][j^a[i]] = add(sum[j],dp1[i][j^a[i]]);
		}
		dp1[i][a[i]] = add(dp1[i][a[i]],1);
		for(int j = 0;j<1024;j++){
			sum[j] = add(sum[j],dp1[i][j]);
		}
	}
	//从后往前选择and
	for(int i=n;i>1;i--){
		for(int j = 0;j<1024;j++){
			dp2[i][j&a[i]] = add(sum2[j],dp2[i][j&a[i]]);
		}
		dp2[i][a[i]] = add(dp2[i][a[i]],1);
		for(int j = 0;j<1024;j++){
			sum2[j] = add(sum2[j],dp2[i][j]);
		}
	}
	//枚举断点，统计答案
	for(int i=1;i<n;i++){
		for(int j=0;j<1024;j++){
            sum3[j]=add(sum3[j],dp1[i][j]);
        }
		for(int j =0;j<1024;j++){
			ans = add(ans,sum3[j]*dp2[i+1][j]);
		}
	}
	cout<<ans;
}
