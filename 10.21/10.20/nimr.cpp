#include <bits/stdc++.h>
using namespace std;
#define end en
const int N = 2010;
int cnt = 1, n, m, dx[4] = { 0, 0, -1, 1 }, S, T, dy[4] = { 1, -1, 0, 0 }, dis[N * N], vis[N * N], head[N * N];
struct Edge {
    int to, w, nxt;
} e[N * N << 2];
struct node {
    int x, y;
} end[N][N][4];
struct Node {
    int pos, dis;
    bool operator<(const Node a) const
    {
        return dis > a.dis;
    }
};
priority_queue<Node> heap;
char Map[N][N];
int id(int x, int y)
{
    return (x - 1) * m + y;
}
void add(int x, int y, int w)
{
    e[++cnt].to = y;
    e[cnt].nxt = head[x];
    e[cnt].w = w;
    head[x] = cnt;
}
node make(int x, int y, int k)
{
    if (end[x][y][k].x != 0 && end[x][y][k].y != 0)
        return end[x][y][k];
    int X = x + dx[k], Y = y + dy[k];
    if (X > n || Y > m || X < 1 || Y < 1 || Map[X][Y] == '#')
        end[x][y][k] = (node) { x, y };
    else
        end[x][y][k] = make(X, Y, k);
    return end[x][y][k];
}
void Dij(int s, int t)
{
    memset(dis, 0x3f, sizeof(dis));
    heap.push((Node) { s, dis[s] = 0 });
    while (heap.size()) {
        int x = heap.top().pos;
        heap.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            if (dis[y] > dis[x] + e[i].w) {
                dis[y] = dis[x] + e[i].w;
                heap.push((Node) { y, dis[y] });
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'S')
                S = id(i, j);
            if (Map[i][j] == 'C')
                T = id(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (Map[i][j] == '#')
                continue;
            for (int k = 0; k < 4; k++) {
                int x = dx[k] + i, y = dy[k] + j;
                if (x > n || y > m || x < 1 || y < 1 || Map[x][y] == '#')
                    continue;
                add(id(i, j), id(x, y), 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                end[i][j][k] = make(i, j, k);
            }
            int Min = 0x3f3f3f3f;
            for (int k = 0; k < 4; k++)
                Min = min(Min, abs(i - end[i][j][k].x) + abs(j - end[i][j][k].y) + 1);
            for (int k = 0; k < 4; k++)
                add(id(i, j), id(end[i][j][k].x, end[i][j][k].y), Min);
        }
    }
    Dij(S, T);
    cout << dis[T] << endl;
    return 0;
}