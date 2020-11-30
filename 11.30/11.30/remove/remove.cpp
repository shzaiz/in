#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 1;i<=n;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define fl(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define N 10005
#define fi first
#define se second
int fa[N];
void init(int n){
	fo_(i,0,n) fa[i] = i;
}
int find(int x){
	return (x== fa[x]) ? x: (fa[x] = find(fa[x]));
}
void merge(int x ,int y){
	int xx = find(x);
	int yy = find(y);
	if(xx==yy){
		return;
	}
	fa[yy] = xx;
}
bool isin(int x,int y){
	return find(x) == find(y);
}
signed main(){
	fl("remove");
	int n;
	cin>>n;
	init(n+5);
	fo(i,n){
		int x,y;
		cin>>x>>y;
		if(!isin(x,y)) merge(x,y);
		else{
			cout<<i<<endl;
			return 0;
		}
		
	}
}
