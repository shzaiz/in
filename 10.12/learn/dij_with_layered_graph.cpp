#include <bits/stdc++.h>
#define next nxt
using namespace std;


const int N = 2e2 + 10, M = 3e3 + 10, inf = 1e9;
int n, m, k, p, tot, a[N], d[N][N * 50], vis[N][N * 50];
int head[N], next[M * 2], ver[M * 2], edge[M * 2], cost[M * 2];
priority_queue<pair<pair<int, int>, int  > >q;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void add(int x, int y, int z, int c)
{
    ver[++tot] = y;
    edge[tot] = z;
    cost[tot] = c;
    next[tot] = head[x];
    head[x] = tot;
}
inline int dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (1 << p); j++)
            d[i][j] = inf;
    }
    d[1][0] = 0;
    q.push(make_pair(make_pair(0, 1), 0));
    while (q.size())
    {
        int t = -q.top().first.first, x = q.top().first.second, s = q.top().second;
        q.pop();
        if (x == n)
            return t;
        if (vis[x][s])
            continue;
        vis[x][s] = 1;
        s |= a[x];
        for (int i = head[x]; i; i = next[i])
        {
            int y = ver[i], z = edge[i], c = cost[i];
            if ((s | c) != s)
                continue;
            if (d[y][s] > t + edge[i])
            {
                d[y][s] = t + edge[i];
                q.push(make_pair(make_pair(-d[y][s], y), s));
            }
        }
    }
    return -1;
}
int main()
{
    n = read();
    m = read();
    p = read();
    k = read();
    for (int i = 1; i <= k; i++)
    {
        int w = read(), q = read();
        for (int j = 1; j <= q; j++)
        {
            int x = read();
            a[w] |= 1 << (x - 1);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read(), z = read(), s = read(), c = 0;
        for (int j = 1; j <= s; j++)
        {
            int v = read();
            c |= 1 << (v - 1);
        }
        add(x, y, z, c);
        add(y, x, z, c);
    }
    printf("%d\n", dijkstra());
    return 0;
}