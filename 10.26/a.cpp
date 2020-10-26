#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace baoli {

int mian(int n)
{
    
    int a[16];
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < (1 << n); i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {

            if ((i >> j) & 1) {

                v.push_back(a[j]);
            }
        }
        int sz = v.size();
        for (int i = 0; i < sz; i++) {
            // printf("%d ",v[i]);
        }
        int fl = 1;
        for (int aa = 0; aa < sz - 1; aa++) {
            for (int b = aa + 1; b < sz; b++) {
                if (v[aa] ^ v[b] >= min(v[aa], v[b]))
                    fl = 0;
            }
        }
        if (fl) {
            ans = max(ans, sz);
            for (int i = 0; i < sz; i++) {
                // printf("%d ", v[i]);
            }
            // printf("\n");
        }
        v.clear();
    }
    printf("%d\n", ans);
}

}
namespace zhengjie {
int mian(int n)
{
    int a[1005], b[1005];
    int ans = 0;
    int pos[64];
    for (int i = 0; i <= 63; i++)
        pos[i] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 60; j >= 0; j--) {
        for (int i = 1; i <= n; i++) {
            // printf("%d << j = \n",a[i]);
            int tmp = (a[i] << j) & 1;
            if (tmp)
                pos[j]++;
        }
    }
    for (int i = 0; i < 60; i++) {
        ans = max(ans, pos[i]);
    }
    printf("%lld\n", ans);
}
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
#endif
    //  baoli::mian();
    int n;
    while(scanf("%lld",&n)==1) if(n<10) baoli::mian(n); else zhengjie::mian(n);
}