#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x7ffffffffffff;
const string wnm[] = {"BangZhu", "FuBangZhu", 
							"HuFa", "ZhangLao", 
                            "TangZhu", "JingYing", "BangZhong"};
const long long fuck[] = {1, 3, 5, 9, 16, 41, inf};
map<string, int> fcku;
struct Player {
    string a, b;
    long long c, d;
    int inn;
} _a[150];
int n;
bool com(Player a, Player b) {
    if (a.c == b.c) {
        return a.inn < b.inn;
    } else {
        return a.c > b.c;
    }
}
bool com2(Player a, Player b) {
    if (a.b == b.b) {
        if (a.d == b.d) {
            return a.inn < b.inn;
        } else {
            return a.d > b.d;
        }
    } else {
        return fcku[a.b] < fcku[b.b];
    }
}
int main() {
    for (int i = 0; i < 7; ++i) {
        fcku[wnm[i]] = i;
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> _a[i].a >> _a[i].b >> _a[i].c >> _a[i].d;
        if (_a[i].b == wnm[0]) {
            _a[i].c = inf;
        } else if (_a[i].b == wnm[1]) {
            _a[i].c = inf - 5;
        }
        _a[i].inn = i;
    }
    sort(_a + 1, _a + n + 1, com);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (i <= fuck[j]) {
                _a[i].b = wnm[j];
                break;
            }
        }
    }
    sort(_a + 1, _a + n + 1, com2);
    for (int i = 1; i <= n; ++i) {
        cout << _a[i].a << " " << _a[i].b << " " << _a[i].d << endl;
    }
    return 0;
}