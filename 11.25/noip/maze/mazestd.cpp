#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 310
using namespace std;
int n,m,head=1,tail,f[maxn][maxn];
char s[maxn][maxn],c;
struct node{
    int x,y,t;
}q[maxn*maxn];
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
int Bfs(){
    int mx=0;
    while(head<=tail){
        node p=q[head++];
        int x=p.x,y=p.y,t=p.t;
        mx=max(mx,t);
        for(int i=0;i<4;i++){
            int nx=x+xx[i];
            int ny=y+yy[i];
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&f[nx][ny]==0&&s[nx][ny]==' ')
                f[nx][ny]=1,q[++tail]=(node){nx,ny,t+1};
        }
    }
    return mx;
}
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    scanf("%d%d",&m,&n);c=getchar();
    m=m*2+1;n=n*2+1;
    for(int i=1;i<=n;i++)gets(s[i]+1);
    for(int i=1;i<=m;i++)
        if(s[1][i]==' ')q[++tail]=(node){1,i,0},f[1][i]=1;
    for(int i=1;i<=m;i++)
        if(s[n][i]==' ')q[++tail]=(node){n,i,0},f[n][i]=1;
    for(int i=1;i<=n;i++)
        if(s[i][1]==' ')q[++tail]=(node){i,1,0},f[i][1]=1;
    for(int i=1;i<=n;i++)
        if(s[i][m]==' ')q[++tail]=(node){i,m,0},f[i][m]=1;
    printf("%d\n",Bfs()+1>>1);
    return 0;
}
