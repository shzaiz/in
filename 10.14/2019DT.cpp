#include <bits/stdc++.h>
#define int long long
using namespace std;
// void g(int n,int m){
//     if(n==1 && m==1) {printf("1");return;}
//     if(n==1 && m==0) {printf("0");return;}
//     if(m>=((1<<n)/2-1)){
//         printf("1");
//         g(n-1,(1<<n)-1-m);
//         return;
//     }else{
//         printf("0");
//         g(n-1,m);
//         return;
//     }
// }
void g(int n,int m){
    while(n!=1ULL){
        if(m>((1ULL<<(n-1ULL))-1ULL)){
            printf("1");
            m=(pow(2ull,n)-1ull-m);n--;
        }else{
            printf("0");
            n--;
        }
    }
     printf("End:%lld %lld\n",n,m);
    if(n==1ULL && m==1ULL) {printf("1");return;}
    if(n==1ULL && m==0ULL) {printf("0");return;}
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
    #endif
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    int x,y;cin>>x>>y;
    g(x,y);
    return 0;
}