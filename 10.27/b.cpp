#include <bits/stdc++.h>
using namespace std;
#define tm fuckccf
#define N 100010
struct Edge {
    int to, nxt, w;
} e[N];
int head[N];
int cnt = 0;
int dis[N], vis[N], tm[N];
void adde(int u, int v, int w)
{
    // printf("Added %d --[%d]--> %d\n ", u, w, v);
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    e[cnt].w = w;
    head[u] = cnt;
}
int n, m;
queue<int> Q;

bool spfa(int s)
{
    memset(dis, 1e9 + 7, sizeof dis);
    dis[s] = 0;
    vis[s] = 1;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        vis[u] = 0;
        Q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (!vis[v] && dis[u] + e[i].w < dis[v]) {
                dis[v] = dis[u] + e[i].w;
                Q.push(v);
                tm[v]++;
                vis[v] =1;
                if (tm[v] >= n)
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
#ifdef FUCKCCF
freopen("D:/Testcases/in.ac","r",stdin);
freopen("D:/Testcases/out.ac","w",stdout);
#else
freopen("farm.in","r",stdin);
freopen("farm.out","w",stdout);
#endif
    cin >> n >> m;
    int op;
    
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op == 3) {
            int a, b;
            cin >> a >> b;
            adde(a, b, 0);
            adde(b, a, 0);
        } else if (op == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            adde(a, b, -c);
        } else if (op == 2) {
            int a, b, c;
            cin >> a >> b >> c;
            adde(a, b, c);
        } else {
            printf("Your fucking idiot data must made wrong!!!");
        }
    }
    if (!spfa(1)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}