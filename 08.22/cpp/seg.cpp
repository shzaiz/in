#include <bits/stdc++.h>
#define ls o<<1
#define rs o<<1|1
#define mid (l+r)/2
#define s(x) (tree[(x)].r - tree[(x)].l +1)
using namespace std;
int a[10010]={0,1,2,3,10,5};
struct tre{
	int l,r,sum,lz;
}tree[999999];

void pushdn(int o){
	if(tree[o].lz!=0){
		
		tree[ls].lz += tree[o].lz;tree[rs].lz += tree[o].lz;
		tree[ls].sum += tree[ls].lz*s(ls);
		tree[rs].sum += tree[rs].lz*s(rs);
	}
}

void build(int o,int l,int r){
	tree[o].l = l; tree[o].r = r;
	if(l==r){
		tree[o].sum = a[l];
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	tree[o].sum = tree[ls].sum+tree[rs].sum;
}
int query(int o,int l,int r){
	if(l<=tree[o].l && r>= tree[o].r) return tree[o].sum;
	if(tree[o].r<l || tree[o].l >r) return 0;
	
	int s = 0;
	if(tree[ls].r>=l) s += query(ls,l,r);
	if(tree[rs].l<=r) s += query(rs,l,r);
	return s; 
}

void add(int o,int l,int r,int d){
	if(l<=tree[o].l && r>= tree[o].r) {
		tree[o].sum += s(o)*d;
		tree[o].lz += d; 
	}
	if(tree[o].r<l || tree[o].l >r) return;
	
	if(tree[ls].r>=l) add(ls,l,r,d);
	if(tree[rs].l<=r) add(rs,l,r,d);
}

int main(){
	build(1,1,5);
	add(1,1,3,1);
	cout<<query(1,1,3);
}
