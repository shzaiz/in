#include <bits/stdc++.h>
using namespace std;
int n, m, a1, b1, c1, cnt, to[2000010], val[2000010], nxt[2000010], first[1010], d[1010], f[1010], v[1010];
priority_queue<pair<int, int>> q;
void addedge(int x, int y, int z)
{
    cnt++;
    to[cnt] = y;
    val[cnt] = z;
    nxt[cnt] = first[x];
    first[x] = cnt;
}
void dij1()
{
    memset(d, 0x7f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[2] = 0;
    while (q.size())
        q.pop();
    q.push(make_pair(0, 2));
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        v[x] = 1;
        for (int i = first[x]; i; i = nxt[i]) {
            int y = to[i], z = val[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                q.push(make_pair(-d[y], y));
            }
        }
    }
}
void dij2()
{
    memset(v, 0, sizeof(v));
    memset(f, 0, sizeof(f));
    f[1] = 1;
    while (q.size())
        q.pop();
    q.push(make_pair(d[1], 1));
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        v[x] = 1;
        for (int i = first[x]; i; i = nxt[i]) {
            int y = to[i];
            if (d[y] < d[x]) {
                f[y] += f[x];
                q.push(make_pair(d[y], y));
            }
        }
    }
}
int main()
{
    while (scanf("%d", &n), n) {
        cnt = 0;
        memset(nxt, 0, sizeof(nxt));
        memset(val, 0, sizeof(val));
        memset(to, 0, sizeof(to));
        memset(first, 0, sizeof(first));
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &a1, &b1, &c1);
            addedge(a1, b1, c1);
            addedge(b1, a1, c1);
        }
        dij1();
        dij2();
        printf("%d\n", f[2]);
    }
}