#include <bits/stdc++.h>
const int maxn = 150;

template <typename T>
inline void read(T &s) {
    s = 0;
    T w = 1, ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') w = -1; ch = getchar(); }
    while (isdigit(ch))  { s = (s << 1) + (s << 3) + (ch ^ 48); ch = getchar(); }
    s *= w;
}

int n;
int m;
int s[maxn];
int v[maxn];
int w[maxn];
int f[maxn];

int main() {
    read(n), read(m);
    for (int i = 1; i <= n; ++i) {
        read(w[i]);
        read(v[i]);
        read(s[i]);
    }

    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= w[i]; --j) {
            for (int k = 1; k <= s[i] && k * w[i] <= j; ++k) {
                f[j] = std::max(f[j], f[j - k * w[i]] + k * v[i]);
                // printf()
            } 
        }
    }

    printf("%d\n", f[m]);
    return 0;
}

