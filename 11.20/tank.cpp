#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 0
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
#define clock ccclllloooccckkk
struct Edge{
	int to,nxt,w;
}e[N];
int fr[N],to[N],w[N],vis[N];
int n,m;
int head[N],cnt = 0;
void adde(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	e[cnt].w = w;
	head[u] = cnt;
}
int t = 0;
int low[N],dfn[N],clock,scccnt=0,s[N],tp,ins[N];
void reset(){	
	memset(low,0,sizeof low);
	memset(dfn,0,sizeof dfn);
	memset(s,0,sizeof s);
	clock=0;
	scccnt=0;
	memset(ins,0,sizeof ins);
	tp=0;
	memset(head,0,sizeof head);
	memset(vis,0,sizeof vis);
	cnt = 0;
	t = 0;
}

void tarjan(int u){
	low[u] = dfn[u] = ++clock;ins[u] = 1; s[++tp] = u;
	for(int i = head[u];i;i = e[i].nxt){
		int v = e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[v],low[u]); 
		}else{
			low[u] = min(low[u],dfn[v]);
		} 
	}
	if(dfn[u]==low[u]){
		scccnt++;
		int x;
		do{	
			x = s[tp--];
			ins[x]=0;
		}while(x!=u);
	}
}
bool check(int vi){
	reset();
	fo(i,m)if(w[i]<=vi){
		 adde(fr[i],to[i],w[i]);
		 deb printf("Added %d %d %d\n",fr[i],to[i],w[i]);
	}
	fo(i,n) if(!dfn[i]) tarjan(i);
	if(scccnt == 1) return true;
	else return false;
}
int main(){
	#ifdef XBBZAKIOI 
	freopen("tank.in","r",stdin);
	freopen("tank.out","w",stdout);
	#endif
	int ub = -1;
	cin>>n>>m;
	fo(i,m) cin>>fr[i]>>to[i]>>w[i],ub = max(ub,w[i]);
	int r = ub, l = 0,mid,ans = -1;
	while(l<=r){
		mid = (l+r)/2;
		deb cout<<l<<" "<<mid<<" "<<r<<endl;
		if(check(mid)){
			deb cout<<"Checked!";
			r=mid-1;
			ans = mid;
		}else{
			l = mid+1;
		}
	}
//	cout<<l<<" "<<mid<<" "<<r<<endl;
//	cout<<check(4);
	cout<<ans<<endl;
	return 0;
} 
