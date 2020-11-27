#include <bits/stdc++.h>
#define N 100100
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define mp make_pair
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define fi first
#define se second
#define MOD 1000000009
using namespace std;
int n,m;
pair<int ,char > c[N];
int ans = 1;
using namespace std;
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	
	cin>>n>>m;
	fo(i,m){
		char x;int y;
		cin>>x>>y;
		c[i] = mp(y,x);
	}
	sort(c+1,c+1+m);
	fo(i,m) cout<<c[i].first<<" "<<c[i].second<<endl;
	fo(i, m-1){
		if(c[i].se == c[i+1].se) continue;
		else ans = (ans%MOD*(c[i+1].fi - c[i].fi)%MOD)%MOD;
	}
	cout<<ans;
	return 0;
} 
