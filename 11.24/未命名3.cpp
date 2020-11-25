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
int mp[N][N],res[N],used[N];
bool find(int x){
	for(int i = 1;i<=n;i++) {
		if(mp[x][i] && !used[i]){
			used[i] = 1;
			if(!res[i] || find(mp[x][i])){
				res[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int n,m;cin>>n>>m;
	fo(i,n) cin>>a[i];
	
	return 0;
}

