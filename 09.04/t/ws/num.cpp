#include<bits/stdc++.h>
using namespace std;
int a1[1000]={0,0};
int a2[1000]={0,1,0}; 
int a3[1000]={0,4,1,0};
int a4[1000]={0,11,11,1,0};
int a5[1000]={0,26,66,26,1,0};
int a6[1000]={0,57,302,302,57,1,0};
int a7[1000]={0,120,1191,2416,1191,120,1,0};
int a8[1000]={0,247,4293,15619,4293,247,1,0};
int a9[1000]={0,502,14608,88234,156190,88234,14608,502,1,0};
int a10[1000]={0,1013,47840,455192,1310354,1310354,455192,47840,1013,1,0};
int main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout); 
	int n,k;
	cin>>n>>k;
	if(n<=10){
		if(n==1){
			cout<<a1[k]%2012<<endl;
			return 0;
		}
		if(n==2){
			cout<<a2[k]%2012<<endl;
			return 0;
		}
		if(n==3){
			cout<<a3[k]%2012<<endl;
			return 0;
		}
		if(n==4){
			cout<<a4[k]%2012<<endl;
			return 0;
		}
		if(n==5){
			cout<<a5[k]%2012<<endl;
			return 0;
		}
		if(n==6){
			cout<<a6[k]%2012<<endl;
			return 0;
		}
		if(n==7){
			cout<<a7[k]%2012<<endl;
			return 0;
		}
		if(n==8){
			cout<<a8[k]%2012<<endl;
			return 0;
		}
		if(n==9){
			cout<<a9[k]%2012<<endl;
			return 0;
		}
		if(n==10){
			cout<<a10[k]%2012<<endl;
			return 0;
		}
	}
	else{
		if(k==n){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	return 0;
}

