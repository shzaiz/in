#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define int unsigned long long
int n;
bool check(int mid){
    int ans = (mid*mid+mid)/2;
    if(ans>n+1) return 0;
    else return 1;
}

signed main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>n;
    int l=1,r=n+1;
    // cout<<check(3);
    while (l < r){
        int mid = (l + r+1) >> 1;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    cout<<n-l+1<<endl;
}