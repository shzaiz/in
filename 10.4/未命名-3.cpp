#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n;
namespace lian{
	int n,m;
	int a[N],b[N],A[N],B[N],c[N];
	void feed(int tot,int ask){
		n = tot,m=ask;
	}
	void ask(int s,int t){
		int ans = 0;
		ans = (A[t-1]-A[s])*(B[t]-B[])
		cout<<ans;
	}
	int mian(){
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		for(int i = 1;i<=n;i++){
			cin>>b[i];
		}
		A[1] = a[1];B[1] = b[1];C[1] = a[1]*a[1];
		
		for(int i = 2;i<=n;i++){
			B[i] = B[i-1]+b[i];
			A[i] = A[i-1]+a[i];
			C[i] = C[i-1]+(a[i]*a[i])
		}
		for(int i = 1;i<=m;i++){
			int lf,rg;
			cin>>lf>>rg;
			ask(lf,rg);
			printf("\n");
		}
	}
	
}
struct Edge{
	int to,nxt,w;
	
}e[N];
int head[N],cnt=0;
void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

int main(){
	int n,m;cin>>n>>m;
	bool lian = true;
	for(int i = 2;i<=n;i++){
		int x;cin>>x;adde(x,i);adde(i,x);
		if(x != i-1) lian = 0;
	}
	if(lian){
		lian::feed(n,m);
		lian::mian();
	}
	
	return 0;
}