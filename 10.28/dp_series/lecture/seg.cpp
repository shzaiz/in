#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define ls(x) x<<1
#define rs(x) x<<1|1
#define sz(x) r[x] - l[x]
#define mid (ll+rr)/2
int a[N];
int l[N],r[N],lz[N],sum[N];
void pushup(int o){sum[o] = sum[ls(o)]+sum[rs(o)];}
void pushdn(int o){
    if(lz[o]){
        sum[ls(o)] += lz[o]*sz(ls(o));
        sum[rs(o)] += lz[o]*sz(rs(o));
        lz[ls(o)] += lz[o];
        lz[rs(o)] += lz[o];
        lz[o] = 0;
    }
}
void build(int o,int ll,int rr){
    l[o] = ll;r[o] = rr;
    if(l == r) {sum[o] = a[ll];l[o] = ll;r[o] = rr; return;}
    build(ls(o),ll,mid);
    build(rs(o),mid+1,rr);
    pushup(o);
}
void add(int o,int ll,int rr,int L,int R,int delta){
    if(L<=ll && rr<=R) {lz[o]+=delta; return ;}
    pushdn(o);
    if(L<=mid) add(ls(o),ll,mid,L,R,delta);
    if(mid<R) add(rs(o),mid+1,rr,L,R,delta);
    pushup(o);
}
int query(int o,int ll,int rr,int L,int R){
    int ans = 0;
    if(L<=ll && rr<=R) {return sum[o];}
    pushdn(o);
    if(L<=mid) ans+=query(ls(o),ll,mid,L,R);
    if(mid<R) ans+=query(rs(o),mid+1,rr,L,R);
    pushup(o);
}
int main(){

}