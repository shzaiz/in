#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("xbzalopo.in","r",stdin);
    freopen("xbzalopo.out","w",stdout);
    #endif
    int n;
    cin>>n;
    int a[100010];
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int start  = 0;
    int end = 0;

    for(int i = 1;i<=n;i++){
        if(start==0 && a[i]==1){
            start = i; 
        }else if(start != 0 && a[i] == 1){
            end = i;
        }
    }
    int ans=0;
    for(int i = start;i<=end;i++){
        if(a[i]==0) ans++; 
    }
    printf("%d\n",ans);
}