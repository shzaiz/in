#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
struct Edge{
    int to,nxt,flow,dis;
}e[N];
int n,m,s,t,vis[N],dis[N],flow[N],pre[N],last[N],head[N],cnt=0,mxflow,mincost;
void adde(int u,int v,int flow,int dis){
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    e[cnt].flow = flow;
    e[cnt].dis = dis;
    head[u] = cnt;
}
queue<int > Q;
// bool spfa(int s,int t){
    // memset(dis,127/3,sizeof(dis));
    // memset(flow,127/3,sizeof flow);
    // memset(vis,0,sizeof 0);
    // Q.push(s); vis[s] = 1, dis[s] = 0, pre[t] = -1;
//     while(!Q.empty()){
//         int u = Q.front();Q.pop();
//         vis[u] = 0;
//         for(int i = head[u];~i;i = e[i].nxt){
//             int v = e[i].to;
//             if(e[i].flow>0 && dis[v]>dis[u]+e[i].dis){
//                 dis[v] = dis[u]+e[i].dis;
//                 pre[v] = u;
//                 last[v] = i;
//                 flow[v] = min(flow[u],e[i].flow);
//                 if(!vis[v]){
//                     vis[v] = 1;Q.push(v);
//                 }
//             }
//         }
//     }
//     return pre[t]!=1;
// }
#define maxflow mxflow
#define edge e
#define q Q
#define next nxt
bool spfa(int s,int t)
{
	 memset(dis,127/3,sizeof(dis));
    memset(flow,127/3,sizeof flow);
    memset(vis,0,sizeof 0);
    Q.push(s); vis[s] = 1, dis[s] = 0, pre[t] = -1;
	
	while (!q.empty())
	{
		int u = Q.front();Q.pop();
        vis[u] = 0;
        for(int i = head[u];~i;i = e[i].nxt){
            int v = e[i].to;
            if(e[i].flow>0 && dis[v]>dis[u]+e[i].dis){
                dis[v] = dis[u]+e[i].dis;
                pre[v] = u;
                last[v] = i;
                flow[v] = min(flow[u],e[i].flow);
                if(!vis[v]){
                    vis[v] = 1;Q.push(v);
                }
            }
        }
	}
	return pre[t]!=-1;
}
void MCMF()
{
	while (spfa(s,t))
	{
		int now=t;
		maxflow+=flow[t];
		mincost+=flow[t]*dis[t];
		while (now!=s)
		{//从源点一直回溯到汇点 
			edge[last[now]].flow-=flow[t];//flow和dis容易搞混 
			edge[last[now]^1].flow+=flow[t];
			now=pre[now];
		}
	}
}
#undef maxflow
#undef edge
#undef Q
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    memset(head,-1,sizeof head);
    cin>>n>>m>>s>>t;
    fo(i,m) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        adde(a,b,c,d);adde(b,a,0,-d);
    }
    MCMF();
    cout<<mxflow<<" "<<mincost;
    return 0;
}