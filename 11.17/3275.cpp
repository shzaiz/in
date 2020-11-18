#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Edge {
    int v, w, next;
} e[N * 2];
int cnt, front[N], n, k;
long long ans;
int dis[N], vis[N], use[N];
queue<int> q;
void add(int u, int v, int w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = front[u];
    front[u] = cnt;
}
bool spfa()
{
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        use[u] = 0;
        for (int i = front[u]; i; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                use[i]++;
                if (use[i] > n - 1)
                    return false;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return true;
}
int main()
{
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>n>>k;
    for (int i = 1; i <= k; i++) {
        int op, u, v;
        cin>>op>>u>>v;
        if (op == 1) {
            add(u, v, 0);
            add(v, u, 0);
        }
        if (op == 2)
            add(u, v, 1);
        if (op == 3)
            add(v, u, 0);
        if (op == 4)
            add(v, u, 1);
        if (op == 5)
            add(u, v, 0);
        if (op % 2 == 0 && u == v) {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 1;
        dis[i] = 1;
        use[i] = 1;
        q.push(i);
    }
    if (!spfa()) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        ans += dis[i];
    printf("%lld\n", ans);
    return 0;
}