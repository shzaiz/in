#include <bits/stdc++.h>
using namespace std;
#define N 5000005
#define int unsigned long long
#define fo(i,x) for(register int i =1;i<=x;++i)
int a[N],b[N],n;
signed main(){
	freopen("D:\\in.in","r",stdin);
	freopen("D:\\out.out","w",stdout);
	cin>>n;
	fo(i,n) cin>>a[i];
	fo(i,n){
		cin>>b[i];
		int ans = 0;
		fo(j,i){
			if(a[j] == 0) continue;
			else if(a[j]>=b[i]){
//				printf("Melting some\n");
				 ans += b[i];
				 a[j] -= b[i]; 
			} 
			else if(a[j]<b[i]){
//				printf("Melting all %d %d\n",a[j],b[i]);
				ans+= a[j];
				a[j]= 0;
			}
		}
		cout<<ans<<" ";
	}
}
