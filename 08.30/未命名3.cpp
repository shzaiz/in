#include <bits/stdc++.h>
using namespace std;

string mul(string aa,string bb){
	reverse(aa.begin(),aa.end());
	reverse(bb.begin(),bb.end());
	int m = aa.size(),n =bb.size();
	int a[10010],b[10010];
	for(int i = 0;i<m;i++){
		a[i+1] = aa[i]-'0';
	}
	for(int i = 0;i<n;i++){
		b[i+1] = bb[i]-'0';
	}
	int p[10010];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			p[i+j-1] += a[i]*b[j];
		}
	}
	for(int i=1;i<=m+n+1;i++){
		p[i+1] += p[i] /10;
		p[i] = p[i] %10;
	}
	int T=1000;
	bool in = false;
	string ss = "";
	
	while(T--){
		if(T==0) break;
		if(p[T]==0&& !in) continue;
		else{
			in = 1;
			ss = ss+(char)(p[T]+'0');
		}
		
	}
	if(ss.size()==0) ss="0";
	return ss;
}
string add(string aa,string bb){
	reverse(aa.begin(),aa.end());
	reverse(bb.begin(),bb.end());
	int m = aa.size(),n =bb.size();
	int a[10010],b[10010];
	for(int i = 0;i<m;i++){
		a[i+1] = aa[i]-'0';
	}
	for(int i = 0;i<n;i++){
		b[i+1] = bb[i]-'0';
	}
	int p[10010];
	int t = max(m,n);
	for(int i=1;i<=t;i++){
		p[i] = a[i]+b[i];
	}
	for(int i=1;i<=m+n+1;i++){
		p[i+1] += p[i] /10;
		p[i] = p[i] %10;
	}
	int T=1000;
	bool in = false;
	string ss = "";
	
	while(T--){
		if(T==0) break;
		if(p[T]==0&& !in) continue;
		
		else{
			in = 1;
			ss = ss+(char)(p[T]+'0');
		}
		
	}
	if(ss.size()==0) ss="0";
	return ss;
}
unsigned __int64 f[1005][1005];
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

string ITS(int x){
	string s = "";
	while(x){
		s = s+(char)(x%10+'0');
		x /=10;
	}
	reverse(s.begin(),s.end());
	return s;
}

int main(){
//	freopen("permutation.in","r",stdin);
//	freopen("permutation.out","w",stdout);
	for(int i=0;i<1005;i++){
		f[i][0] = 1;
	}
	for(int i=1;i<105;i++){
		for(int j=1;j<105;j++){
//			f[i][j] = add(mul(f[i-1][j-1],ITS((i-j))),mul(ITS((j+1)),f[i-1][j]));
//			cout<<i<<j<<" "<<mul(ITS((j+1)),f[i-1][j])<<endl;
			f[i][j] = (f[i-1][j-1]*((i-j)) + f[i-1][j]*(j+1));
		}
	}
	int n=read(),p=read();
	cout<<f[n][p];
	return 0;
}
