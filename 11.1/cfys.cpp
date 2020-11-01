#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int n, m, u, v, w, tot;
int dis[200010], vis[200010], cnt[200010], head[200010];

struct node {
    int to, net, val;
} e[200010];

inline void add(int u, int v, int w)
{
    e[++tot].to = v;
    e[tot].val = w;
    e[tot].net = head[u];
    head[u] = tot;
}

inline bool spfa()
{
    for (register int i = 0; i <= n; i++) {
        vis[i] = 0;
        dis[i] = 20050206;
    }
    dis[0] = 0;
    vis[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (register int i = head[x]; i; i = e[i].net) {
            int v = e[i].to;
            if (dis[v] > dis[x] + e[i].val) {
                dis[v] = dis[x] + e[i].val;
                if (cnt[v] >= n)
                    return false;
                if (!vis[v]) {
                    vis[v] = 1;
                    cnt[v]++;
                    q.push(v);
                }
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(v, u, w);
    }
    for (register int i = 1; i <= n; i++)
        add(0, i, 0);
    if (spfa() == false)
        puts("NO");
    else {
        for (register int i = 1; i <= n; i++)
            printf("%d ", dis[i]);
    }
    return 0;
}