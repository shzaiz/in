#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,f[N],a[N];
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    f[1] =1;
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<i;j++){
            if(a[j] & a[i]){
                f[i] = max(f[i],f[j]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) ans = max(ans,f[i]);
    printf("%d\n",ans);
}