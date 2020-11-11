#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define int long long
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 5000105
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define mid (l+r)/2
int n,m;
int a[N],maxx[N],sum[N];
void pushup(int o){
	maxx[o] = max(maxx[ls(o)],maxx[rs(o)]);
	sum[o] = sum[ls(o)]+sum[rs(o)];
}
void build(int o,int l,int r){
	if(l==r){
		sum[o] = maxx[o] = a[l];
		return ;
	
	}
	build(ls(o),l,mid);
	build(rs(o),mid+1,r);
	pushup(o);
}

void sq(int o,int l,int r,int L,int R){
	if(l== r && L<=l && r<=R) {
		sum[o] = maxx[o] =sqrt(sum[o]);
		return ;
	}
	if(L<=mid && maxx[ls(o)]>1) sq(ls(o),l,mid,L,R);
	if(mid <R&& maxx[rs(o)]>1) sq(rs(o),mid+1,r,L,R);
	pushup(o);
}

int query(int o,int l,int r,int L,int R){
	if(L<=l && r<=R){
		return sum[o]; 
	}
	int ans = 00;
	if(L<=mid) ans+=  query(ls(o),l,mid,L,R);
	if(mid<R) ans+=  query(rs(o),mid+1,r,L,R);
	return ans;
	pushup(o);
}

signed main(){
	realfl freopen("P2023.in","r",stdin);
	realfl freopen("2023.out","w",stdout);
	cin>>n;
	fo(i,n) cin>>a[i];
	build(1,1,n);
	cin>>m;
	while(m--){
		int op,l,r;
		cin>>op>>l>>r;
		if(l>r) swap(l,r);
		if(op == 0) sq(1,1,n,l,r);
		else cout<<query(1,1,n,l,r)<<endl;
	}
	return 0;
}

