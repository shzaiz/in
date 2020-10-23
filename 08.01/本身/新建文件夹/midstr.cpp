#include <bits/stdc++.h>
using namespace std;
int sum[500100],s[500100],t[500100],a[500100];
int N;
string tab[29] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
void deb(){
//	for(int i=1;i<=N;i++) cout<<s[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=N;i++) cout<<t[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=N;i++) cout<<sum[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=N;i++) cout<<a[i]<<" ";
//	cout<<endl;
//	cout<<"-----"<<endl;
}
int main(){
	freopen("midstr.in","r",stdin);
	freopen("midstr.out","w",stdout);
	cin>>N;
	string q;cin>>q;
	for(int i=1;i<=N;i++) {s[i]=q[i-1]-97;}
	cin>>q;
	for(int i=1;i<=N;i++) {t[i]=q[i-1]-97;}
	for(int i=1;i<=N;i++) {sum[i] = s[i]+t[i];}
	deb();
	for(int i=1;i<N;i++){
		a[i] = a[i] + sum[i];
		
		a[i+1] += (sum[i] %2)*26;
		a[i] = a[i] / 2;
	}
	//cout<<a[2];
	a[N] += (sum[N]);
	a[N] = a[N] / 2;
	for(int i=1;i<=N;i++){
		cout<<tab[a[i]];
	}
}
