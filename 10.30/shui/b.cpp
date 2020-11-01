#include <algorithm>
#include <cstdio>
using namespace std;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
struct Maker {
    int x, y, face;
};
char map[12][12];
int vis[11][11][11][11];
void operator++(Maker& a)
{
    int nx = a.x + dx[a.face];
    int ny = a.y + dy[a.face];
    if (map[nx][ny] != '\*')
        a.x = nx, a.y = ny;
    else
        a.face++, a.face %= 4;
}
bool operator!=(const Maker& a, const Maker& b)
{
    return a.x != b.x || a.y != b.y;
}
int main()
{
    Maker jhon, cow;
    fill(map[0], map[0] + 12, '\*');
    fill(map[11], map[11] + 12, '\*');
    for (int i = 1; i <= 10; i++) {
        scanf("%s\n", &map[i][1]);
        map[i][0] = map[i][11] = '\*';
        for (int j = 1; j <= 10; j++) {
            if (map[i][j] == 'C')
                cow = (Maker) { i, j, 0 };
            if (map[i][j] == 'F')
                jhon = (Maker) { i, j, 0 };
        }
    }
    int ans = 0;
    while (jhon != cow) {
        if (vis[jhon.x][jhon.y][cow.x][cow.y]++ == 4) {
            printf("0");
            return 0;
        }
        ans++, ++jhon, ++cow;
    }
    printf("%d\n", ans);
    return 0;
}