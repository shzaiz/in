#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
//#define endl "\n"
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=1000010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
#define int ll
int n,a[N];
vector<pair<long long,long long> > s;
void Solve(){
	n=read();
	repeat(i,1,n+1)
		a[i]=read(),a[i]-=i;
	s.push_back({a[1],1});
	repeat(i,2,n+1){
		if(a[i]<s.back().first){
			s.push_back({a[i],i});
			continue;
		}
		if(a[i]==s.back().first)continue;
		while(s.size()>1 && a[i]-s.back().first>i-s.back().second){
			a[i]-=i-s.back().second;
			s.pop_back();
		}
		if(s.size()==1){
			int t=(a[i]-s.back().first)/(i-1+1);
			a[i]-=t*(i-1);
			s.back().first+=t;
		}
		if(a[i]==s.back().first)continue;
		int d=a[i]-s.back().first;
		pii t=s.back();
		if(s.size()==1)s.back().first++;
		else s.pop_back();
		s.push_back({t.first,t.second+d});
	}
	s.push_back({0,INF});
	int p=0;
	repeat(i,1,n+1){
		if(s[p+1].second==i)p++;
		printf("%lld ",s[p].first+i);
	}
	puts("");
}
signed main(){
	int T=1;
	while(T--)Solve();
	return 0;
}
