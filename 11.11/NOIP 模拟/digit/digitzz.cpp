#include <bits/stdc++.h>
#define deb if(debug)
const int  debug = 0;
#define int unsigned long long
#define fo(i,x) for(int i = 1;i<=x;i++)
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
signed main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	io>>n>>k;
	if(k==0){
		sub1();
	}else{
		int fans = 0;
		fo(i,9){
			fans+= dfs(1,i);
		}
		cout<<fans;
	}
} 
