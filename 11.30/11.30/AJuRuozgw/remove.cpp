#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 1;i<=n;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define fl(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define N 100015
#define fi first
#define se second
using namespace std;
int n,frm,v,num,ans,tot,top,root,st;
int du[N],sta[N],low[N],dfn[N],head[N],a[N],b[10];
bool vis[N];
priority_queue<int>q;
struct node{
	int frm,to,nxt;
}e[N*2];
void add(int x,int y){
	e[++tot].to = y;
	e[tot].frm = x;
	e[tot].nxt = head[x];
	head[x] = tot;
}
void tarjan(int x){
	dfn[x] = low[x] = ++num;
	sta[++top] = x; vis[x] = 1;
	for(int i = head[x]; i; i = e[i].nxt){
		int to = e[i].to;
		a[to] = i;
		if(!dfn[to]){
			tarjan(to);
			low[x] = min(low[x],low[to]);
		}else if(vis[to]){
			low[x] = min(low[x],dfn[to]);
		}
	}
	if(dfn[x] == low[x]){
		int y;
		do{	
			y = sta[top--];
			q.push(a[y]);
			vis[y] = 0;
		}while(x != y);
	}
	if(q.size() > 1) ans = max(ans,q.top());
	while(!q.empty()) q.pop();
}
void dfs(int x){
	vis[x] = 1;
	for(int i = head[x]; i; i = e[i].nxt){
		int to = e[i].to;
		if(to == st) continue;
		dfs(to);
	}
}
int main(){
	fl("remove");
    cin>>n;
    bool flag = 0;
    for(int i = 1; i <= n; i++){
    	cin>>frm>>v;
    	add(frm,v);
    	du[v]++;
    	if(du[v] == 2){flag = 1; st = v;}
    }
    if(flag == 1){
    	for(int i = 1; i <= n; i++) if(!du[i]) root = i;
    	dfs(root);
    	for(int i = 1; i <= n; i++) if(e[i].to == st) b[++num] = i;
    	if(!vis[e[b[1]].frm]) ans = b[1];
    	else{
    		if(!vis[e[b[2]].frm]) ans = b[2];
    		else ans = max(b[1],b[2]);
		}
    }
    else{
    	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
    }
    printf("%d\n",ans);
    return 0;
}

