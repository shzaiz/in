#include <bits/stdc++.h>
using namespace std;
#define fo(i, x) for (int i = 1; i <= x; i++)
#define fo_(i, b, x) for (int i = b; i <= x; i++)
#define re(i, x, b) for (int i = x; i > b; i--)
#define N 10010
map<string, int> mp;
string ch[40000];
string c;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("answer.in","r",stdin);
    freopen("answer.out","w",stdout);
    #endif
    int n, m, p, q;
    cin>>n>>m>>p>>q;
    fo(i,n)cin >> ch[i];
    sort(ch + 1, ch + n + 1);
    if (p == 0 && q != 0) {
        swap(p, q);
        fo(i,n)fo_(j,0,m-1)if (ch[i][j] == 'Y')ch[i][j] = 'N';else ch[i][j] = 'Y';
    }
    fo(i,n)mp[ch[i]]++;
    fo(i,n) if (mp[ch[i]] == p) {
        c = "";
        for (int j = 0; j < m; ++j)
            if (ch[i][j] == 'Y') c += 'N';
            else c += 'Y';
            if (mp[c] == q) {
                cout << ch[i] << endl;
                return 0;
            }
        }
    if (p == 0 && q == 0) {
        c = "";
        fo_(i,0,m-1) c += 'N';
        string c1 = "";
        fo_(i,0,m-1) c1 += 'Y';
        for(;;){
            if (mp[c] == 0 && mp[c1] == 0) {cout << c << endl;return 0;}
            int tp = m - 1;
            while (tp > 0 && c[tp] == 'Y') --tp;
            c[tp] = 'Y';
            for (int i = tp + 1; i < m; ++i) c[i] = 'N';
            c1 = "";
            fo_(i,0,m-1)if (c[i] == 'Y') c1 += 'N';else c1 += 'Y';
        }
    } else {cout<<"-1\n";}
    return 0;
}