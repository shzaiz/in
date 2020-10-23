#include <bits/stdc++.h>
using  namespace std;
#define N 200010
char s[N];
int tp = 0;
int solve(){
    memset(s,0,sizeof(s));
    tp = 0;
    string str;
    cin>>str;
    int len = str.length();
    for(int i = 0;i<len;i++){
        s[++tp] = str[i];
        if((s[tp]=='B' && s[tp-1]=='B') ||(s[tp]=='B' && s[tp-1]=='A')){
            tp-=2;
        }

    }
    printf("%d\n",tp);
}
int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("D:/Testcases/in.ac","r",stdin);
    // freopen("D:/Testcases/out.ac","w",stdout);
    // #else
    // #endif
    int T;cin>>T;while(T--)
    solve();
}