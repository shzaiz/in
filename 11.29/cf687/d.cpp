#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
int n,a[N];
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int n;cin>>n;
    fo(i,n) cin>>a[i];
    int nn = unique(a+1,a+n+1)-a-1;
    fo_(i,2,n){
        int x = a[i-1] ^ a[i];
        a[i] = x;
        if(i==n){
            cout<<"-1";
            return 0;
        }
        if(a[i]>a[i+1]){
            cout<<i-1<<endl;
            return 0;
        } 
    }
}