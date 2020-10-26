#include <bits/stdc++.h>
#define MAXN 5010
#define lowbit(x) x&-x
#define int long long
using namespace std;
int n,k,a[MAXN],t[MAXN];
inline void A(int pos,int val){
    while(pos<=n){
        t[pos]+=val;
        pos+=lowbit(pos);
    }
}
inline int S(int pos){
    int res=0;
    while(pos){
        res+=t[pos];
        pos-=lowbit(pos);
    }
    return res;
} 
inline int rev(){
    int res=0;
    for(int i=n;i>=1;i--){
        res+=S(a[i]);
        A(a[i],1);
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    #endif
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int tot=rev(),ans=tot*k;
    for(int i=1;i<=tot;++i){
        if(i>=k)break;
        ans+=i-k;
    }
    printf("%lld\n",ans);
    return 0;
}