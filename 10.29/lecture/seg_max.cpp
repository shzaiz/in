#include <bits/stdc++.h>
#define MAX 200000
using namespace std;
int a, b, ans, n, m, x, val, maxx;
char op;
struct node {
    int l, r, w, f;
} t[4 * MAX + 5];
void build(int l, int r, int k)
{
    t[k].l = l;
    t[k].r = r;
    if (t[k].l == t[k].r) {
        scanf("%d", &t[k].w);
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2 + 1);
    t[k].w = max(t[k * 2].w, t[k * 2 + 1].w);
}
void modify(int k)
{
    if (t[k].l == t[k].r) {
        t[k].w = val;
        return;
    }
    int mid = (t[k].l + t[k].r) / 2;
    if (x <= mid)
        modify(k * 2);
    else
        modify(k * 2 + 1);

    t[k].w = max(t[k * 2].w, t[k * 2 + 1].w);
}
void query(int k)
{
    if (a <= t[k].l && t[k].r <= b) {
        maxx = max(maxx, t[k].w);
        return;
    }

    int mid = (t[k].l + t[k].r) / 2;
    if (a <= mid)
        query(k * 2);
    if (b > mid)
        query(k * 2 + 1);
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF) {
        build(1, n, 1);
        for (int i = 1; i <= m; i++) {
            getchar();
            op = getchar();
            if (op == 'Q') {
                scanf("%d%d", &a, &b);
                maxx = -1;
                query(1);
                printf("%d\n", maxx);
            } else if (op == 'U') {
                scanf("%d%d", &x, &val);
                modify(1);
            }
        }
    }
    return 0;
}