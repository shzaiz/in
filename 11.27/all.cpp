#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 210
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
struct Node{
	int a,b;
	bool operator<(Node z) const{
		return b>z.b;
	}
}s[N];
int sum[N],f[N][N*N];

signed main(){
	#ifndef ONLINE_JUDGE
	#endif
	int n;cin>>n;
	fo(i,n) cin>>s[i].a>>s[i].b;
	sort(s+1,s+1+n);
	fo(i,n) sum[i] = sum[i-1]+s[i].a;
	memset(f,127,sizeof f);
	f[0][0] = 0;
	fo(i,n) fo(j,sum[i]){
		if(j>=s[i].a) f[i][j] = min(f[i][j],max(f[i-1][j-s[i].a],j+s[i].b));
		f[i][j] = min(f[i][j],max(f[i-1][j],sum[i]-j+s[i].b));
	} 
	int ans = 9e9;
	fo_(i,0,sum[n]){
		ans = min(ans,f[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}

