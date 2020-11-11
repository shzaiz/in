#include <bits/stdc++.h>
#define deb if(debug)
const int  debug = 0;
#define int long long
#define fo(i,x) for(int i = 1;i<=(int)x;i++)
#define f0(i,x) for(int i = 0;i<=(int)x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define N 55
using namespace std;
struct ios{
    inline char read(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }
    template <typename _Tp> inline ios & operator >> (_Tp&x){
        static char c11,boo;
        for(c11=read(),boo=0;!isdigit(c11);c11=read()){
            if(c11==-1)return *this;
            boo|=c11=='-';
        }
        for(x=0;isdigit(c11);c11=read())x=x*10+(c11^'0');
        boo&&(x=-x);
        return *this;
    }
}io;
int n,k;
int f[50][2] = {};
void sub1(){
	f[1][0] = 1; f[1][1] = 9;
	fo_(i,2,50){
		f[i][0] = f[i-1][0]*10 + f[i-1][1];
		f[i][1] = f[i-1][1]*9;
	}
	cout<<f[n][0];
}
int dfs(int i, int ans){
	
	if(ans>k || i>n) return 0;
	deb printf("%lld %lld\n",i,ans);
	if(ans == k && n == i) return 1; 
	int me =0;
	fo(num,9){
		me+=dfs(i+1,ans*num);
	}
	return me;	
}
int dp[19][32][32][32][32];
void dps(){
	int kk = k;
	int cnt2=0,cnt3=0,cnt5=0,cnt7=0;
	while(kk%2==0) kk/=2,cnt2++;
	while(kk%3==0) kk/=3,cnt3++;
	while(kk%5==0) kk/=5,cnt5++;
	while(kk%7==0) kk/=7,cnt7++;
	if(kk>1) {
		puts("0");
		exit(0);
	}
	dp[0][0][0][0][0] = 1;
	fo(i,n) f0(j,cnt2) f0(k,cnt3) f0(h,cnt5) f0(g,cnt7){
		dp[i][j][k][h][g] += dp[i-1][j][k][h][g];
		if(j-1>=0) dp[i][j][k][h][g] += dp[i-1][j-1][k][h][g];
		if(k-1>=0) dp[i][j][k][h][g] += dp[i-1][j][k-1][h][g];
		if(j-2>=0) dp[i][j][k][h][g] += dp[i-1][j-2][k][h][g];
		if(h-1>=0) dp[i][j][k][h][g] += dp[i-1][j][k][h-1][g];
		if(j-1>=0 && k-1>=0) dp[i][j][k][h][g] += dp[i-1][j-1][k-1][h][g];
		if(g-1>=0) dp[i][j][k][h][g] += dp[i-1][j][k][h][g-1];
		if(j-3>=0) dp[i][j][k][h][g] += dp[i-1][j-3][k][h][g];
		if(k-2>=0) dp[i][j][k][h][g] += dp[i-1][j][k-2][h][g];
	}
	cout<<dp[n][cnt2][cnt3][cnt5][cnt7];
}
signed main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	io>>n>>k;
	if(k==0){
		sub1();
	}else{
		dps();
	}
} 
