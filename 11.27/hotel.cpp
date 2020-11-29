#include <bits/stdc++.h>
#define mid (l+r>>1)
#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
using namespace std;
const int maxn=50000+10;
int n,m;

struct node{
	int sum,lmax,rmax,lazy,len;
	
}tree[maxn<<2];
#define lson (rt<<1)
#define rson (rt<<1|1)
#define sum(rt) tree[rt].sum
#define lmax(rt) tree[rt].lmax
#define rmax(rt) tree[rt].rmax
#define lazy(rt) tree[rt].lazy
#define len(rt) tree[rt].len
void pushup(int rt){
	lmax(rt)=(lmax(lson)==len(lson))?len(lson)+lmax(rson):lmax(lson);
	rmax(rt)=(rmax(rson)==len(rson))?len(rson)+rmax(lson):rmax(rson);
	sum(rt)=max(rmax(lson)+lmax(rson),max(sum(lson),sum(rson)));
}

void pushdown(int rt){
	if(!lazy(rt)) return ;
	lazy(lson)=lazy(rson)=lazy(rt);
	sum(lson)=lmax(lson)=rmax(lson)=(lazy(rt)==1)?len(lson):0;
	sum(rson)=lmax(rson)=rmax(rson)=(lazy(rt)==1)?len(rson):0;
	lazy(rt)=0;
}

void build(int l,int r,int rt){
	sum(rt)=lmax(rt)=rmax(rt)=len(rt)=r-l+1;
	if(l == r) return ;
	build(l,mid,lson);
	build(mid+1,r,rson);
}

void update(int L,int R,int tag,int l,int r,int rt){
	if(L <= l && r <= R){
		sum(rt)=lmax(rt)=rmax(rt)=(tag==1)?len(rt):0;
		lazy(rt)=tag;
		return ;
	}
	pushdown(rt);
	if(L <= mid) update(L,R,tag,l,mid,lson);
	if(R > mid) update(L,R,tag,mid+1,r,rson);
	pushup(rt);
}

int query(int len,int l,int r,int rt){
	if(l == r) return l;
	pushdown(rt);
	if(sum(lson)>=len) return query(len,l,mid,lson);
	if(rmax(lson)+lmax(rson)>=len) return mid-rmax(lson)+1;
	return query(len,mid+1,r,rson);
}

int main()
{
	scanf("%d%d",&n,&m);
	build(1,n,1);
	int opt,l,x;
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&x);
			if(sum(1)>=x){
				l=query(x,1,n,1);
				printf("%d\n",l);
				update(l,l+x-1,2,1,n,1);
			}
			else printf("0\n");
		}
		else {
			scanf("%d%d",&l,&x);
			update(l,l+x-1,1,1,n,1);
		}
	}
	return 0;
}
