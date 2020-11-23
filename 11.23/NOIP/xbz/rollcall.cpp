#include<bits/stdc++.h>
#define fint register int
#define h 5001
#define N 500001
#define ll t[x].l
#define rr t[x].r
#define ls x<<1
#define rs x<<1|1
#define tt t[x].tot
#define int long long
using namespace std;
struct node
{
	int tot;
	int l;
	int r;
}
t[N];
int a[N],b[N];
int rt[N];
int cnt=0;
inline int read();
inline void build(int &x,int l,int r);
inline int query(int posa,int posb,int x,int l,int r);
inline void adds(int &x,int last,int l,int r,int pos);
signed main()
{
	freopen("rollcall.in","r",stdin);
	freopen("rollcall.out","w",stdout);
	int n,m;
	n=read(),m=read();
	for(fint i=1;i<=n;i++)
	a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	int len=unique(b+1,b+n+1)-b-1;
	for(fint i=1;i<=n;i++)
	a[i]=lower_bound(b+1,b+len+1,a[i])-b; 
	build(rt[0],1,len);
	for(fint i=1;i<=n;i++)
	adds(rt[i],rt[i-1],1,len,a[i]);
	int x,y,ranks=1;
	for(fint i=1;i<=m;i++)
	{
		x=1,y=read();
		cout<<query(rt[x-1],rt[y],1,len,ranks)<<endl;
		ranks++;
	}
	return 0;
}

inline void build(int &x,int l,int r)
{
	x=++cnt;
	if(l==r)
	return ; 
	int mid=(l+r)>>1;
	build(ll,l,mid);
	build(rr,mid+1,r);
	return ;
}

inline void adds(int &x,int last,int l,int r,int pos)
{
	x=++cnt;
	t[x]=t[last];
	tt++;
	if(l==r)
	return ;
	int mid=(l+r)>>1;
	if(pos<=mid)
	adds(ll,t[last].l,l,mid,pos);
	else
	adds(rr,t[last].r,mid+1,r,pos);
	return ;
}

inline int query(int lll,int rrr,int l,int r,int k)
{
    int x=t[t[rrr].l].tot-t[t[lll].l].tot;
    if(l==r) 
	return b[l];
    int mid=(l+r)>>1;
    if(x>=k) 
	return query(t[lll].l,t[rrr].l,l,mid,k);
    return query(t[lll].r,t[rrr].r,mid+1,r,k-x);
}

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
