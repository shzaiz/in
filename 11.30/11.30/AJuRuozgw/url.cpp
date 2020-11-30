#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 1;i<=n;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define fl(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define fi first
#define se second
string s[1005],s2[1005];
map<string, string> mp;
string str = "a";
void nxt(){
	int le = str.length();
	int tg = 0;
	int i = 0;
	while( i < le){
		if(str[i]!='z'){
			str[i] ++;
			break;
		}else{
			tg = 1;
			str[i] = 'a';
			i+=1;
		}
	}
	if(tg&&i==le) {
		str  = str+"a";
	}
	
	
}
bool cmp(string a,string b){
	if(a.length()!=b.length()) return a.length()<b.length();
	else return a<b;
}
signed main(){
	fl("url");
	int n;cin>>n;
	fo(i,n ){
		cin>>s[i];
	}
	fo(i,n ) s2[i] = s[i];
	
	sort(s2+1,s2+n+1,cmp); 
	int xx = unique(s2+1,s2+1+n)-s2-1;
	fo(i,xx){
		mp[s2[i]] = str;
		nxt();
	}
	fo(i,n){
		cout<<mp[s[i]]<<endl; 
	}
	return 0;
	
} 
