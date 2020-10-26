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
const int maxn=250005;
int Right[maxn],Left[maxn],Up[maxn],Down[maxn];
int main(){
	int T;read(T);
	while(T--){
		int n,m;
		read(n),read(m);
		for(int i=1;i<=n*m;++i)
			Right[i]=Left[i]=Up[i]=Down[i]=0;
		int tot=0;
		for(int i=1;i<=n;++i){
			int last=0;
			for(int j=1;j<=m;++j){
				int a;read(a);if(j!=1)Right[last]=a,Left[a]=last;last=a;
			}
		}
		for(int j=1;j<=m;++j){
			int last=0;
			for(int i=1;i<=n;++i){
				int a;read(a);if(i!=1)Down[last]=a,Up[a]=last;last=a;
			}
		}
		int rt;
		for(int i=1;i<=n*m;++i){
			if(!Up[i]&&!Left[i]){
				rt=i;break;
			}
		}
		while(rt){
			for(int i=rt;i>=1&&i<=n*m;i=Right[i])
				write(i),pc(" \n"[!Right[i]]);
			rt=Down[rt];
		}
	}
	return 0;
}
