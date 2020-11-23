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
struct Edge{
	int to,nxt,w;
}e[N];
int head[N],cnt = 0,mx[N];
void adde(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	e[cnt].w= w;
	head[u] = cnt;
}
int n,rt;
int ans = 0;
void dfs(int u,int fa){
	
}
int main(){
	realfl freopen("shitai.in","r",stdin);
	realfl freopen("shitai.out","w",stdout);
	cin>>n>>rt;
	fo(i,n) {
		int x,y,z; cin>>x>>y>>z;
		adde(x,y,z);
	}
	
	return 0;
}

