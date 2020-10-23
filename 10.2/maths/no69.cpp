// #include <bits/stdc++.h>
// using namespace std;
// int n = 3;
// int a[1000] = {0,1,2,3};
// int dfs(int pos, int lim,int pre){
//     printf("%d %d %d\n",pos,lim,pre);
//     int ans = 0;
//     if(pos == 0){
//         return 1;
//     }
//     int up  = lim ? a[pos]:9;
//     for(int i = 0;i<=up;i++){
//         if(i==4){
//             continue;
//         }
//         if(i==2 && pre == 6){
//             continue;
//         }
//         ans +=dfs(pos-1,lim & (i==a[pos]),i); 
//     }
//     return ans;
// }
// int main(){
//     freopen("D:\\Testcases\\wa.in","r",stdin);
//     freopen("D:\\Testcases\\wa.out","w",stdout);
//     cout<<dfs(3,1,-1);    
// }


#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
int a[20];
int dp[20][2];
// int dfs(int pos,int pre,bool limit){
//     if(pos==-1) return 1;
//     int up=limit ? a[pos] : 9;
//     int tmp=0;
//     for(int i=0;i<=up;i++)
//     {
//         if(pre==6 && i==2)continue;
//         if(i==4) continue;//都是保证枚举合法性
//         tmp+=dfs(pos-1,i,limit && i==a[pos]);
//     }
//     return tmp;
// }
int dfs(int pos, int lim,int pre){
    printf("%d %d %d\n",pos,lim,pre);
    int ans = 0;
    if(pos == -1){
        return 1;
    }
    int up  = lim ? a[pos]:9;
    for(int i = 0;i<=up;i++){
        if(i==4){
            continue;
        }
        if(i==2 && pre == 6){
            continue;
        }
        ans +=dfs(pos-1,lim & (i==a[pos]),i); 
    }
    return ans;
}
int solve(int x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,-1,true);
}
int main()
{
        freopen("D:\\Testcases\\wa.in","r",stdin);
    freopen("D:\\Testcases\\wa.out","w",stdout);
    int le,ri;
    //memset(dp,-1,sizeof dp);可优化
    while(~scanf("%d%d",&le,&ri) && le+ri)
    {
        memset(dp,-1,sizeof dp);
        printf("%d\n",solve(ri)-solve(le-1));
    }
    return 0;
}