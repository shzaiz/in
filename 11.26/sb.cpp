#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
#define mod 100000000
#define lint long long
using namespace std;
struct Martrix{
	lint mp[3][3];
}; 
lint n,m;
Martrix init,unit,mul;

Martrix __mul(Martrix rec_1,Martrix rec_2){
	Martrix ans;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			ans.mp[i][j]=0;
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			for(int k=1;k<=2;k++){
				ans.mp[i][j]+=rec_1.mp[i][k]*rec_2.mp[k][j];
				ans.mp[i][j]%=mod;
			}
		}
	} 
	return ans;
}
Martrix __pow(Martrix rec,lint exp){
	Martrix ans=unit;
	while(exp!=0){
		if(exp&1){
			exp-=1;
			ans=__mul(ans,rec);
		}
		exp>>=1;
		rec=__mul(rec,rec);
	} 
	return ans;
} 
lint gcd(lint x,lint y){
	if(x%y==0)return y;
	return gcd(y,x%y);
}
int main(){
	scanf("%lld%lld",&n,&m);
	mul.mp[1][1]=1;
	mul.mp[1][2]=1;
	init.mp[1][1]=0;
	init.mp[1][2]=1;
	init.mp[2][1]=1;
	init.mp[2][2]=1;
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			unit.mp[i][j]=0;
		}
		unit.mp[i][i]=1;
	} 
	lint res=gcd(n,m);
	if(res==1||res==2){
		puts("1");
		return 0;
	}else{
		//printf("res=%lld\n",res);
		Martrix ans,tmp=__pow(init,res-2);
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				ans.mp[i][j]=0;
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				for(int k=1;k<=2;k++){
					ans.mp[i][j]+=mul.mp[i][j]*tmp.mp[k][j];
					ans.mp[i][j]%=mod;
				}
			}
		}
		printf("%lld",ans.mp[1][2]); 
	}
	return 0;
}
