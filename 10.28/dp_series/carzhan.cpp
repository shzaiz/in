#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 1001
struct edge {
    int v, next, to;
} mem[N * N];
int n, m, size, MAX;
int a[N], head[N], in[N], q[N], ans[N];
bool map[N][N], v[N];
void add(int from, int to)
{
    size++;
    mem[size].to = to;
    mem[size].next = head[from];
    head[from] = size;
}
void topsort()
{
    int tot = 0;
    int tmp = 1;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            tot++;
            q[tot] = i;
        }
    }
    while (tot < n) {
        int kobe = 0;
        for (int i = tmp; i <= tot; i++) {
            int now = q[i];
            for (int e = head[now]; e; e = mem[e].next) {
                in[mem[e].to]--;
                if (in[mem[e].to] == 0) {
                    kobe++;
                    q[tot + kobe] = mem[e].to;
                    ans[mem[e].to] = ans[now] + 1;
                }
            }
        }
        tmp = tot + 1;
        tot = tot + kobe;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int si;
        memset(v, 0, sizeof(v));
        scanf("%d", &si);
        for (int j = 1; j <= si; j++) {
            scanf("%d", &a[j]);
            v[a[j]] = 1;
        }
        for (int j = a[1]; j <= a[si]; j++) {
            if (v[j])
                continue;
            for (int k = 1; k <= si; k++)
                if (map[a[k]][j] == 0)
                    add(a[k], j), map[a[k]][j] = 1, in[j]++;
        }
    }
    topsort();
    for (int i = 1; i <= n; i++)
        MAX = max(MAX, ans[i]);
    printf("%d", MAX + 1);
    return 0;
}