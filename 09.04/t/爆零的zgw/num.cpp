#include <bits/stdc++.h>
#define MOD 2015
using namespace std;
int f[1005][1005];
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

int main(){
	for(int i=0;i<1005;i++){
		f[i][0] = 1;
	}
	for(int i=1;i<1005;i++){
		for(int j=1;j<1005;j++){
			f[i][j] = (f[i-1][j-1]*(i-j) + f[i-1][j]*(j+1))%MOD;
		}
	}
	int n=read(),p=read();
	printf("%d\n",f[n][p]);
	return 0;
}
