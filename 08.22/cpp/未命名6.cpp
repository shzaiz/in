#include <cstdio>
#define lowbit(x) ((x)&(-x))
int tree[500010],a[500010],n,m,mode,left,right;
void update(int x,int k) {
	for(;x<=n;x+=lowbit(x))tree[x]+=k;
}
void build() {
	for(int i=1; i<=n; i++) update(i,a[i]);
}
int query(int x) {
	int sum=0;
	while(x) {
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	build();
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&mode,&left,&right);
        if(mode==1) update(left,right);
        else printf("%d\n",query(right)-query(left-1));
	}
	return 0;
}
