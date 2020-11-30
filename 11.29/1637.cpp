//#include <bits/stdc++.h>
//using namespace std;
//#define using_debug_output 1
//#define using_temp_file 0
//#define this_is_a_real_file_output 1
//#define fo(i,x) for(int i = 1;i<=x;i++)
//#define fo_(i,b,x) for(int i = b;i<=x;i++)
//#define re(i,x,b) for(int i = x;i>b;i--)
//#define N 10010
//#define deb if(using_debug_output)
//#define fil if(using_temp_file)
//#define realfl if(this_is_a_real_file_output)
//#define ls(o) ls[o]
//#define rs(o) rs[o]
//#define mid (l+r)/2
//int ls[N],rs[N],val[N],cnt =0;
//int a[N],n,q,rt[N*20];
//int read(){
//	int x;cin>>x;return x;
//}
//void build(int &o,int l,int r){
//	o = ++cnt;
//	if(l== r) {
//		val[o] = a[l]; return;
//	}
//	build(ls(o),l,mid);
//	build(rs(o),mid+1,r);
//}
//void add(int &o,int pr,int l,int r,int q,int v){
//	o = ++cnt; 
//	ls[o] = ls[pr];
//	rs[o] = rs[pr];
//	val[o] = val[pr];
//	if(l==r) {
//		val[o] = v;
//		return;
//	}
//	if(q<=mid) add(ls(o),ls(pr),l,mid,q,v);
//	if(mid<v) add(rs(o),rs(pr),mid+1,r,q,v);
//}
//int query(int &o,int l,int r,int q){
//	if(l==r) return val[o];
//	if(q<=mid) return query(ls(o),l,mid,q);
//	else return query(rs(o),mid+1,r,q);
//}
//signed main(){
//	#ifndef ONLINE_JUDGE
//	freopen("1637.in","r",stdin);
//	#endif
//	int n = read(),m=read();
//	for(int i=1;i<=n;i++)cin>>a[i];
//    build(rt[0],1,n);
//    for(int i=1;i<=m;i++){
//        int pre=read(),opt=read(),x=read();
//        if(opt==1){int v=read();add(rt[i],rt[pre],1,n,x,v);}
//        if(opt==2){printf("%d\n",query(rt[pre],1,n,x));rt[i]=rt[pre];}
//    }
//	return 0;
//}
#include<bits/stdc++.h>
const int N=1000005;
using namespace std;
int a[N],n,q,rt[N*20];
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
struct Persistable_Segment_Tree{
    int lc[N*20],rc[N*20],val[N*20],cnt;
    inline void build(int &o,int l,int r){
        o=++cnt;
        if(l==r){val[o]=a[l];return;}
        int mid=(l+r)>>1;
        build(lc[o],l,mid);build(rc[o],mid+1,r);
    }
    inline void ins(int &o,int pre,int l,int r,int q,int v){
        o=++cnt;lc[o]=lc[pre];rc[o]=rc[pre];val[o]=val[pre];
        if(l==r){val[o]=v;return;}
        int mid=(l+r)>>1;
        if(q<=mid)ins(lc[o],lc[pre],l,mid,q,v);
        else ins(rc[o],rc[pre],mid+1,r,q,v);
    }
    inline int query(int o,int l,int r,int q){
        if(l==r)return val[o];
        int mid=(l+r)>>1;
        if(q<=mid)return query(lc[o],l,mid,q);
        else return query(rc[o],mid+1,r,q);
    }
}T;
int main(){
    n=read();int m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    T.build(rt[0],1,n);
    for(int i=1;i<=m;i++){
        int pre=read(),opt=read(),x=read();
        if(opt==1){int v=read();T.ins(rt[i],rt[pre],1,n,x,v);}
        if(opt==2){printf("%d\n",T.query(rt[pre],1,n,x));rt[i]=rt[pre];}
    }
}
