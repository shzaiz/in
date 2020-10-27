#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 100010
int n,m,dis[maxn],num,head[maxn*2],step[maxn];
bool vis[maxn],flag;
int qread(){
    int i=0,j=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')j=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){i=i*10+ch-'0';ch=getchar();}
    return i*j;
}
struct node{
    int to,pre,v;
}e[maxn*2];
void Insert(int from,int to,int v){
    e[++num].to=to;
    e[num].v=v;
    e[num].pre=head[from];
    head[from]=num;
} 
void spfa(int x){
    if(flag)return;
    vis[x]=1;
    for(int i=head[x];i;i=e[i].pre){
        int to=e[i].to;
        if(dis[to]>dis[x]+e[i].v){
            dis[to]=dis[x]+e[i].v;
            if(vis[to]){flag=1;return;}
            spfa(to);
        }
    }
    vis[x]=0;
} 
int main(){
    // #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    // #else
    // freopen("akioi.in","r",stdin);
    // freopen("akioi.out","w",stdout);
    // #endif
    n=qread();m=qread();
    int op,x,y,z;
    for(int i=1;i<=m;i++){
        op=qread();
        if(op==1){
            x=qread();y=qread();z=qread();
            Insert(x,y,-z);
        }
        if(op==2){
            x=qread();y=qread();z=qread();
            Insert(y,x,z);
        }
        if(op==3){
            x=qread();y=qread();
            Insert(x,y,0);
            Insert(y,x,0);
        }
    }
    for(int i=1;i<=n;i++)Insert(0,i,0);
    memset(dis,127/3,sizeof(dis));
    dis[0]=0;
    spfa(0);
    if(flag)printf("No");//存在负环 
    else printf("Yes");
    return 0;
}        