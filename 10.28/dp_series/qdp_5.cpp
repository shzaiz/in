#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int v[N];
int w[N];
int f[N];
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int n,m;cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = m;j>=v[i];j--){
            f[j] = max(f[j],f[j-v[i]]+w[i]);
        }
    }
    printf("%d",f[m]);
}