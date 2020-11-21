#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 505 
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
 
using namespace std;

struct Edge {
    int nxt, to;
} e1[N << 1], e2[N << 1];
int head2[N], head[N], v[N], w[N], cost[N], val[N], f[N][N * 5], cnt, cntt2, scccnt, n, m, low[N], dfn[N], num, s[N], tp, vis[N], fa[N], faa[N], use[N];

void adde(int u, int v){
    e1[++cnt].nxt = head[u];
    e1[cnt].to = v;
    head[u] = cnt;
}

void adde2(int u, int v){
    e2[++cntt2].nxt = head2[u];
    e2[cntt2].to = v;
    head2[u] = cntt2;
}

void tarjan(int u){
    low[u] = dfn[u] = ++num;
    s[++tp] = u;
    vis[u] = 1;
    for (int i = head[u]; i; i = e1[i].nxt) {
        int to = e1[i].to;
        if (!dfn[to]) {
            tarjan(to), low[u] = min(low[u], low[to]);
        } else if (vis[to]) {
            low[u] = min(low[u], dfn[to]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scccnt;
        vis[u] = 0;
        while (s[tp + 1] != u) {
            fa[s[tp]] = scccnt, vis[s[tp--]] = 0;
        }
    }
    return;
}
void dp(int x){
    for (int i = cost[x]; i <= m; ++i) {
        f[x][i] = val[x];
    }
    for (int i = head2[x]; i; i = e2[i].nxt) {
        int v = e2[i].to;
        dp(v);
        for (int j = m - cost[x]; j >= 0; --j)
            for (int k = 0; k <= j; ++k) {
                f[x][j + cost[x]] = max(f[x][j + cost[x]], f[x][j + cost[x] - k] + f[v][k]);
            }
    }
    return;
}
int main(){
	
	freopen("install.in","r",stdin);
	freopen("install.out","w",stdout);

    cin>>n>>m;
    memset(f, -inf, sizeof(f));
    fo(i,n) cin>>w[i];
    fo(i,n) cin>>v[i];
    int x;
    fo(i,n){
        cin>>x;
        faa[i] = x;
        if (x != 0) adde(x, i);
    }
    fo(i,n) if (!dfn[i]) tarjan(i);
    fo(i,n) {
        val[fa[i]] += v[i];
        cost[fa[i]] += w[i];
        if (fa[i] != fa[faa[i]] && faa[i]) {
            adde2(fa[faa[i]], fa[i]);
            use[fa[i]]++;
        }
    }
    int s = scccnt + 1;
    fo(i,scccnt) if (!use[i]) adde2(s, i);
    dp(s);
    cost[s] = 0;val[s] = 0;
    cout<< f[s][m + cost[s]];
    return 0;
}
