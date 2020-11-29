#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
const int maxn = 500005;         //最大顶点数
const int maxm = 500005;        //最大边数
const int inf = 0x3f3f3f3f;     //inf无限大
struct edge{                    //链式前向星建图
    int to,next,w;
}e[maxm];
int using_v[maxn],using_times[maxn];//入队的点和点的入队次数
int head[maxn],dis[maxn];
int cnt=0;
void addedge(int u,int v,int w){
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
int spfa(int start){
    queue<int>q;
    dis[start] = 0;         //起始点离自己的dis为0
    using_v[start] = 1;     //起始点标记
    q.push(start);          //入队
    while(!q.empty()){//fs
        int top=q.front();  //队首
        q.pop();            //取出
        using_v[top] = 0;   //top这个点暂时没在队列中
        using_times[top]++; //使用次数++
        for(int i = head[top];i;i=e[i].next){   //图遍历
            if(dis[e[i].to]>dis[top]+e[i].w){   //松弛
                dis[e[i].to] = dis[top]+e[i].w;
                if(!using_v[e[i].to]){
                    using_v[e[i].to] = 1;       //入队
                    q.push(e[i].to);
                }
            }
        }
    }
    return 1;
}
int a,b,x,y;
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>a>>b>>x>>y;
    memset(dis,inf,sizeof(dis));
    
    fo(i,100 ) addedge(i,i+100,x),addedge(i+100,i,x);
    fo(i,99 ) addedge(i+1,i+100,x),addedge(i+100,i+1,x);
    fo(i,99) addedge(i,i+1,y),addedge(i+1,i,y);
    fo_(i,101,199) addedge(i,i+1,y),addedge(i+1,i,y);

    spfa(b+100);
    cout<<dis[a];
    

    return 0;
}