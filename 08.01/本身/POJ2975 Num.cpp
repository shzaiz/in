#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
int n,ans,x,a[1005];
int main(){
    while (~scanf("%d",&n)){
        if (n==0) break;
        int s=0;
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            s^=a[i];
        }
        ans=0;
        for (int i=1;i<=n;i++)
         if ((s^a[i])<a[i]) ans++;
        printf("%d\n",ans);
    }
}
