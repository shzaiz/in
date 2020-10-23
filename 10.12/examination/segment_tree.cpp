#include <bits/stdc++.h>
using namespace std;
#define ls(x) t[x].l
#define rs(x) t[x].r
#define N 10010
#define int long long
int n,m;
struct Seg{
    int l,r,sum,lz;
}t[N];
int root = 0,cnt = 0; 
void pushdn(int o,int ln,int rn){
    if(!ls(o)) ls(o) = ++cnt;
    if(!rs(o)) rs(o) = ++cnt;
    if(t[o].lz){
        t[rs(o)].lz+=t[o].lz;
        t[ls(o)].lz+=t[o].lz;
        t[ls(o)].sum+=t[o].lz*ln;
        t[rs(o)].sum+=t[o].lz*rn;
        t[o].lz = 0;
    }
}

void pushup(int o){
    t[o].sum+= t[ls(o)].sum+t[rs(o)].sum;
}

void modify(int L,int R,int l,int r,int &o,int c){
    if(!o) o = ++cnt;
    if(L<=l && r<=R) {
        t[o].sum += (r-l+1)*c;
        t[o].lz +=c;
        return;
    }
    int mid = (l+r)/2;
    pushdn(o,mid-l+1,r-mid);
    if(L<=mid) modify(L,R,l,mid,ls(o),c);
    if(mid<R) modify(L,R,mid+1,r,rs(o),c);
    pushup(o);
}

int ask(int L,int R,int l,int r,int &o){
    if(!o) o = ++cnt;
    if(L<=l && r<=R) {
        return t[o].sum;
    }
    int mid = (l+r)/2,ans = 0;
    pushdn(o,mid-l+1,r-mid);
    if(L<=mid) ans+=ask(L,R,l,mid,ls(o));
    if(mid<R) ans+=ask(L,R,mid+1,r,rs(o));
    pushup(o);
    return ans;
}
signed main(){
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
    int a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
  scanf("%lld %lld",&n,&m);
  for(int i=1;i<=m;i++){
    int opt;
    scanf("%lld",&opt);
    if(opt==1){
      int l,r,k;
      scanf("%lld %lld %lld",&l,&r,&k);
      modify(l,r,1,n,root,k);
    }
    else{
      int l,r;
      scanf("%lld %lld",&l,&r);
      printf("%lld\n",ask(l,r,1,n,root) );
    }
  }
  return 0;
}
