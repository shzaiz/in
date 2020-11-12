#include <bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int v[N];
int head[N], nxt[N * 2], to[N * 2], cnt;
int dep[N], fa[N];
int q[N], top;
void adde(int u, int vv)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = vv;
    nxt[++cnt] = head[vv];
    head[vv] = cnt;
    to[cnt] = u;
}
int n;
void dfs(int u)
{
    for (int i = head[u]; i; i = nxt[i]) {
        int vv = to[i];
        if (vv == fa[u]) {
            continue;
        }
        fa[vv] = u;
        dep[vv] = dep[u] + 1;
        dfs(vv);
    }
}
int main()
{
    freopen("sdtg.in","r",stdin);
    freopen("sdtg.out","w",stdout);
    int T;
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, vv;
        scanf("%d%d", &u, &vv);
        adde(u, vv);
    }
    dfs(1);
    for (int i = 1; i <= T; i++) {
        int k, u, vv;
        scanf("%d%d%d", &k, &u, &vv);
        if (!k) {
            top = 0;
            while (top <= 50) {
                if (dep[u] < dep[vv]) {
                    swap(u, vv);
                }
                q[++top] = v[u];
                if (u == vv) {
                    break;
                }
                u = fa[u];
            }
            if (top > 50) {
                printf("Y\n");
            } else {
                int ok = 0;
                sort(q + 1, q + top + 1);
                for (int i = 1; i <= top - 2; i++) {
                    if ((ll)q[i] + q[i + 1] > q[i + 2]) {
                        ok = 1;
                        printf("Y\n");
                        break;
                    }
                }
                if (!ok) {
                    printf("N\n");
                }
            }
        } else {
            v[u] = vv;
        }
    }
    return 0;
}