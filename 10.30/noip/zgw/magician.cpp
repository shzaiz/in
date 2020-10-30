#include <bits/stdc++.h>
using namespace std;
#define N 500010
const int mod = 1e9+9;
int fa[N];
void init(int n){
    for(int i = 1;i<=n;i++){
        fa[i] = i;
    }
}
int find(int x){
    return (x==fa[x]) ? x: (fa[x] = find(fa[x]));
}
int merge(int x,int y){
    int xx = find(x);
    int yy = find(y);
    if(xx == yy) return 0;
    fa[xx] = yy;
    return 1;
}
bool same(int x,int y){
    return find(x) == find(y);
}
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("magician.in","r",stdin);
    freopen("magician.out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    init(n);
    int ans = 0;
    for(int i =1;i<=m;i++){
        int x,y;cin>>x>>y;
        if(same(x,y)){
            ans = (((ans%mod)*2)%mod+1)%mod;
        }else{
            merge(x,y);
        }
        printf("%d\n",ans);
    }
    return 0;
}