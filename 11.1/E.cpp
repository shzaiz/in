#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, a[20001];
struct each {
    int x, y, cost;
} b[20001];
bool com(each x, each y)
{
    return x.cost < y.cost;
}
int read()
{
    int x;
    cin >> x;
    return x;
}
int find(int x)
{
    if (a[x] == 0)
        return x;
    a[x] = find(a[x]);
    return a[x];
}
int main()
{
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    n = read();
    m = read();
    s = read();
    t = read();
    for (int i = 1; i <= m; i++) {
        b[i].x = read();
        b[i].y = read();
        b[i].cost = read();
    }
    sort(b + 1, b + m + 1, com);
    for (int i = 1; i <= m; i++) {
        int X = find(b[i].x), Y = find(b[i].y);
        if (X != Y)
            a[X] = Y;
        if (find(s) == find(t)) {
            cout << b[i].cost << endl;
            return 0;
        }
    }
    return 0;
}