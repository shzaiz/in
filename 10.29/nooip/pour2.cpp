#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y;
int exgcd(int a,int b) {
    if(b==0) {
        x=1,y=0;
        return a;
    }
    int gcd=exgcd(b,a%b);
    int t=x;
    x=y;
    y=t-a/b*y;
    return gcd;
}

signed main() {
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("pour.in","r",stdin);
    freopen("pour.out","w",stdout);
    #endif
    int a,b;
    scanf("%lld%lld",&a,&b);
    int gcd=exgcd(a,b);
    b/=gcd,x%=b;
    if(x>0) x-=b;x=-x;
    printf("%lld\n%d %lld",gcd,x,(x*a+gcd)/(b*gcd));
    return 0;
}