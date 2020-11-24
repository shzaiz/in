#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 1005
bool to[N][N],vis[N];
int l[N],n,m,ans,sum[N]; 
bool Find(int x){
    for(int j=1;j<=n;j++)
        if(to[x][j]&&!vis[j]){
            vis[j]=true;
            if(l[j]==0||Find(l[j])){
                l[j]=x; sum[x]=j;
                return true;
            }
        }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        to[i][x+1]=to[i][y+1]=true;
    }
    for(int i=1;i<=m;i++){
        memset(vis,false,sizeof(vis));
        if(Find(i))ans++;
        else break;
    }
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++) printf("%d\n",sum[i]-1);
    return 0;
}