#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int t;
signed main(){
	cin>>s;
	cin>>t;
	int x=0,y=0;
	int len = s.length();
	for(int i=0;i<t;i++){
		int ch = s[i%len];
		if(ch=='E') x++;
		if(ch=='S') y--;
		if(ch=='W') x--;
		if(ch=='N') y++;
	}
	printf("%lld %lld",x,y);
	return 0;
}
