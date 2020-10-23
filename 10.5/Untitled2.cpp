#include <bits/stdc++.h>
#include <set>
using namespace std;
#define N 500505
#define ll long long
int a[N],b[N];
int ta[N],tb[N];
int n;
int main(){
	ll n;cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	sort(b+1,b+n+1);
	ll maxl = b[n/2];
	ll minr = b[n/2+1];
	ll ls = 0;
	for(int i = 1;i<=n/2;i++){
		if(a[i]>maxl) ls+= i;
	}
	ll rs = 0;
	for(int i = n/2+1;i<=n;i++){
		if(a[i]<minr) rs+= i;
	}
	cout<<rs-ls<<endl;
	
	return 0;
}
