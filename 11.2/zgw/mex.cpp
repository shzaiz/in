// Expected 10 pts
// brute force 
#include <bits/stdc++.h>
using namespace std;
int b[200100];
int a[1000010];
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
int mex(int l,int r){
	memset(b,0,sizeof b);
	for(int i=l;i<=r;i++){
		b[a[i]]++;
	}
	for(int i=0;i<2000100;i++){
		if(!b[i]) return i;
	}
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	int n=read(),m=read();
	for(int o = 1;o<=n;o++){
		cin>>a[o];
	}
	for(int o = 1;o<=m;o++){
		int x = read(),y = read();
		cout<<mex(x,y)<<endl;
	}
	return 0;
}
