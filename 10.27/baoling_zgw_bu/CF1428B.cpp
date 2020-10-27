#define N 1000100
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
 int n, m, _, k;
char s[N];
int main() {
    for (cin >> _; _; --_) {
        cin >> n >> s + 1;
        int a = 0;
        unordered_set<int> st;
        rep (i, 1, n) {
            if (s[i] == '-') st.insert(i % n), st.insert((i + 1) % n);
            else if (s[i] == '>') {
                if (a == 0) a = 1;
                else if (a == 2) a = -1;
            } else {
                if (a == 0) a = 2;
                else if (a == 1) a = -1;
            }
        }
        if (a != -1) cout << n << '\n';
        else cout << st.size() << '\n';
    }
    return 0;
}