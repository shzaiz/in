#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
struct node {
    int v, id;
    node(int a, int b)
    {
        v = a;
        id = b;
    }
    bool operator>(node b) const
    {
        return v == b.v ? id > b.id : v > b.v;
    }
};
tree<node, null_type, greater<node>, rb_tree_tag, tree_order_statistics_node_update> T, TE;
int main()
{
    int n, m, k, s = 0, q, ans = 0;
    char c[10];
    scanf("%d%d", &n, &m);
    while (n--) {
        cin >> c[0];
        scanf("%d", &k);
        if (*c == 'I') {
            k += s;
            if (k >= m)
                T.insert(node(k, n));
        } else if (*c == 'A')
            m -= k, s -= k;
        else if (*c == 'S') {
            m += k, s += k;
            T.split(node(m, -1), TE);
            ans += TE.size();
        } else if (*c == 'F')
            printf(k > T.size() ? "-1\n" : "%d\n", T.find_by_order(k - 1)->v - s);
    }
    printf("%d\n", ans);
    return 0;
}