#include <bits/stdc++.h>
using namespace std;
#define Maxn 500010
#define LL long long
// int head[N],cnt =0;
// int le[N],f[N];
// struct Edge{
//     int to,nxt;
// }e[N];
// void adde(int u,int v){
//     e[++cnt].to = v;
//     e[cnt].nxt = head[u];
//     head[u] = ++cnt;
// }
// int v[N],sum[N];
// void dfs(int u){
//     bool fl = 1;
//     for(int i = head[u];i;i = e[i].nxt){
//         dfs(e[i].to);fl = 0;

//     }
//     if(!fl){
//         sum[u] = v[u];
//         le[u] = 1;
//     }
//     for(int i = head[u];i;i = e[i].nxt){
//         int v =e[i].to;
//         f[u] = max(f[u],f[v]);sum[u] += sum[v];
//         le[u]+=le[v];
//     }
//     f[u] = max(f[u],(sum[u]+le[u]-1)/le[u]);
// }
// int main(){
//     #ifndef ONLINE_JUDGE
//     freopen("D:/Testcases/in.ac","r",stdin);
//     freopen("D:/Testcases/out.ac","w",stdout);
//     #endif
//     int n;cin>>n;
//     for(int i =1;i<n;i++){
//         int x;cin>>x;
//         adde(i,x);
//     }
//     for(int i = 1;i<=n;i++){
//         cin>>v[i];
//     }
//     dfs(1);
//     printf("%d\n",f[1]);
//     return 0;
// }
int n;
LL val[Maxn], siz[Maxn], f[Maxn], leaf[Maxn];

struct Edge {
    int next, to;
}
edge[Maxn];
int head[Maxn], edge_num;

void add_edge(int from, int to) {
    edge[++edge_num].next = head[from];
    edge[edge_num].to = to;
    head[from] = edge_num;
}

void dfs(int u) {
    bool flag = 1;
    for(int i = head[u]; i; i = edge[i].next) dfs(edge[i].to), flag = 0;
    if(flag) leaf[u] = 1; siz[u] = val[u];
    for(int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        f[u] = max(f[v], f[u]);
        siz[u] += siz[v]; leaf[u] += leaf[v];
    }
    f[u] = max(f[u], (siz[u] + leaf[u] - 1) / leaf[u]);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>n;
    for(int i = 2; i <= n; ++i) {
        int fa ;cin>>fa;
        add_edge(fa, i);
    }
    for(int i = 1; i <= n; ++i) cin>>val[i];
    dfs(1);
    cout << f[1] << endl;
    return 0;
}