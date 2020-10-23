#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
const int maxn=150+10;
const int inf=0x3f3f3f3f;
struct node{
    int x;
    int y;
}a[maxn];
double cal(int i,int j){
    return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}
int n;
double dis[maxn][maxn],ldis[maxn],l1,l2=inf,ans;
int main(){
    int tmp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%1d",&tmp);
            if(tmp)dis[i][j]=cal(i,j);
            else if(i!=j)dis[i][j]=inf;
        }    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(dis[i][j]!=inf)ldis[i]=max(dis[i][j],ldis[i]);
            l1=max(l1,ldis[i]);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dis[i][j]==inf)
                l2=min(ldis[i]+cal(i,j)+ldis[j],l2);
    ans=max(l1,l2);
    printf("%.100f",ans);
    return 0;
}
