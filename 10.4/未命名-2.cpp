#include <bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
int n;
int head[N],cnt=0,d[N],p[N][21],a[N][21],b[N][21],A[N],B[N];
namespace lian{
	int n,m;
	int a[N],b[N],A[N],B[N];
	void feed(int tot,int ask){
		n = tot,m=ask;
	}
	void ask(int s,int t){
		ll ans = 0;
		for(int i = s;i<t;i++){
			ans+= a[i]*(B[t]-B[i]);
		}
		cout<<ans;
	}
	int mian(){
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		for(int i = 1;i<=n;i++){
			cin>>b[i];
		}
		A[1] = a[1];B[1] = b[1];
		
		for(int i = 2;i<=n;i++){
			B[i] = B[i-1]+b[i];
			A[i] = A[i-1]+a[i];
		}
		for(int i = 1;i<=m;i++){
			int lf,rg;
			cin>>lf>>rg;
			ask(lf,rg);
			printf("\n");
		}
		return 0;
	}
	
}

struct Edge{
	int to,nxt,w;
	
}e[N];
void dfs(int u,int fa){
    d[u]=d[fa]+1;
    p[u][0]=fa;
    for(int i=1;(1<<i)<=d[u];i++)
        p[u][i]=p[p[u][i-1]][i-1];
        
    for(int i=head[u];i!=0;i=e[i].nxt){
        int to=e[i].to;
        if(to!=fa)
            dfs(to,u);
    }
}

void adde(int u,int v){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
int lca(int a,int b){
    if(d[a]>d[b])
        swap(a,b);
    for(int i=20;i>=0;i--)
        if(d[a]<=d[b]-(1<<i))
            b=p[b][i];
    if(a==b)
        return a; 
    for(int i=20;i>=0;i--){
        if(p[a][i]==p[b][i])
            continue;
        else
            a=p[a][i],b=p[b][i];
    }
    return p[a][0];
}
int _a[N],_b[N],tp=0;
void ask(int x,int y){
	tp = 0;
	memset(_a,0,sizeof _a);memset(_b,0,sizeof _b);
	int LCA = lca(x,y);
	ll dis = d[x]+d[y]-2*d[LCA]+1;
	while(x!=LCA){
		_a[++tp] = a[x][0];
		_b[tp] = b[x][0];
		x = p[x][0];
	}
	int hp = dis;
	// printf("Dis:%d\n",dis);
	while(y!=LCA){
		_a[hp--] = a[y][0];
		_b[hp+1] = b[y][0];
		y = p[y][0];
	}
	_a[++tp] = a[LCA][0];
	_b[tp] = b[LCA][0];
	A[1] = _a[1];B[1] = _b[1];
	for(int i = 2;i<=dis;i++){
		// printf(" %d+%d\n",B[i-1],_b[i]);
		B[i] = B[i-1]+_b[i];
		A[i] = A[i-1]+_a[i];
	}
	ll ans = 0;
	for(int i = 1;i<dis;i++){
		ans+= _a[i]*(B[dis]-B[i]);
	}
	cout<<ans<<"\n";
	// for(int i = 1;i<=dis;i++){
		// cout<<A[i]<<" ";
	// }
	// cout<<"\n";
	// for(int i = 1;i<=dis;i++){
		// cout<<B[i]<<" ";
	// }
}
int main(){
	int n,m;cin>>n>>m;
	bool lian = true;
	for(int i = 2;i<=n;i++){
		int x;cin>>x;adde(x,i);adde(i,x);
		// printf("Add %d<-->%d\n",i,x);
		if(x != i-1) lian = 0;
	}
	if(lian){
		lian::feed(n,m);
		lian::mian();
	}else{
		for(int i = 1;i<=n;i++){
			cin>>a[i][0];
		}
		for(int i = 1;i<=n;i++){
			cin>>b[i][0];
		}
		dfs(1,0);
		for(int i = 1;i<=m;i++){
			memset(_a,0,sizeof _a);
			memset(_b,0,sizeof _b);
			memset(A,0,sizeof A);
			memset(B,0,sizeof B);
			int l,r;cin>>l>>r;
			ask(l,r);
		}
	}
	return 0;
}