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
int a[N],pre[N],head[N],n,m,q,cnt = 1;
int s,t,j,flow,p;
struct Edge{
	int to,nxt,flow;
}e[N];
void add(int u,int v,int w){
	e[++cnt].flow = w;
	e[cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt; 
}
bool bfs(){
	queue<int > Q;
	memset(a,0,sizeof a);
	Q.push(s);
	while(!Q.empty()){
		int u  =Q.front();Q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			int v = e[i].to;
			if(!e[i].flow) continue;
			if(a[v]) continue;
			a[v] = min(a[u],e[i].flow);
			pre[v] = i;
			Q.push(v);
		}
	}
	if(!a[t]) return 0;
	flow += a[t];
	return 1;
}
void upd(){
	int m = t;
	for(;pre[m];m=e[pre[m]^1].to){
		e[pre[m]].flow -=a[t]; e[pre[m]^1].flow += a[t];
	}
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("1402.in","r",stdin);
	#endif
	s = 2*n+p+q+1,t = s+1;
	fo(i,n){
		for(int x,j=1;j<=p;j++){
            scanf("%d",&x);
            if(x^1) continue;
            add(j,p+i,1);
            add(p+i,j,0);
        }
	}
	for(int i=1;i<=n;i++){
        for(int x,j=1;j<=q;j++){
            scanf("%d",&x);
            if(x^1) continue;
            add(p+n+q+i,p+n+j,1);
            add(p+n+j,p+n+q+i,0);
        }
    }
    for(int i=1;i<=n;i++) add(p+i,p+n+q+i,1),add(p+n+q+i,p+i,0);
    for(int i=1;i<=p;i++) add(s,i,1),add(i,s,0);
    for(int i=p+1+n;i<=p+n+q;i++) add(i,t,1),add(t,i,0);
    while(bfs()) upd();
    printf("%d",flow);
	return 0;
}

