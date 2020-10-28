#include<string.h>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;
#define maxn 100030
int a[maxn],dp[maxn];
int findx(int l,int r,int x){
    int i,j,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(dp[mid]==x)return mid;
        if(dp[mid]>x){
            l=mid+1;
        }
        else r=mid-1;
    }
    return l;
}
int main()
{
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int n,m,i,j,len;
    int T;cin>>T;while(T--){
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        len=1;dp[1]=a[1];
        for(i=2;i<=n;i++){
            if(a[i]<dp[len]){
                len++;dp[len]=a[i];continue;
            }
            j=findx(1,len,a[i]);
            dp[j]=a[i];
        }
        printf("%d\n",len);
    }}
    return 0;
}