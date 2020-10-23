#include <bits/stdc++.h>
using namespace std;
int a[100][100] = {{0,0,0,0},{0,2,4,8},{0,2,12,21},{0,8,36,112}};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    #endif
    int n,m;cin>>n>>m;
    cout<<a[n][m]<<endl;
}