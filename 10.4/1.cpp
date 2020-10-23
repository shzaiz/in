#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e2+50;
const int maxm=1e4+50;
const int inf=100000009;

int n,m,r;
ll ans;
int cnt = 0;
inline ll read(){
	ll x;
    x=0;char ch=0;bool sign=false;
    while(ch < '0' || ch > '9'){
        sign|=(ch == '-');
        ch=getchar();
    }
    while(!(ch < '0' || ch > '9')){
        x=x*10+(ch^48);
        ch=getchar();
    }
    x=sign ? -x : x;
    return x;
}

inline void print(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
struct edge {int u,v;ll w;}e[maxm];
int cnt2=0,fa[maxn],id[maxn],top[maxn],mi[maxn];
ll anss = -1;
inline int getans() {
    while(1) {
        for(register int i=1;i<=n;++i) id[i]=top[i]=0,mi[i]=inf;
        for(register int i=1;i<=m;++i)
            if(e[i].u!=e[i].v&&e[i].w<mi[e[i].v])
                fa[e[i].v]=e[i].u,mi[e[i].v]=e[i].w;
        int u=mi[r]=0;
        for(register int i=1;i<=n;++i) {
            if(mi[i]==inf) return 0;
            ans+=mi[i];
            // printf("%d ",mi[i]);
            anss = max((ll)mi[i],anss);
            for(u=i;u!=r&&top[u]!=i&&!id[u];u=fa[u]) top[u]=i;
            if(u!=r&&!id[u]) {
                id[u]=++cnt;
                for(int v=fa[u];v!=u;v=fa[v]) id[v]=cnt;
            }
        }if(!cnt) return 1;
        for(register int i=1;i<=n;++i) if(!id[i]) id[i]=++cnt;
        for(register int i=1;i<=m;++i) {
            int last=mi[e[i].v];
            if((e[i].u=id[e[i].u])!=(e[i].v=id[e[i].v])) e[i].w-=last;
        }n=cnt;r=id[r];cnt=0;
    }
}
void adde(int u,int v,ll w){
	e[++cnt2]=(edge){(int)u,(int)v,w};
}
int main() {
    n=read();m=read();r=0;
    for(register int i=0;i<m;i++,adde((int)read(),(int)read(),read()));
    for(int i = 1;i<=n;i++){
    	adde(0,i,100000007);
    }
    if(getans()) printf("%lld",man);
    else printf("-1");
    return 0;
}