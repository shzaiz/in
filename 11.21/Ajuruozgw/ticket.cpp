#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
typedef long long ll;
int a[20];
int dp[20][2];
int dfs(int pos,int pre,int sta,bool lim){
    if(pos==-1) return 1;
    if(!lim && dp[pos][sta]!=-1) return dp[pos][sta];
    int tmp=0;
    for(int i=0;i<=(lim ? a[pos] : 9);i++){
        if(pre==3 && i==7)continue;
        if(i==4) continue;
        tmp+=dfs(pos-1,i,i==3,(lim && i==a[pos]));
    }
    if(!lim) dp[pos][sta]=tmp;
    return tmp;
}
int solve(int x){
    int pos=0;
    while(x){a[pos++]=x%10;x/=10;}
    return dfs(pos-1,-1,0,true);
}
int main(){
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);

    int le,ri;
    cin>>le>>ri;
    memset(dp,-1,sizeof dp);
    int rr = solve(ri);
    int ll = solve(le-1);
    cout<<rr-ll;
    return 0;
}
