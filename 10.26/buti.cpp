#include <bits/stdc++.h>
using namespace std;
#define N 10010
#define D double
D L,a,b,t,r;
int n;
int c[N];
D f[N];
int which(int x,int y){
    int dis = c[y] - c[x];
    if( t*a+r*b>dis) return 2; // Coffee has not cool down
    else if(t*a>dis) return 1; // coffee is having effect
    else return 3; // coffee has run out of its effect.
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>L>>a>>b>>t>>r;
    cin>>n;
    int i = 0;
    for(i = 1;i<=n;i++){
        cin>>c[i];
    }
    c[i] = L;
    f[1] = 0.0;
    for(int i = 2;i<N;i++) f[i] = 998244353.0;
    for(int i = 0;i<=n+1;i++){
        for(int j = 0;j<i;j++){
            int type = which(i,j);
            D dis = abs(c[i]-c[j]);
            printf("%d[ %d %d ]%lf\n",type,i,j,dis);
            if(type==1) f[i] = min(f[i], f[j]+(dis/a));
            else if(type == 2) f[i] = min(f[i],f[j]+t+(dis-a*t)/b);
            else if(type == 3) f[i] = min(f[i],f[j]+t+r+(dis-a*t-b*r)/a);
        }
    }
    cout<<f[n+1];
}