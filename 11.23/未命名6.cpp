#include<bits/stdc++.h>
#define il inline
#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
using namespace std;
const int N=5005,inf=23333333;
int T,to[N],tot[N],net[N],h[N],w[N],dis[N],cnt,n,m;
bool vis[N];
queue<int>q;
void add(int u,int v,int c){to[++cnt]=v,net[cnt]=h[u],h[u]=cnt,w[cnt]=c;}
bool spfa(int s){
    For(i,1,n)dis[i]=-inf;
    q.push(s);dis[s]=0;vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;tot[u]++;
        if(tot[u]==n)return 0;
        for(int i=h[u];i;i=net[i])
            if(dis[to[i]]<dis[u]+w[i]){
                dis[to[i]]=dis[u]+w[i];
                if(!vis[to[i]])q.push(to[i]),vis[to[i]]=1;
            }
	}
	return 1;
    
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        cnt=0;
        memset(vis,0,sizeof(vis));
        memset(h,0,sizeof(h));
        memset(tot,0,sizeof(tot));
        int u,v,c,f;
        while(m--){
            cin>>u>>v>>c;
            add(u-1,v,c);add(v,u-1,-c);
        }
        f=0;
        For(i,0,n){
            if(!tot[i]){
                if(!spfa(i)){f=1;break;}
            }
        }
        if(!f)printf("true\n");
        else printf("false\n");
    }
    return 0;
}
