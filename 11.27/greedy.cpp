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
const int maxn=100005;
int sum_r[maxn<<2],sum_l[maxn<<2],add[maxn<<2];
int n,m;
int L,R;
void update_l(int now,int l,int r,int t){
	if(l==r){
		sum_l[now]++;
		return ;
	}
	int mid=(l+r)>>1;
	if(t<=mid)update_l(now<<1,l,mid,t);
	else update_l(now<<1|1,mid+1,r,t);
	sum_l[now]=sum_l[now<<1]+sum_l[now<<1|1];
	return ;
}
void update_r(int now,int l,int r,int t){
	if(l==r){
		sum_r[now]++;
		return ;
	}
	int mid=(l+r)>>1;
	if(t<=mid)update_r(now<<1,l,mid,t);
	else update_r(now<<1|1,mid+1,r,t);
	sum_r[now]=sum_r[now<<1]+sum_r[now<<1|1];
	return ;
}
int query_l(int now,int l,int r){
	if(L<=l&&r<=R){
		return sum_l[now];
	}
	int mid=(l+r)>>1;
	int ans=0; 
	if(L<=mid)ans+=query_l(now<<1,l,mid);
	if(mid<R)ans+=query_l(now<<1|1,mid+1,r);
	return ans;
}
int query_r(int now,int l,int r){
	if(L<=l&&r<=R){
		return sum_r[now];
	}
	int mid=(l+r)>>1;
	int ans=0; 
	if(L<=mid)ans+=query_r(now<<1,l,mid);
	if(mid<R)ans+=query_r(now<<1|1,mid+1,r);
	return ans;
}
int main()
{
	int op,l,r;
	int cnt=0,tmp=0;
	scanf("%d %d",&n,&m);
	for(register int i=1;i<=m;i++){
		scanf("%d %d %d",&op,&l,&r);
		if(op==1){
			update_l(1,1,n,l);
			update_r(1,1,n,r);
			cnt++;
		}
		else {
			L=r+1,R=n;
			if(L<=R)tmp+=query_l(1,1,n);		
			L=1,R=l-1;
			if(L<=R)tmp+=query_r(1,1,n);
		    cout<<cnt-tmp<<endl;
		    tmp=0;
		}
	}
	return 0;
} 
