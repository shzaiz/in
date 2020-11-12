#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define int unsigned long long
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
int C(int x){
	return x*(x-1)*(x-2)/6;
}
signed main(){
	freopen("nmtg.in","r",stdin);
	freopen("nmtg.out","w",stdout);
	int n,m;cin>>n>>m;
	int ans = C((n+1)*(m+1))-(n+1)*C(m+1)-(m+1)*C(n+1);
	fo(i,n) fo(j,m){
		ans-= 2*(__gcd(i,j)-1)*(n+1-i)*(m+1-j);
	}
	cout<<ans;
	return 0;
} 
