// https://codeforces.com/problemset/problem/1426/F

#include <bits/stdc++.h>
const int MOD = 1e9+7;
using namespace std;
#define ll long long
#define int unsigned long long
int l;
string s = "acbbac";
int f[500005][4];
int cnt[500005];

int mul(int x,int y){return ((x%MOD)*(y%MOD))%MOD;}
int add(int x,int y){return ((x%MOD)+(y%MOD))%MOD;}
int qp(int a,int n){
    ll res  =1,bs = a;
    while(n>0){
        if(n&1) res = mul(res ,bs);
        bs = mul(bs,bs);
        n>>=1;
    }
    return res;
    // int res=  1;
    // for (int i =1;i<=n;i++){
    //     res = res*a;
    // }
    // return res;
}
signed main()
{
#ifdef FUCKCCF
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#endif
    string s;cin>>l;cin>>s;
    l = s.length();
    s = "_"+s;
    for(int i =1;i<=l;i++){
        cnt[i] = cnt[i-1];
        if(s[i]=='?'){ cnt[i]++;}
    }
    // printf("%d\n",qp(3,2));
    for (int i = 1; i <= l; i++) {
        if (s[i] != '?') {
            f[i][0] = add(f[i - 1][0],(s[i] == 'a' ? qp(3,cnt[i-1]) : 0)) ;
            f[i][1] = add(f[i - 1][1],(s[i] == 'b' ? f[i - 1][0] : 0)) ;
            f[i][2] = add(f[i - 1][2],(s[i] == 'c' ? f[i - 1][1] : 0)) ;
        } else {
            f[i][0] = add(3*f[i - 1][0] ,qp(3,cnt[i-1])) ;
            f[i][1] = add(3*f[i - 1][1], f[i - 1][0]) ;
            f[i][2] = add(3*f[i - 1][2],f[i - 1][1]) ;
        }
    }
    printf("%d\n", f[l][2]%MOD);
}
