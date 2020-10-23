#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
static char buf[100000],*pa,*pd;
const int N=1100000;
struct edge{
 	int to,next;
}e[N];
int head[N],tot;
void add(int x,int y){
 	e[++tot].next=head[x];e[tot].to=y;head[x]=tot;
} 
#define ll long long 
ll ans,val[N];
int n,po[N];
priority_queue<ll> son[N];
ll now[N];
int cnt;
void dfs(int u){
	po[u]=u;
 	for(int i=head[u];i;i=e[i].next){
		dfs(e[i].to);
	 	if(i==head[u]){
		 	po[u]=po[e[i].to];
		} 
		else{
		 	if(son[po[u]].size()<son[po[e[i].to]].size())swap(po[u],po[e[i].to]);
			cnt=0;
			while(!son[po[e[i].to]].empty()){
				now[++cnt]=max(son[po[e[i].to]].top(),son[po[u]].top());son[po[u]].pop();son[po[e[i].to]].pop();
			}
			for(int j=1;j<=cnt;j++)
				son[po[u]].push(now[j]);
		} 
	}
	son[po[u]].push(val[u]);
} 
int main(){
	cin>>n;
	register int i;
	for(i=1;i<=n;i++)cin>>val[i];
	for(i=2;i<=n;i++){
	 	int fa;cin>>fa;add(fa,i);
	} 
	dfs(1);
	while(!son[po[1]].empty()){
		ans+=son[po[1]].top();son[po[1]].pop();
	}
	cout<<ans;
	return 0;
} 
