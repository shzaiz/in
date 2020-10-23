#include <bits/stdc++.h>
using namespace std;
#define mod 1000003
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1) ans = 1ll *a*ans %mod;
		a = 1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int p[15];
int q(int a){
	printf("? %d\n",a);fflush(stdout);
	int t;
	cin>>t;
	return t;
}
void w(int i){
	printf("! %d\n",i);fflush(stdout);
	exit(0);
}

int main(){
	for(int i=0;i<=10;i++){
		p[i] = q(i);
		if(!p[i]) w(i);
		for(int j=0;j<=10;j++){
			if(i==j) continue;
			p[i] = 1ll*p[i]*qp(i-j,mod-2)%mod;
		}
	}
	for(int i=11;i<mod;i++){
		int v = 0;
		for(int j=0;j<=10;j++){
			int val = 1;
			for(int k =0;k<=10;k++){
				if(j==k) continue;
				val = 1ll * val*(i-k)%mod;
			}
			v=(v+1ll*val*p[j])%mod;
		}
		if(v==0) w(i);
	}
	w(-1);
	return 0;
	
}
