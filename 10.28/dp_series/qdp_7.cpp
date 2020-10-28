#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int t, n, f[1000007], book[1000007 * 3];
struct node {
    int x, y, e;
} a[1000001];
bool cmp(node a, node b)
{
    return a.e > b.e;
}
inline void first(int kkk)
{
    for (int i = 1; i <= kkk; i++)
        f[i] = i;
}
int get(int x)
{
    if (x == f[x])
        return x;
    return f[x] = get(f[x]);
}
int main()
{
    scanf("%d", &t);
    while (t--) {
        int tot = -1;
        memset(book, 0, sizeof(book));
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        int flag = 1;
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].e);
            book[++tot] = a[i].x;
            book[++tot] = a[i].y;
        }
        sort(book, book + tot);
        int reu = unique(book, book + tot) - book;
        for (int i = 1; i <= n; ++i) {
            a[i].x = lower_bound(book, book + reu, a[i].x) - book;
            a[i].y = lower_bound(book, book + reu, a[i].y) - book;
        }
        first(reu);
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            int r1 = get(a[i].x);
            int r2 = get(a[i].y);
            if (a[i].e) {
                f[r1] = r2;
            } else if (r1 == r2) {
                printf("NO\n");
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("YES\n");
    }
    return 0;
}