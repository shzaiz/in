#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define ls(o) (o<<1)
#define rs(o) (o<<1|1)
#define mid ((ll+rr)/2)
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
int n,op,data[N],d[N];
int l[N],r[N],lz[N],sum[N];
void pushup(int o){
	sum[o] = sum[ls(o)]+sum[rs(o)];
}
void pushdn(int o,int ln,int rn){
	if(lz[o]){
		sum[ls(o)]+= ln*lz[o];
		sum[rs(o)]+= rn*lz[o];
		lz[ls(o)] += lz[o];
		lz[rs(o)] += lz[o];
		lz[o] = 0;
	}
}

void build(int o,int ll,int rr){
	l[o] = ll, r[o] = rr, lz[o] = 0; 
	if(ll == rr){
		sum[o] = data[ll];
		return;
	}
	build(ls(o),ll,mid);
	build(rs(o),mid+1,rr);
	pushup(o);
}
void add(int o, int ll,int rr,int L,int R,int c){
	if(L<=ll && rr<=R) {
		lz[o] += c;
		sum[o] += (rr-ll+1)*c;
		return; 
	}
	pushdn(o,mid-ll+1,rr-mid);
	if(L<=mid)add(ls(o),ll,mid,L,R,c);
	if(mid<R)add(rs(o),mid+1,rr,L,R,c);
	pushup(o);
}
int query(int o,int ll,int rr,int L,int R){
	if(L<=ll && rr<=R) return sum[o];
	pushdn(o,mid-ll+1,rr-mid);
	int ans = 0;
	if(L<=mid) ans+= query(ls(o),ll,mid,L,R);
	if(mid<R) ans+= query(rs(o),mid+1,rr,L,R);
	pushup(o);
	return ans;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("seg.in","r",stdin);
	freopen("seg.out","w",stdout);
	#endif
	int n,m,opt,l,r,k,d,t;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    for(int i=n-1;i>0;i--)
        data[i+1]=data[i+1]-data[i];
    build(1,1,n);
    for(int i=0;i<m;i++){
        cin>>opt;
        if(opt==1){
            cin>>l>>r>>k>>d;
            add(1,1,n,l,l,k);
            if(l+1<=r)add(1,1,n,l+1,r,d);
            if(r<n)add(1,1,n,r+1,r+1,-(k+d*(r-l)));
        }
        else{
            cin>>t;
            cout<<query(1,1,n,1,t)<<endl;
        }
        
    }
    return 0;
}

