#include <bits/stdc++.h>
using namespace std;
int a[100005];
int cnt = 0;
int n;
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
    freopen("type.in","r",stdin);
 	freopen("type.out","w",stdout);
	n = read();
	for(int i=1;i<=n;i++){
		char C;
		cin>>C;
		if(C=='T'){
			char X;
			cin>>X;
			a[++cnt] = X;
		}else if(C=='U'){
			int x = read();
			cnt-=x;
		}else if(C=='Q'){
			int y = read();
			cout<<(char)a[y]<<endl;
		}
	}
	return 0;
}