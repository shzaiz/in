#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 0
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 200100
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
struct Edge{
	int to,nxt;
}e[N];
int head[N],cnt = -1;
void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
int n,m,k,a[N],ans[N],b[N],c[N],d[N],vis[N];
vector<int > G[N];
void dfs(int u){
	u = u;
}
int fa[N],an;
int find(int x){
	return x == fa[x] ? x:find(fa[x]);
}
void merge(int x,int y){
	int xx = find(x);
	int yy = find(y);
	if(xx == yy) return;
	--an;
	fa[xx] = yy;
}
void add(int x,int y){
	
	if(!d[x] && !d[y]){
		deb printf("Add %d %d\n",x,y);
		merge(x,y);
		return;
	}
	G[x].push_back(y);
	G[y].push_back(x);
}

int main(){
	memset(head,-1,sizeof head);
	realfl freopen("P197.in","r",stdin);
	realfl freopen("P197.out","w",stdout);
	cin>>n>>m;
	fo(i,m) cin>>a[i]>>b[i];
	cin>>k;
	fo(i,k) {
		cin>>c[i];
		d[c[i]] = 1;
	}
	an = n-k;
	fo(i,m){
		add(a[i],b[i]);
		if(d[a[i]] || d[b[i]]) continue;
		else{
			deb printf("Add %d -> %d\n",a[i],b[i]);
			adde(a[i],b[i]); adde(b[i],a[i]);
		}
	}
	 
	fo(i,n){
		 if(!vis[i] && !d[i]){
		 	deb printf("Not vis %d\n",i);
		 	dfs(i);
		 	ans[k+1]++;
		 }
	}
	ans[k+1]=an;
	fo(ii,999-1) fa[ii] = ii;
	for(int i = k;i>=1;--i){
		d[c[i]] = 0;
		++an;
		for(int j = 0;j<(int)G[c[i]].size();++j){
			if(!d[G[c[i]][j]]) {
				merge(c[i],G[c[i]][j]);
				deb printf("Here an :%d\n",an);
			}
		}
		ans[i]  = an;
	}
	fo(i,k+1) cout<<ans[i]<<endl;
	return 0;
}

