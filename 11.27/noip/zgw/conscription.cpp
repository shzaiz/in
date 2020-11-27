#include <bits/stdc++.h>
using namespace std;
#define  N 50050
#define fo(i,n) for(int i = 1 ;i<=n;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define rep(i,b,a) for(int i = b ;i>=a;i--)
#define int long long
int a[N],fa[N],n,m,r,ans =0 ;
void init(int n){
	for(int i  =1;i<=n;i++) fa[i ] = i;
}
int find(int x){
	return (fa[x] == x) ?  fa[x]:(fa[x] = find(fa[x])) ;
} 
int isin(int a,int b){
	int xx = find(a);
	int yy = find(b);
	if(xx == yy) return 1;
	else return 0;
}
void merge(int x,int y){
	int xx = find(x);
	int yy = find(y);
	if(xx!=yy){
		fa[xx] = yy;
	}
}
struct Edge{
	int frm,to,w;
}e[N];
bool cmp(Edge a,Edge b){
	return a.w>b.w;
}
void kus(){
	sort(e+1,e+1+n,cmp);
	for(int i = 1;i<=r;i++){
		if(!isin(e[i].frm,e[i].to)){
			ans+= e[i].w;
			merge(e[i].frm,e[i].to);
//			cout<<ans<<endl;
		}
	}
}
void solve(){
	ans = 0;
	n = 0, m = 0;
	memset(fa,0,sizeof fa);
	for(int i = 0;i<N;i++){
		e[i].frm = 0, e[i].to = 0;e[i].w = 0;
	}
	init(N-1);
	cin>>n>>m>>r;
	for(int i = 1;i<=r ; i++){
		cin>>e[i].frm>>e[i].to>>e[i].w;
		e[i].to += n;
	}
	kus();
	cout<<((n+m)*10000-ans)<<endl;
	
}
signed main(){
	freopen("conscription.in","r",stdin);
	freopen("conscription.out","w",stdout);
	int T;cin>>T;while(T--) solve();
	return 0;
} 
