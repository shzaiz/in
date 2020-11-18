#include <cstdio>
#include <cstring>
using namespace std;
const int N = 505;
int n, ans, t;
int matched[N];
bool G[N][N], vis[N];
bool dfs(int x)
{
    for (int i = 1; i <= n; i++)
        if (G[x][i] && !vis[i]) {
            vis[i] = true;
            if (!matched[i] || dfs(matched[i])) {
                matched[i] = x;
                return true;
            }
        }
    return false;
}
int main()
{
    scanf("%d", &t);
    while (t--) {
        memset(matched, 0, sizeof(matched));
        memset(G, false, sizeof(G));
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &G[i][j]);
        for (int i = 1; i <= n; i++) {
            memset(vis, false, sizeof(vis));
            ans += dfs(i);
        }
        if (ans == n) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}