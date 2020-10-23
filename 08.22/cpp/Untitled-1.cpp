#include <bits/stdc++.h>
using namespace std;
int A[10010];

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
		int n;
		scanf("%d",&n);
		int ans = -99999999;
		int maxn = max(read(),-999999);
		for(int j=1;j<n;j++) {
			int aj = read();
			ans = max(ans,maxn-aj);
			maxn =max(aj,maxn);
		}
		print(ans);
		printf("\n");
	
	return 0;
}