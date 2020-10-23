#include <bits/stdc++.h>
using namespace std;
#define N 10010
int s[N], tp = 0;
int S[N];
int meet = -1;
int a[N];
int solve(){
    memset(s,0,sizeof(s));
    memset(S,0,sizeof(S));
    tp = 0;meet = -1;
    memset(a,0,sizeof(a));
int n;cin>>n;
    for(int i =1;i<=n;i++)cin>>a[i];
    for(int i = 1;i<=n;i++){
        if(a[i]==1 && meet==-1){
            meet = i;
        }else if(a[i]==1){
            int len = i -meet-1;
            if(len!=0){
                s[++tp] = len;
            }
            meet = i;
        }
    }
    int anss = 998244353;
    int ans = 0;
    S[1] = s[1];
    for(int i =2;i<=n;i++){
        S[i] = S[i-1]+s[i];
    }
    // for(int i = 1;i<=tp;i++){cout<<S[i]<<" ";}
    for(int piv=1;piv<=tp;piv++){
        ans = 0;
        for(int i =0;i<=piv;i++){
            ans+= S[i];
        }
        for(int i =piv+1;i<=tp;i++){
            ans+= S[i]-S[piv];
        }
        anss = min(ans,anss);
    }
    if(tp==0) printf("0\n");
    else printf("%d\n",anss);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
    int T;cin>>T;while(T--) solve();
}