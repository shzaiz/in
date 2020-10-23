#include <bits/stdc++.h>
#define ll long long
#define deb cout<<__LINE__<<" "<<__FUNCTION__<<endl;
using namespace std;
int n,k,m;
const int MAXN = 2e5+50;
int a[MAXN+10000];
ll qpow(ll a,ll b,ll n){ll t,y;t=1; y=a;while (b!=0){if (b&1==1) t=t*y%n;y=y*y%n; b=b>>1;}return t;}
const int MOD = 998244353;
long long mul(long long u,long long v){
	return (u*v)%MOD;
}
long long add(long long u,long long v){
	return (u+v)%MOD;
}
void sub45(){
	//TEST 45 ok
	ll f[MAXN][2] = {};
	f[0][0] = 1;
	for(int i=1;i<=n+1;i++){
		f[i][0] = add(f[i-1][1],mul(k-2,f[i-1][0]));
		f[i][1] = mul(k-1,f[i-1][0]);
	}
	// To test 4, a[1] = a[n], so the answer should be f[n][1]
	if(a[1]==a[n]) cout<<f[n-2][1]<<endl;
	else cout<<f[n-2][0]<<endl;
	// The output was 917399223 , and the ans was 917399223.
}

void sub3(){
	// TEST 3 ok
	ll ans = qpow(k-1,n-1,MOD);
	cout<<ans;
	return;
}

int st=1,en=1;
int makestr(int a[],int& st,int& en,int &n){
	if(en==n) return -1;
	st = en;
	if(en==1&&a[1]==0){
		for(;a[en+1]==a[en];en++){
			if(en==n) return 233;
		}
		if(en!=n){
			st++;
			en++;
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
ll f[MAXN][2];
ll ans = 1;
void sub67(){
	
	f[0][0] = 1;
	for(int i=1;i<=n+1;i++){
		f[i][0] = add(f[i-1][1],mul(k-2,f[i-1][0]));
		f[i][1] = mul(k-1,f[i-1][0]);
	}
	
	for(int i=makestr(a,st,en,n);i!=-1;i = makestr(a,st,en,n)){
		if(i==0) ans=mul(ans,qpow(k-1,en-st,MOD));
		else if(i==233) ans=mul(ans,qpow(k-1,en-st+1,MOD));
		else if(i==999) {while(1)cout<<"ERROR!!!"<<endl;}
		else if(i==1) {
			if(a[st]!=a[en]){
				ans = mul(ans,f[en-st-1][0]); 
			}else{
				ans = mul(ans,f[en-st-1][1]);
			}
		}
	}
	cout<<ans;
}
int od[MAXN];
int ev[MAXN];
int nod=0;
int nev=0;
int stev,enod,enev;
int stod = stev=enod=enev = 1;
void prepare(){
	for(int i=1;i<=n;i++){
		if(i&1){
			od[++nod] = a[i];
		}else{
			ev[++nev] = a[i];
		}
	}
	
}

void ALL(){
	prepare();
	f[0][0] = 1;
	for(int i=1;i<=n+1;i++){
		f[i][0] = add(f[i-1][1],mul(k-2,f[i-1][0]));
		f[i][1] = mul(k-1,f[i-1][0]);
	}
	for(int i=makestr(od,stod,enod,nod);i!=-1;i = makestr(od,stod,enod,nod)){
		
		if(i==0) ans=mul(ans,qpow(k-1,enod-stod,MOD));
		else if(i==233) ans=mul(ans,qpow(k-1,enod-stod+1,MOD));
//		else if(i==999) {while(1)cout<<"ERROR!!!"<<endl;}
		else if(i==1) {
			if(od[stod]!=od[enod]){
				ans = mul(ans,f[enod-stod-1][0]); 
			}else{
				ans = mul(ans,f[enod-stod-1][1]);
			}
		}
	}
	for(int i=makestr(ev,stev,enev,nev);i!=-1;i = makestr(ev,stev,enev,nev)){
		if(i==0) ans=mul(ans,qpow(k-1,enev-stev,MOD));
		else if(i==233) ans=mul(ans,qpow(k-1,enev-stev+1,MOD));
//		else if(i==999) {while(1)cout<<"ERROR!!!"<<endl;}
		else if(i==1) {
			if(ev[stev]!=ev[enev]){
				ans = mul(ans,f[enev-stev-1][0]); 
			}else{
				ans = mul(ans,f[enev-stev-1][1]);
			}
		}
	}
	
	cout<<ans;
}


void input(){
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	input();
	if(m){
		ALL();
	}else{
		sub67();
	}
} 

