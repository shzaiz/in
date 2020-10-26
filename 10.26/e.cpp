#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define rd(x) scanf("%d",&x);
typedef long long LL;
const int N=1e5+10;
int n,a[N],t[N<<2],las[N],f[N]; 
void pushup(int rt){ t[rt]=min(t[rt<<1],t[rt<<1|1]); }
int query(int rt,int l,int r,int L,int R){
	if(l>R||r<L) return 1e9;
	if(L<=l&&r<=R){
		return t[rt];
	}
	int mid=l+r>>1;
	return min(query(rt<<1,l,mid,L,R),query(rt<<1|1,mid+1,r,L,R));
}
void update(int rt,int l,int r,int x,int val){
	if(x<l||x>r) return;
	if(l==r) { t[rt]=val; return; }
	int mid=l+r>>1;
	update(rt<<1,l,mid,x,val);
	update(rt<<1|1,mid+1,r,x,val);
	pushup(rt);
	return;
}
int main(){
	rd(n);
	rep(i,1,n){
		rd(a[i]);
		int x=0; if(a[i]!=1) x=query(1,1,n,1,a[i]-1);
		if(x>las[a[i]]) f[a[i]]=1;
		update(1,1,n,a[i],i);las[a[i]]=i;
	}
	rep(i,2,n+1){
		int x=query(1,1,n,1,i-1);
		if(x>las[i]) f[i]=1;
	}
	rep(i,1,n) if(a[i]!=1) f[1]=1;
	int i=1;
	while(1){
		if(f[i]==0){
			printf("%d\n",i);
			return 0;
		}
		i++;
	}
	return 0;
}