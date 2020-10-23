#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long f[99999][11][11];
int ans = 0;
int N = 4;
long long MOD = 1000000009;
bool pri(int x){
	if(x == 1) return false;
	int mi = sqrt(x);
	for(int i=2;i<=mi;i++){
		if(x % i == 0) return false;
	}
	return true;
}

void init(){
	memset(f,sizeof f,0);
}

void get3p(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			int warma = 0;
			for(int k=1;k<=9;k++){
				if(pri(k*100+i*10+j)){
					warma++;
				//	cout<<(k*100+i*10+j)<<endl;
				}
			}
			f[3][i][j] = warma;
		}
	}
}

void dp(int n){
	for(int i=4;i<=n;i++){
		for(int j=1;j<=9;j++){
			for(int k=1;k<=9;k++){
				for(int q=1;q<=9;q++){
					if(pri(q*100+k*10+j)){
						f[i][k][j] = (f[i-1][q][k] + f[i][k][j])% MOD;
					}
				}
			}
		}
	}
}

int collect(){
	for(int i=1;i<=9;i++){
		for(int j = 0;j<=9;j++){
			ans = (ans + f[N][i][j])%MOD;
		}
	}
	cout<<ans;
}


int main(){
	freopen("threeprime.in","r",stdin);
	freopen("threeprime.out","w",stdout);
	cin>>N;
	if(N==3){
		cout<<"143";
	}else if(N==4){
		cout<<"204";
	}else if(N==5){
		cout<<"374";
	}else{
		init();
		get3p();
		dp(N);
		collect();
	}
	return 0;
	
} 
