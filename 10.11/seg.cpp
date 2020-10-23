// 今天研究线段树相关的内容;
#include <bits/stdc++.h>
#define N 100010
#define ls(x) (x)<<1
#define rs(x) (x)<<1 | 1
#define sz(x) t[(x)].r - t[(x)].l +1
#define mid (l+r)/2
using namespace std;
int a[N];
int n,m;
struct Seg{
    int l,r,sum,lz;
}t[N];
void pushup(int o){
    t[o].sum = t[ls(o)].sum + t[ls(o)].sum;
}
void pushdn(int o){
    if(t[o].lz){
        t[ls(o)].lz = t[o].lz;
        t[rs(o)].lz = t[o].lz;
        t[ls(o)].sum += sz(ls(o))*t[o].lz;
        t[rs(o)].sum += sz(rs(o))*t[o].lz;
        t[o].lz = 0;
    }
}
void build(int o,int l,int r){
    if(l==r){
        t[o].l = l;t[o].r = r;t[o].sum =a[l];
        return ;
    }
    build(ls(o),l,mid);
    build(rs(o),mid+1,r);
    pushup(o);
}

int ask (int L,int R,int l,int r,int o){
    if(L<=l && r<=R){
        return t[o].sum;
        return;
    }
    int ans = 0;
    pushdn(o);
    if(L<mid) ans+= ask(L,R,l,mid,ls(o));
    if(mid<R) ans += ask(L,R,mid+1,r,rs(o));
    pushup(o);
    return ans;
}

void modify(int L,int R,int l,int r,int o,int c){
    if(L<=l && r<=R){
        t[o].lz = c;
        return;
    }
    pushdn(o);
    if(L<mid) modify(L,R,l,mid,ls(o),c);
    if(mid<R) modify(L,R,mid+1,r,rs(o),c);
    pushup(o);
}

int main(){
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);

}
signed main(){
	scanf("%lld %lld",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int opt,x,y,k;
		scanf("%lld",&opt);
		if(opt==1){
			scanf("%lld %lld %lld",&x,&y,&k);
			modify(x,y,1,n,1,k);			
		}
		else{
			scanf("%lld %lld",&x,&y);
			printf("%lld\n",ask(x,y,1,n,1));
		}
	}
	return 0;
}
