#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define int unsigned long long
int s[N], id[N], how[N], tp = 0, f[N], ans = 0;
char b[N];
void push(int x, char y) {
    s[++tp] = y;
    id[tp] = x;
}
void pop() { tp--; }
signed main() {
#ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int an = 0;
    for (int i = 1; i <= n; i++) {
        // printf("%d: ",i);
        if (b[i] == '(') {
            push(i, '(');
        } else if (b[i] == ')') {
            if (s[tp] == '(') {
                // printf("Plus\n");
                pop();
                how[id[tp]]++;
                f[id[tp]] += (how[id[tp]]);
                an += (how[id[tp]]);
            } else {
                // printf("Push\n");
                push(i, ')');
            }
        }

        // printf("Ans[%d] = %d\n",i,an);
        ans = ans ^ (an * i);
    }
    cout << ans;
}