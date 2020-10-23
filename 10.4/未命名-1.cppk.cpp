#include <bits/stdc++.h>
using namespace std;
int cost[2005][2005];
int f[2005][2005];
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
	int m,n,k;
	cin>>m>>n>>k;
	for(int i = 0;i<2005;i++){
		for(int j = 0;j<2005;j++){
			f[i][j] = 99999999;
		}
	}
	for(int i = 1;i<=m;i++){
		for(int j =1;j<=n;j++){
			cost[i][j] = read();
		}
	}
	for(int i = 1;i<=n;i++){
		f[2][i] = cost[1][i];
	}
	for(int i = 3;i<=n+1;i++){
		for(int j = 1;j<=m;j++){
			for(int k = 1;k<=m;k++){
				if(j==k) continue;
				f[i][j] = min(f[i][j],f[i-1][k]+cost[i][j]);
			}
		}
	}
	int ans = 999999999;
	for(int i = 1;i<=n;i++){
		ans = min(f[m-1][i],ans);
	}
	cout<<ans;
	return 0;
}