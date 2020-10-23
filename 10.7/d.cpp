#include <bits/stdc++.h>
using namespace std;
#define int long long
#define D double
#define N 13497509
D x[N];
D y[N];
D pt[N][4];
D eps = 1e-9;
int cnt = 0;
void eq(D a1,D b1,D c1,D a2,D b2,D c2){
     x[++cnt] = (b1*c2 -b2*c1)/(b1*a2-b2*a1);
     y[cnt] = (c1*a2-c2*a1)/(b1*a2-b2*a1);
}
signed main(){
    int n;cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>pt[i][1]>>pt[i][2]>>pt[i][3];
    }
    for(int i = 1;i<n;i++){
        for(int j = i+1;j<=n;j++){
            eq(pt[i][1],pt[i][2],pt[i][3],pt[j][1],pt[j][2],pt[j][3]);
        }
    }
    sort(x+1,x+1+cnt);
    sort(y+1,y+1+cnt);
    D x11 = x[cnt/2+1];
    D y11 = y[cnt/2+1];
    if(abs(x11)<=eps) x11 = 0;
    if(abs(y11)<=eps) y11 = 0;
    cout<<fixed<<setprecision(6)<<x11<<" "<<y11<<endl;
    return 0;
}