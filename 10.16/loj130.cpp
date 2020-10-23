#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define ls(o) o<<1
#define rs(o) o<<1|1
#define sz(o) t[(o)].r - t[(o)].l
#define mid (l+r)/2
struct Seg{
    int l,r,lz,sum;
}t[N];
int a[N];
void pushup(int o){
    t[o].sum = t[ls(o)].sum + t[rs(o)].sum; 
}
void pushdn(int o,int ln,int rn){
    if(t[o].lz){
        t[ls(o)].lz +=t[o].lz;
        t[rs(o)].lz +=t[o].lz;
        t[ls(o)].sum += ln* t[o].lz;
        t[rs(o)].sum += rn* t[o].lz;
        t[o].lz = 0;
    }
}
void build(int o,int l,int r){
    
    if(l==r){
        t[o].l = t[o].r = l;
        t[o].sum = a[l];
        t[o].lz = 0;
        return;
    }
    t[o].l = l;t[o].r = r;
    build(ls(o),l,mid);
    build(rs(o),mid+1,r);
    pushup(o);
}

void modify(int o,int L,int R,int l,int r ,int c){
    if(L<=l && r<=R) {
        t[o].lz+=c;
        return;
    }
    // pushdn(o,)
    if(L<=mid) modify(ls(o),L,R,l,mid,c);
    if(mid<R) modify(rs(o),L,R,mid+1,r,o);
    pushup(o);
}

int main(){

}