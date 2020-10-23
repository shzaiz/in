#include<bits/stdc++.h>
using namespace std;
char s[200005],t[200005];
long long anss,anst,ans;
int x[200005],y[200005],cha[200005];
//char num[30]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main(){
	freopen("midstr.in","r",stdin);
	freopen("midstr.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		x[i]=s[i]-'a';
		y[i]=t[i]-'a';
	}
	for(int i=n;i>=1;i--){
		if(y[i]>=x[i]){
			cha[i]=y[i]-x[i];
		}
		else{
			y[i-1]--;
			y[i]+=26;
			cha[i]=y[i]-x[i];
		}
	}
	int q;
	for(int i=1;i<=n;i++){
		q=cha[i]%2;
		cha[i]/=2;
		if(q!=0)
		cha[i+1]+=(q*26);
	}
	for(int i=1;i<=n;i++){
		char p=s[i]+cha[i];
		cout<<p;
	}
	return 0;
}
