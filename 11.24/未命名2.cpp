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
using namespace std;

typedef long long ll;
const int maxn=4004;
struct edge{
	int v,nxt;
}e[maxn*16];
int n,m,cnt=0;
int result[maxn][2],use[maxn];
int head[maxn];

void add_edge(int u,int v){
	++cnt;
	e[cnt]=(edge){v,head[u]};
	head[u]=cnt;
}

bool dfs(int now){
	
	for(int j=head[now];j;j=e[j].nxt){
		int v=e[j].v;
		if(!use[v]){
		use[v]++;
		if(!result[v][0]||dfs(result[v][0])){
			result[v][0]=now;
			return true;
		}
		if(!result[v][1]||dfs(result[v][1])){
			result[v][1]=now;
			return true;
		}
	}
	}
		
	
	return false;
}

int xiongyali(){
	int ans=0;
	for(int i=1;i<=n*2;i++){
		memset(use,0,sizeof(use));
		if(dfs(i))ans++;
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++){
		int a,b;scanf("%d%d",&a,&b);
		add_edge(i,a);
		add_edge(i,b);
	}
	printf("%d\n",xiongyali());
}

