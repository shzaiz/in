// #include <bits/stdc++.h>
// using namespace std;
// #define N 100010
// vector<int > g[N];

// bool vis[N];
// int n,m;
// void adde(int x,int y){
//     g[x].push_back(y);
//     g[y].push_back(x);
// }

// void dfs(int u){
//     printf("%d ",u);
//     vis[u] = 1;
//     for(int i = 0;i<g[u].size();i++){
//         int v = g[u][i];
//         if(!vis[v]) dfs(v);
//     }
// }

// int main(){
//     #ifndef ONLINE_JUDGE
//     freopen("D:/Testcases/in.ac","r",stdin);
//     freopen("D:/Testcases/out.ac","w",stdout);
//     #else
//     freopen("travel.in","r",stdin);
//     freopen("travel.out","w",stdout);
//     #endif
//     cin>>n>>m;
//     for(int i = 1;i<=m;i++){
//         int x,y;cin>>x>>y;
//         adde(x,y);
//     }
//     for(int i = 1;i<=n;i++){
//         int l = g[i].size();
//         sort(g[i].begin(),g[i].end());
//     }
//     dfs(1);
// }

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int n, m;

vector<int> G[5050];

int ans[5050], edge[5050][2];

namespace solve1 {
int cnt = 0;

bool vis[5050];

inline void dfs(int u, int fa)
{
    ans[++cnt] = u;
    vis[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!vis[v])
            dfs(v, u);
    }
}

void main()
{
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    for (int i = 1; i <= n; i++)
        sort(G[i].begin(), G[i].end());
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
}
}

namespace solve2 {
int cnt = 0, res[5050];

bool vis[5050];

inline bool comp()
{
    for (int i = 1; i <= n; i++)
        if (ans[i] != res[i])
            return ans[i] > res[i];
    return false;
}

int del_u, del_v;

inline bool check(int u, int v)
{
    if ((u == del_u && v == del_v) || (u == del_v && v == del_u))
        return false;
    return true;
}

inline void dfs(int u, int fa)
{
    res[++cnt] = u;
    vis[u] = true;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!vis[v] && check(u, v))
            dfs(v, u);
    }
}

void main()
{
    memset(ans, 0x3f, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        sort(G[i].begin(), G[i].end());
    for (int i = 1; i <= m; i++) {
        cnt = 0;
        memset(res, 0, sizeof(res));
        memset(vis, 0, sizeof(vis));
        del_u = edge[i][0];
        del_v = edge[i][1];
        dfs(1, 0);
        /*
			for (int i=1;i<=n;i++)
				cout << res[i] << " ";
			cout << cnt << endl;
			*/
        if (comp() && cnt == n)
            memcpy(ans, res, sizeof(res));
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    #endif
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
        edge[i][0] = u;
        edge[i][1] = v;
    }
    if (m == n - 1)
        solve1::main();
    else
        solve2::main();
    return 0;
}
