#include <bits/stdc++.h>
using namespace std;
long long s[500010];
long long n, q, tmp, op, ans;
int x, y, cnt;
void init(){
    memset(s, 0, sizeof s);
}
void pushup(int root)
{
    s[root] = s[root << 1] + s[root << 1 | 1];
}
void build(int l, int r, int root)
{
    if (l == r)
        cin >> tmp, s[root] = tmp;
    else {
        int mid = l + r >> 1;
        build(l, mid, root << 1);
        build(mid + 1, r, root << 1 | 1);
        pushup(root);
    }
}
void update(int l, int r, int root)
{
    if (s[root] <= r - l + 1)
        return;
    if (l == r)
        s[root] = (long long)floor(sqrt(s[root]));
    else {
        int mid = l + r >> 1;
        if (x <= mid)
            update(l, mid, root << 1);
        if (y > mid)
            update(mid + 1, r, root << 1 | 1);
        pushup(root);
    }
}
void query(int l, int r, int root)
{
    if (l >= x && r <= y)
        ans += s[root];
    else {
        int mid = l + r >> 1;
        if (x <= mid)
            query(l, mid, root << 1);
        if (y > mid)
            query(mid + 1, r, root << 1 | 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        cout << "Case #" << ++cnt << ":" << endl;
        init();
        build(1, n, 1);
        cin >> q;
        while (q--) {
            cin >> op >> x >> y;
            if (x > y)
                swap(x, y);
            if (op) {
                ans = 0;
                query(1, n, 1);
                cout << ans << endl;
            } else {
                update(1, n, 1);
            }
        }
        cout << endl;
    }
    return 0;
}