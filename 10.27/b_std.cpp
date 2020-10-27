#include <bits/stdc++.h>
#define inf 0x7fffffff
#define ll long long
using namespace std;
int n, p1, p2, cnt, top, tot;
int head[100005], r[100005], q[100005], s[100005], h[100005];
struct Edge {
    int to, nxt;
} e[100005];
void adde(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
void topo()
{
    for (int i = 1; i <= n; i++)
        if (!r[i]) {
            s[++top] = i;
            q[++tot] = i;
        }
    while (top) {
        int x = s[top--];
        for (int i = head[x]; i; i = e[i].nxt) {
            r[e[i].to]--;
            if (!r[e[i].to]) {
                s[++top] = e[i].to;
                q[++tot] = e[i].to;
            }
        }
    }
}
int main()
{
#ifdef FUCKCCF
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
    freopen("dizzy.in", "r", stdin);
    freopen("dizzy.out", "w", stdout);
#endif
    cin >> n >> p1 >> p2;
    for (int i = 1; i <= p1; i++) {
        int u, v;
        cin >> u >> v;
        adde(u, v);
        r[v]++;
    }
    topo();
    for (int i = 1; i <= n; i++)
        h[q[i]] = i;
    for (int i = 1; i <= p2; i++) {
        int u, v;
        cin >> u >> v;
        if (h[u] >= h[v])
            printf("%d %d\n", v, u);
        else
            printf("%d %d\n", u, v);
    }
    return 0;
}