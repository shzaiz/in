#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 5000010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
#define ls(o) o<<1
#define rs(o) o<<1|1
#define mid (l+r)/2
#define x1 fdffffff
#define int long long
#define x2 fdhfs
#define y1 fhoidsiho
#define y2 hiosfoihsdh
int n,cnt = 0;
int x1,y1,x2,y2,X[N];
struct SL{
	int l,r,h,mark;
	bool operator<(SL &rhs) const{
	return h<rhs.h;}
}line[N] ; 
struct Seg{
	int l=0,r=0,sum=0,len=0;
}t[N];
void pushup(int o){
	int l = t[o].l, r = t[o].r;
	if(t[o].sum){
		t[o].len = X[r+1]-X[l];
	}else{
		t[o].len = t[ls(o)].len+t[rs(o)].len;
	}
}

void build(int o,int l,int r){
	t[o].l = l; t[o].r = r; t[o].len = 0, t[o].sum = 0;
	if(l == r) return ;
	build(ls(o),l,mid);
	build(rs(o),mid+1,r);
	
}

void add(int o,int L,int R,int c){
	int l = t[o].l, r = t[o].r;
	if(X[r + 1] <= L || R <= X[l]) return;
	if(L<=X[l] && X[r+1]<=R){
		t[o].sum += c;
		pushup(o);
		return;
	}
	 add(ls(o),L,R,c);
	 add(rs(o),L,R,c);
	pushup(o);
}


signed main(){
	#ifndef ONLINE_JUDGE
	freopen("5490.in","r",stdin);
	#endif
	cin>>n;
	fo(i,n){
		cin>>x1>>y1>>x2>>y2;
		X[(i<<1)-1] = x1, X[i<<1]=x2;
		line[(i<<1)-1] = (SL){x1,x2,y1,1};
		line[i<<1] = (SL){x1,x2,y2,-1};
	}
	n<<=1;
	sort(line+1,line+n+1);
	sort(X+1,X+n+1);
	int tot = unique(X+1,X+n+1)-X-1;
	build(1,1,tot-1);
	int ans = 0;
	fo(i,n-1){
		add(1,line[i].l,line[i].r,line[i].mark);
		ans+= t[1].len*(line[i+1].h-line[i].h);
	}
	cout<<ans;
	
	return 0;
}

