#include <bits/stdc++.h>
using namespace std;
int dabiao[1000] = { 4, 7, 44, 77, 47, 74, 444, 777, 477, 747, 774, 744, 474,
    447 };
int x[1002];
int main()
{
    int j = 14;
    for (int n = 1; n <= 1000; n++) {
        for (int i = 0; i < j; i++) {
            if (n == dabiao[i] || n % dabiao[i] == 0) {
                dabiao[j++] = n;
                x[n] = 1;
                break;
            }
        }
    }
    int m;
    cin >> m;
    if (x[m] == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}