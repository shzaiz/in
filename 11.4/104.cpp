#include <bits/stdc++.h>
using namespace std;
#define ls(o) o<<1
#define rs(o) o<<1 | 1
#define sz(x) r[x]-l[x]+1
#define mid (ll+rr)/2
#define deb if(using_debug_output)
#define fil if(using_file_is_okay)
#define realfl if(this_is_a_real_file_output)
#define int long long
const int N = 1000005<<4;
const bool using_debug_output = 0;
const bool using_file_is_okay = 0;
const bool this_is_a_real_file_output = 1;
int l[N],r[N],sum[N],lz[N],a[N];
int Q,n;
void pushup(int o){
	sum[o] = sum[ls(o)]+ sum[rs(o)];
}
void pushdn(int o,int ln,int rn){
	if(lz[o]){
		sum[ls(o)] += lz[o]*ln;
		sum[rs(o)] += lz[o]*rn;
		lz[ls(o)] += lz[o];
		lz[rs(o)] += lz[o];
		lz[o] = 0;
	}
}

void build(int o,int ll,int rr){
	l[o] = ll, r[o] = rr, lz[o] = 0;
	if(ll==rr) {sum[o] = a[rr],l[o] = ll,r[o] = rr,lz[o] = 0;return;}
	build(ls(o),ll,mid);
	build(rs(o),mid+1,rr);
	pushup(o);
} 

int query(int o,int ll,int rr,int L,int R){
	int ans =0;
	if(L<=ll && rr<=R) return sum[o];
	pushdn(o,mid-ll,rr-mid+1);
	if(L<=mid) ans+= query(ls(o),ll,mid,L,R);
	if(mid<R) ans+= query(rs(o),mid+1,rr,L,R);
	pushup(o);
	return ans;
}

void add(int o,int ll,int rr,int L,int R,int c){
	if(L<=ll && rr<=R) {
		sum[o] += sz(o)*c;
		lz[o] += c;
		return ;
	}
	pushdn(o,mid-ll,rr-mid+1);
	if(L<=mid) add(ls(o),ll,mid,L,R,c);
	if(mid<R) add(rs(o),mid+1,rr,L,R,c);
	pushup(o);
}



signed main(){
	fil freopen("D:\\Testcases\\in.ac","r",stdin);
	fil freopen("D:\\Testcases\\out.ac","w",stdout);
	realfl freopen("104.in","r",stdin);
	realfl freopen("104.out","w",stdout); 
	cin>>n>>Q;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	while(Q--){
 	    int op;cin>>op;
 		if(op==1){
 			int x,val;cin>>x>>val;
 			add(1,1,n,x,x,val);
	    }else {
	    	int x,y;cin>>x>>y;
	    	cout<<query(1,1,n,x,y)<<endl;
		}
	}
	
}
