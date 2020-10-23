#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=305;
int main(){
    LL n,tmp;
    while(~scanf("%lld",&n)){
        if(n>1&&n<10) {
            puts("Stan wins.");
            continue;
        }
        LL ans=0,p=1;
        while(p<n){
            if(ans&1) p*=2;
            else p*=9;
            ans++;
        }
        printf("%s wins.\n",ans%2?"Stan":"Ollie");
    }
    return 0;
}
