#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct Edge{
	int to,nxt;
}e[N];
int cnt = 0, head[N];
void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
int s[N],tp = 0;
int ind[N] , oud[N],ans[N],tpmx = 0;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout); 
	int m,n;
	cin>>m>>n;
	for(int i = 0;i<n;i++){
		int x,y;cin>>x>>y; adde(x,y);
		ind[y]++; oud[x]++;
	}	
	for(int i = 1;i<=m;i++){
		if(ind[i]==0){
			s[++tp] = i;
		}
	}
	while(tp){
		printf("%d\n",tp);
		int u = s[tp];
		tp--;
		for(int i = head[u];i;i = e[i].nxt){
			int v = e[i].to;
			ind[v]--;
			ans[++tpmx] = v;
			if(ind[v]==0) s[++tp] = v;
		}
	}
	for(int i = 1;i<=tpmx;i++) cout<<ans[i]; 

	return 0;

}
