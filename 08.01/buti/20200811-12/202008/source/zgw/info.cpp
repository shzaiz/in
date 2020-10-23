#include<bits/stdc++.h>
#define ll long long
#define fo freopen
using namespace std;
const int N=100001;
int n,cnt;
int l[N],r[N],vis[N];
int bfs(int w) {
    queue<int>Q;
    memset(vis,-1,sizeof(vis));
    vis[w]=0;cnt=n-1;Q.push(w);
    while(!Q.empty()) {
        int now=Q.front();Q.pop();
        for(int i=1,nxt=now;i<=l[now];i++){nxt=(nxt-2+n)%n+1;if(vis[nxt]==-1){Q.push(nxt),vis[nxt]=vis[now]+1,cnt--;}}
        for(int i=1,nxt=now;i<=r[now];i++){nxt=nxt%n+1;if(vis[nxt]==-1) Q.push(nxt);vis[nxt]=vis[now]+1;cnt--;}
        if(cnt==0)return vis[now]+1;
    }
}
int main() {
	fo("info.in","r",stdin);fo("info.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&l[i]);
    for(int i=1; i<=n; i++)scanf("%d",&r[i]);
    for(int i=1; i<=n; i++) {printf("%d ",bfs(i));}
    return 0;
}
