#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 * 6 + 100;
int dp[N][N];
int c[N], a[N], b[N];
int n, k, m;
int maxx[N];
struct Edge {
    int nxt, to;
} s[N * 2];
int head[N], cnt = 0;
inline void add(int aa, int bb)
{
    cnt++;
    s[cnt].nxt = head[aa];
    s[cnt].to = bb;
    head[aa] = cnt;
}
priority_queue<int> q;
int sum[N];
int main()
{
    cin >> n >> m >> k;
    memset(dp, -0x3f, sizeof(dp));
    dp[0][k] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        sum[i] = sum[i - 1] + b[i];
        maxx[i] = i;
        if (sum[i - 1] + k < a[i]) {
            cout << -1;
            return 0;
        }
    }
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        maxx[v] = max(maxx[v], u);
    }
    for (int i = 1; i <= n; i++) {
        add(maxx[i], i);
    }
    int num;
    int su[N];
    memset(su, 0, sizeof(su));
    for (int i = 1; i <= n; i++) {
        while (!q.empty())
            q.pop();
        num = 0;
        for (int l = head[i]; l; l = s[l].nxt) {
            q.push(c[s[l].to]);
        }
        su[0] = 0;
        while (!q.empty()) {
            num++;
            if (num != 0)
                su[num] = su[num - 1] + q.top();
            else
                su[num] = q.top();
            q.pop();
        }
        for (int j = a[i]; j + b[i] <= k + sum[i]; j++) {
            if (dp[i - 1][j] < 0)
                continue;
            dp[i][j + b[i]] = max(dp[i][j + b[i]], dp[i - 1][j]);
            for (int bj = 1; bj <= num; bj++) {
                dp[i][j + b[i] - bj] = max(dp[i][j + b[i] - bj], dp[i - 1][j] + su[bj]);
            }
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 0; i <= k + sum[n]; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
    return 0;
}