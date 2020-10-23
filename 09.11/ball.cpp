#include <bits/stdc++.h>
#define ll long long
using namespace std;
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
//	freopen("D:\\ball.in","r",stdin);
//	freopen("D:\\ball.out","w",stdout);
	
	int n = read();
	string s;
	cin>>s;
	ll ans= 0;
	for(ll i=0;i<n;i++){
		if(s[i]=='B') ans += (1ll<<i);  
	}
	cout<<ans;
	return 0;
}
