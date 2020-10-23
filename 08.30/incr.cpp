#include<bits/stdc++.h>
using namespace std;
#define N 1000
int d[N];
int a[N];
inline int read(){
	int x;
    x=0;char ch=0;bool sign=false;
    while(ch < '0' || ch > '9'){
        sign|=(ch == '-');
        ch=getchar();
    }
    while(!(ch < '0' || ch > '9')){
        x=x*10+(ch^48);
        ch=getchar();
    }
    x=sign ? -x : x;
    return x;
}

inline void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
int bound(int l,int r,int x){
	while (l<=r){
		int mid=(l + r) / 2;
		if (d[mid]<x){
			l=mid + 1;
		}
		else{
			r=mid - 1;
		}
	}
	return l;
}
int main(){
	freopen("incr.in","r",stdin);
	freopen("incr.out","w",stdout);
	int n=read();
	for (int i=0;i<n;i++){
		a[i]=read();
	}
	d[0]=-9999999;
	int len=1;
	for (int i=1;i<7;i++){
		if (a[i] > d[len]){
			d[++len]=a[i];
		}
		else{
			int k=bound(1,len,a[i]);
			d[k]=a[i];
		}
	}
	print(n-len);
	return 0;
}
