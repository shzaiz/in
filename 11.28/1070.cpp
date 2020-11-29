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
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
int n,m,p;
int pa[1001],mn[1001][1001],f[1001];
 
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("1070.in","r",stdin);
	#endif
	cin>>n>>m>>p;
	memset(f,-999999,sizeof f);
	f[0] = 0;
	fo(i,n) fo(j,m) cin>>mn[i][j];
	fo(i,n) cin>>pa[i];
	fo(i,m) fo(j,n) {
		int ff = j-1;
		if(!ff) ff = n;
		int ss = mn[ff][i];
		fo(k,p){
			if(i-k<0) break;
			f[i] = max(f[i],f[i-k]+ss-pa[ff]);
			ff--;
			if(!ff) ff = n;
			ss+= mn[ff][i-k];
		}
	}
	cout<<f[m];
	return 0;
}

