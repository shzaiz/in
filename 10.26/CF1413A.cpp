#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ch() getchar()
#define pc(x) putchar(x)
template<typename T>inline void read(T&x){
	int f;char c;
	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c<='9'&&c>='0';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>inline void write(T x){
	static char q[64];int cnt=0;
	if(!x)pc('0');if(x<0)pc('-'),x=-x;
	while(x)q[cnt++]=x%10+'0',x/=10;
	while(cnt--)pc(q[cnt]);
}
int a[105];
int main(){
	int T;read(T);
	while(T--){
		int n;read(n);
		for(int i=1;i<=n;++i)
			read(a[i]);
		for(int i=1;i<=n;i+=2)
			write(-a[i+1]),pc(' '),write(a[i]),pc(" \n"[i==n-1]);
	} 
	return 0;
}
