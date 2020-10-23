#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(x) t[(x)].l
#define rs(x) t[(x)].r
#define N 100010
int cnt=0;
int root=0,m,n;
struct Seg{
    int l,r,sum,lz;
}t[N];
void pushup(int o){
    t[o].sum  = t[ls(o)].sum + t[rs(o)].sum;
}

void pushdown(int o,int ln,int rn){
    if(!ls(o)) ls(o) = ++cnt;
    if(!rs(o)) rs(o) = ++cnt;
    if(t[o].lz){
        t[ls(o)].sum += t[o].lz * ln;
        t[rs(o)].sum += t[o].lz * rn;
        t[ls(o)].lz += t[o].lz;
        t[rs(o)].lz += t[o].lz;
        t[o].lz = 0;
    }
}



void update(int L,int R,int l,int r,int &o,int c){
    if(!o) o=++cnt;
    if(L<=l && r<=R) {t[o].sum += c*(r-l+1);t[o].lz+=c;return ;}
    int mid = (l+r)/2;
    pushdown(o,mid-l+1,r-mid);
    if(L<=mid) update(L,R,l,mid,ls(o),c);
    if(mid<R) update(L,R,mid+1,r,rs(o),c);
    pushup(o);
}

int query(int L,int R,int l,int r,int &o){
    if(!o) o=++cnt;
    if(L<=l && r<=R) {return t[o].sum;}
    int ans = 0; int mid = (l+r)/2;
    pushdown(o,mid-l+1,r-mid);
    if(L<=mid) ans+= query(L,R,l,mid,ls(o));
    if(mid<R) ans+= query(L,R,mid+1,r,rs(o));
    return ans;
}

signed main(){
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
  scanf("%lld %lld",&n,&m);
  for(int i=1;i<=m;i++){
    int opt;
    scanf("%lld",&opt);
    if(opt==1){
      int l,r,k;
      scanf("%lld %lld %lld",&l,&r,&k);
      update(l,r,1,n,root,k);
//      debug(1,n,root);
    }
    else{
      int l,r;
      scanf("%lld %lld",&l,&r);
      printf("%lld\n",query(l,r,1,n,root) );
    }
  }
  return 0;
}
