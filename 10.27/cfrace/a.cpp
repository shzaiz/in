#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int n;cin>>n;
    for(int i = 1;i<=n;i++){
        int x,y;cin>>x>>y;
        if(x==1 || y==1){
            printf("NO\n");

        }else {
            printf("YES\n");
        }
    }
}