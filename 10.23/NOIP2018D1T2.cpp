#include <bits/stdc++.h>
using namespace std;
int dp[1000010],f[1000010],n,x,ans;
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
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    #endif
	int t = read();
	while(t--){
		n = read();
		for(int i=1;i<=n;i++) f[i] = read();
		sort(f+1,f+1+n);
		dp[0] = 1;
		for(int i=1;i<=n;i++){
			if(!dp[f[i]]) ++ans;
			for(int j=f[i];j<=f[n];j++) dp[j]+= dp[j-f[i]];
		}
		print(ans);
		printf("\n");
		memset(f,0,sizeof f);
		memset(dp,0,sizeof dp);
		ans = 0;
		}
	return 0;
}