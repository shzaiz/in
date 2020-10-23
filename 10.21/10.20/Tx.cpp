#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int h, w, d, r, st[N][N][2];
char s[N][N];
struct Point {
    int x, y, u;
};
queue<Point> Q;
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
bool check(int x, int y)
{
    return x >= 1 && y >= 1 && x <= h && y <= w && s[x][y] == '.';
}
int main()
{
    scanf("%d%d%d%d", &h, &w, &d, &r);
    for (int i = 1; i <= h; i++)
        scanf("%s", s[i] + 1);
    memset(st, -1, sizeof(st));
    st[1][1][0] = 0;
    Q.push((Point) { 1, 1, 0 });
    while (!Q.empty() && st[h][w][0] == -1 && st[h][w][1] == -1) {
        Point f = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + f.x, y = dy[i] + f.y;
            if (check(x, y) && st[x][y][f.u] == -1) {
                Q.push((Point) { x, y, f.u });
                st[x][y][f.u] = st[f.x][f.y][f.u] + 1;
                if (f.u == 0 && check(x + d, y + r) && st[x + d][y + r][1] == -1) {
                    Q.push((Point) { x + d, y + r, 1 });
                    st[x + d][y + r][1] = st[x][y][0] + 1;
                }
            }
        }
    }
    if (st[h][w][0] == -1 && st[h][w][1] == -1)
        puts("-1");
    else
        printf("%d", min(st[h][w][0] == -1 ? 1 << 30 : st[h][w][0],
                         st[h][w][1] == -1 ? 1 << 30 : st[h][w][1])); //奇葩的写法，不建议效仿QWQ
}