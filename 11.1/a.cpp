#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int T;cin>>T;
    while(T--){
        int n,k;cin>>n>>k;
            int a1,a2,b2,b1,x;
        if(n==1){
            int x1,x2;cin>>x1>>x2;
            cout<<(x1+x2>k ? "No\n":"Yes\n");
        }else{
            a1 = a2 = b1 = b2 = x = 0;
        for(int i = 1;i<=n;i++){
            if(i==1) cin>>a2;
            else if(i==n) cin>>a1;
            else cin>>x;
        }
        for(int i =1;i<=n;i++){
            if(i==1) cin>>b1;
            else if(i==n) cin>>b2;
            else cin>>x;
        }
        cout<< ((a1+b1<=k && a2+b2<=k)?"Yes\n": "No\n");
        }
        // printf("%d %d %d %d\n",a1,b1,a2,b2);
    }
    return 0;
}