#include <bits/stdc++.h>
using namespace std;
struct S {
    int a, b, c;
    string e;
} Sboww[1000];
int n;
bool cmp(S ac, S wa)
{
    return ac.a + ac.b + ac.c > wa.a + wa.b + wa.c;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Sboww[i].e >> Sboww[i].a >> Sboww[i].b >> Sboww[i].c;
    sort(Sboww, Sboww + n, cmp);
    cout << Sboww[0].e << " " << Sboww[0].a << " " << Sboww[0].b << " " << Sboww[0].c << endl;
    return 0;
}
