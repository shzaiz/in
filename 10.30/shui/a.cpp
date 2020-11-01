#include <cstring>
#include <iostream>
using namespace std;
int a[505][505], b[505][505];

void spin(int x, int y, int r)
{
    for (int i = x - r; i <= x + r; i++) {
        for (int k = y - r; k <= y + r; k++)
            b[i][k] = a[i][k];
    }
    int x1 = x + r, y1 = y - r;
    for (int i = x - r; i <= x + r; i++) {
        for (int k = y - r; k <= y + r; k++) {
            a[i][k] = b[x1][y1];
            x1--;
        }
        x1 = x + r, y1++;
    }
}

void work(int x, int y, int r)
{
    for (int i = x - r; i <= x + r; i++) {
        for (int k = y - r; k <= y + r; k++)
            b[i][k] = a[i][k];
    }
    int x1 = x - r, y1 = y + r;
    for (int i = x - r; i <= x + r; i++) {
        for (int k = y - r; k <= y + r; k++) {
            a[i][k] = b[x1][y1];
            x1++;
        }
        y1--, x1 = x - r;
    }
}

int main()
{
    int n, m, t = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++)
            a[i][k] = ++t;
    }
    int x, y, r, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> r >> z;
        if (z == 0)
            spin(x, y, r);
        else if (z == 1)
            work(x, y, r);
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++)
            cout << a[i][k] << " ";
        cout << endl;
    }
}