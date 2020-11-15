#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10
int a[N] = {0,2,0};
int f[29][14];
int n = 2;
int dfs(int i,int hi,int lim,int last){
    if(i==n+1) {return 1;}
    int ans = 0;
    fo_(j,0,9){
        if((abs(j-last)<2) ||( lim && j>a[i])) continue;
        // cout<<j;
         if(j!=0 &&!hi && !lim && f[i+1][j+3]!=-2) ans+=f[i+1][j+3];
        else ans += dfs(i+1,j==0&&hi , j==a[i] && lim,(j==0&&hi)?-3:j);
    }
    if(last>0 && !hi && !lim) f[i][last+3] = ans;
    return ans;
}
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    fo_(i,0,28) fo_(j,0,13) f[i][j] = -2;
    string s,t;
    cin>>s>>t;

    n = s.length();
    fo_(i,0,n-1) {a[i+1] = s[i]-'0';if(i==n-1) a[i+1]--;}
    int ans1 = dfs(1,1,1,-3);

    n = t.length();
    fo_(i,0,n-1) a[i+1] = t[i]-'0';
    int ans2 = dfs(1,1,1,-3);
    cout<<ans2-ans1<<endl;
    return 0;
}