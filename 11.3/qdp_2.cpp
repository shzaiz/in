#include <bits/stdc++.h>
#define ____debug_____ 1
#define deb if(____debug_____)
#define N 1005
#define fo(i,b,x) for(register int i =b;i<=x;++i)
using namespace std;
#define D double
#define ll long long
int n,a[N],S[N],f[N][N];D ans=-1;
D calc(D a,D b,D c){
	D p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
bool tran(D a, D b,D c){
	if(a+b>c && b+c>a && a+c>b) return 1;
	else return 0; 
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("D:\\Testcases\\in.ac","r",stdin);
	freopen("D:\\Testcases\\out.ac","w",stdout);
	#endif 
	cin>>n;
	fo(i,1,n) cin>>a[i];
	S[1] = a[1];
	fo(i,2,n) S[i] = S[i-1]+ a[i];
	f[0][0] = 1;
	fo(i,1,n){
		for(int j = S[n]/2;j>=0;j--){
			for(int k = S[n]/2;k>=0;k--){
				if(j-a[i] >= 0 && f[j-a[i]][k]) f[j][k] = 1;
				if(k-a[i] >= 0 && f[j][k-a[i]]) f[j][k] = 1;
			}
		}
	}
	int m = S[n];
	for(ll i=m/2;i>0;i--)
	for(ll j=m/2;j>0;j--){
    	if(!f[i][j]) continue;
       	if(!tran(i,j,m-i-j)) continue;
    	ans=max(ans,calc(i,j,m-i-j)); 
    }	
    if(ans == -1) {cout<<"-1" ; return 0;
	}
	cout<<(int)(ans*100);
	
	
}
