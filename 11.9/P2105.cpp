#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 0
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 1000010
#define dpt ;
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
//struct Edge{
//	int to,nxt;
//}e[N];
//int n,q;
//int cnt = 0,val[N],head[N],dep[N],fa[N],sz[N],son[N],id[N],tp[N],cnt2 = 0; 
//void adde(int u,int v){
//	e[++cnt].to = v;
//	e[cnt].nxt = head[u];
//	head[u] = cnt;
//}
//void dfs1(int u,int f){
//	dpt;
//	fa[u] = f;
//	sz[u] = 1;
//	dep[u] = dep[f]+1;
//	for(int i = head[u];i;i = e[i].nxt){
//		int v = e[i].to;
//		if(v == f) continue;
//		dfs1(v,u);
//		sz[u] += sz[v];
//		if(sz[v] >= sz[son[u]]) son[u] = v;
//	}
//}
//void dfs2(int u,int tpo){
//	dpt
//	id[u] = ++cnt2;
//	val[cnt2] = u;
//	tp[u] = tpo;
//	if(!son[u]) return ;
//	dfs2(son[u],tpo);
//	for(int i = head[u];i;i = e[i].nxt){
//		int v = e[i].to;
//		if(id[v]) continue;
//		dfs2(v,v);
//	}
//}
//#define ls(o) o<<1
//#define rs(o) o<<1|1
//#define sz(o) rr-ll+1
//#define mid (ll+rr)/2
//int sum[N], a[N],maxx[N];
//void pushup(int o){
//	maxx[o] = max(sum[ls(o)],sum[rs(o)]);
//	sum[o] = sum[ls(o)] + sum[rs(o)];
//}
//void build(int o,int ll,int rr){
//	if(ll == rr) {
//		sum[o] = a[ll];
//		maxx[o] = a[ll];
//		return;
//	}
//	build(ls(o),ll,mid);
//	build(rs(o),mid+1,rr);
//	pushup(o);
//	return;
//}
//
//void update(int o,int ll,int rr,int x,int t){
//	dpt
//	if(x == ll) {
//		sum[o] = maxx[o] = t;
//		return ;
//	}
//	if(x<=mid) update(ls(o),ll,mid,x,t);
//	else update(rs(o),mid+1,rr,x,t);
//	pushup(o);
//}
//
//int querysum(int o , int L,int R,int ll,int rr){
//	deb printf("%d %d %d %d \n",ll,rr,L,R);
//	int ans = 0;
//	if(L<=ll && rr<=R) return sum[o];
//	if(L<=mid) ans+= querysum(ls(o),ll,mid,L,R);
//	if(mid<R) ans+= querysum(rs(o),mid+1,rr,L,R);
//	return ans;
//}
//
//int querymax(int o, int L,int R,int ll,int rr ){
//	dpt
//	deb printf("%d %d %d %d \n",ll,rr,L,R);
//	int ans = 0;
//	if(L<=ll &&rr<=R) return maxx[o];
//	if(L<=mid) ans=max(ans,querymax(ls(o),ll,mid,L,R));
//	if(mid<R) ans= max(querymax(rs(o),mid+1,rr,L,R),ans); 
//	pushup(o);
//	return ans;
//}
//int qsum(int u,int v){
//	dpt
//	int ans = 0;
//	while(tp[u] != tp[v]){
//		if(dep[tp[u]]<dep[tp[v]]) swap(u,v);
//		ans += querysum(1,1,n,id[tp[u]],id[v]);
//		u = fa[tp[u]];
//	}
//	if(dep[u]<dep[v]) swap(u,v);
//	ans+= querysum(1,1,n,id[u],id[v]);
//	return ans;
//}
//
//int qmax(int u,int v){
//	dpt
//	int ans = 0;
//	while(tp[u]!=tp[v]){
//		if(dep[tp[u]]<dep[tp[v]]) swap(u,v);
//		ans = max(querymax(1,1,n,id[tp[u]],id[v]),ans);
//		u = fa[tp[u]];
//	}
//	if(dep[u]<dep[v]) swap(u,v);
//	ans = max(querymax(1,1,n,id[u],id[v]),ans);
//	return ans;
//}
//
//
//int main(){
//	realfl freopen("P2023.in","r",stdin);
//	realfl freopen("2023.out","w",stdout);
//	cin>>n;
//	fo(i,n-1){
//		int u,v;cin>>u>>v;
//		adde(u,v);
//	}
//	dpt
//	fo(i,n) cin>>a[i];
//	dpt
//	dep[1] = 1;fa[1] = 0;
//	dpt
//	dfs1(1,0);
//	dpt
//	dfs2(1,1);
//	dpt
//	build(1,1,n);
//	cin>>q;
//	dpt
//	while(q--){
//		dpt
//		int x,y;
//		cin>>x>>y;
//		char s[10];
//		scanf("%s%d%d",s,&x,&y);
//		dpt
//		if(s[1] == 'H') update(1,1,n,id[x],y);
//		else if(s[1]=='M') cout<<qmax(x,y)<<endl;
//		else if(s[1]=='S') cout<<qsum(x,y)<<endl;
//		dpt
//	}
//	return  0;
//}
#define inf 1000000000
int n,q,a[4*N];
struct Edge{
    int u,v,next;
}G[N];
int tot=0,head[N];
int size[100005],wson[100005],fa[100005],d[100005],top[100005];
int tpos[100005],pre[100005],cnt=0;
inline void addedge(int u,int v){
    G[++tot].u=u;G[tot].v=v;G[tot].next=head[u];head[u]=tot;
    G[++tot].u=v;G[tot].v=u;G[tot].next=head[v];head[v]=tot;
}
void dfs1(int u,int f){
    size[u]=1;
    for (int i=head[u];i;i=G[i].next){
        int v=G[i].v;if (v==f)continue;
        d[v]=d[u]+1;fa[v]=u;
        dfs1(v,u);
        size[u]+=size[v];
        if (size[v]>size[wson[u]])wson[u]=v;
    }
}
void dfs2(int u,int TP){
    tpos[u]=++cnt;pre[cnt]=u;top[u]=TP;
    if (wson[u])dfs2(wson[u],TP);
    for (int i=head[u];i;i=G[i].next){
        int v=G[i].v;
        if (v==fa[u]||v==wson[u])continue;
        dfs2(v,v);
    }
}
int sumv[4*N],maxv[4*N];
inline void pushup(int o){
    sumv[o]=sumv[o*2]+sumv[o*2+1];
    maxv[o]=max(maxv[o*2],maxv[o*2+1]);
}
void build(int o,int l,int r){
    int mid=(l+r)/2;
    if (l==r){sumv[o]=maxv[o]=a[pre[l]];return;}
    build(o*2,l,mid);build(o*2+1,mid+1,r);
    pushup(o);
}
void update(int o,int l,int r,int q,int v){
    int mid=(l+r)/2;
    if (l==r){sumv[o]=maxv[o]=v;return;}
    if (q<=mid)update(o*2,l,mid,q,v);
    else update(o*2+1,mid+1,r,q,v);
    pushup(o);
}
int querysum(int o,int l,int r,int ql,int qr){
    int mid=(l+r)/2,ans=0;
    if (ql<=l&&r<=qr)return sumv[o];
    if (ql<=mid)ans+=querysum(o*2,l,mid,ql,qr);
    if (qr>mid)ans+=querysum(o*2+1,mid+1,r,ql,qr);
    pushup(o);
    return ans;
}
int querymax(int o,int l,int r,int ql,int qr){
    int mid=(l+r)/2,ans=-inf;
    if (ql<=l&&r<=qr)return maxv[o];
    if (ql<=mid)ans=max(ans,querymax(o*2,l,mid,ql,qr));
    if (qr>mid)ans=max(ans,querymax(o*2+1,mid+1,r,ql,qr));
    pushup(o);
    return ans;
}
int qsum(int u,int v){
    int ans=0;
    while (top[u]!=top[v]){
        if (d[top[u]]<d[top[v]])swap(u,v);
        ans+=querysum(1,1,n,tpos[top[u]],tpos[u]);
        u=fa[top[u]];
    }
    if (d[u]<d[v])swap(u,v);
    ans+=querysum(1,1,n,tpos[v],tpos[u]);
    return ans;
}
int qmax(int u,int v){
    int ans=-inf;
    while (top[u]!=top[v]){
        if (d[top[u]]<d[top[v]])swap(u,v);
        ans=max(ans,querymax(1,1,n,tpos[top[u]],tpos[u]));
        u=fa[top[u]];
    }
    if (d[u]<d[v])swap(u,v);
    ans=max(ans,querymax(1,1,n,tpos[v],tpos[u]));
    return ans;
}
int main(){
    memset(head,0,sizeof(head));
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
    }
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    d[1]=1;fa[1]=1;dfs1(1,-1);dfs2(1,1);build(1,1,n);
    scanf("%d",&q);
    while (q--){
        int x,y;
        char s[10];
        scanf("%s%d%d",s,&x,&y);
        if (s[1]=='H')update(1,1,n,tpos[x],y);
        if (s[1]=='M')printf("%d\n",qmax(x,y));
        if (s[1]=='S')printf("%d\n",qsum(x,y));
    }
    return 0;
}
