#include <algorithm>
#include <cstdio>
using namespace std;
bool pm(int x);
void pot(int a)
{
    if (a == 4) {
        printf("4=2+2\n");
        return;
    }
    for (int i = 3; i + 2 <= a; i += 2) {
        if (pm(i) && 2 + i == a) {
            printf("%d=2+%d\n", a, i);
            return;
        }
    }
    for (int i = 3; i + 3 <= a; i += 2) {
        if (pm(i) && pm(a - i)) {
            printf("%d=%d+%d\n", a, min(i, a - i), max(i, a - i));
            return;
        }
    }
}
bool pm(int x)
{
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 4; i <= n; i += 2)
        pot(i);
    return 0;
}