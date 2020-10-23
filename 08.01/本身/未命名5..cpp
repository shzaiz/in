#include <iostream>
using namespace std;
int n = 11;
const int MAXN = 2e5+5;
int a[MAXN]={0,0,0,0,0,3,0,0,2,2,2,5};
int stt=1,enn=1;
int makestr(int a[],int& st,int& en){
	if(en>=n) return -1;
	st = en;
	if(en==1&&a[1]==0){
		for(;a[en+1]==a[en];en++){
			if(en==n) return 233;
		}
		if(en!=n){
			st=st+1;
			en=en+1;
			return 233;
		} 
	}
	
	
	for(;st<=n;st++){
		if(st>=n) return -1;
		if(a[st]!=0 && a[st+1]==0){
			en=st+1;
			for(;en<=n;en++){
				if(en>n) return -1;
				if(en==n&&a[en]==0){
					return 0;
				}else if(a[en]!=0&&a[en-1]==0){
					return 1;
				}
			}
		}
	}
}

int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=makestr(a,stt,enn),cnt=0;i!=-1;i = makestr(a,stt,enn),cnt++){
		cout<<stt<<" "<<enn<<" "<<i<<"\n";
		//if(cnt>10) return 0;
	}
}
