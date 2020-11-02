#include <iostream>
using namespace std;
int n, m, r, ans, dx[2] = { 0, 1 }, dy[2] = { 1, 0 };
char map[105][105];
void skim(int x, int y, int i, int j)
{
    if (j > r) {
        ++ans;
        return;
    }
    if (map[x][y] != '.' || x < 0 || y < 0 || x >= n || y >= m)
        return;
    skim(x + dx[i], y + dy[i], i, j + 1);
    return;
}
int main()
{
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
        cin >> map[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == '.')
                for (int k = 0; k < 2; k++)
                    skim(i, j, k, 1);
    if (r == 1)
        ans /= 2;
    cout << ans << endl;
    return 0;
}