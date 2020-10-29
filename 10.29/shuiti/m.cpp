#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define inf 0x7fffffff
using namespace std;
int a[30];
int p[30] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
int main()
{
    int i, j, k, n, m, x, y;
    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        x = i;
        for (j = 0; p[j] <= x && j < 25; j++) {
            while (x % p[j] == 0) {
                a[j]++;
                x /= p[j];
            }
        }
    }
    int x3 = 0, x5 = 0, x15 = 0, x25 = 0, x75 = 0;
    for (i = 0; i < 25; i++) {
        if (a[i] >= 2) {
            x3++;
        }
        if (a[i] >= 4) {
            x5++;
        }
        if (a[i] >= 14) {
            x15++;
        }
        if (a[i] >= 24) {
            x25++;
        }
        if (a[i] >= 74) {
            x75++;
        }
    }
    printf("%d", (x3 - 2) * x5 * (x5 - 1) / 2 + (x3 - 1) * x25 + x15 * (x5 - 1) + x75);
}