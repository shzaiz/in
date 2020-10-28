#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int T;cin>>T;
    while(T--){
        int l ;cin>>l;
        cin>>s;
        int cnt[2] = {0,0};
        int x = 1;
        for(int i = 0;i<l;i++){
            while(s[i]!=s[i+1]){i++;}
            cnt[x] ++;
            x^=1;
        }
        printf("%d\n",min(cnt[0],cnt[1]));
    }
}