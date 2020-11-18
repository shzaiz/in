#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define ll long long
ll n,m,ans;
ll to[N];
struct node{
    ll to,nex;
}e[N];
ll x,y,tot;
ll head[N];
bool vis[N];
void add(ll a,ll b){
    e[++tot].to=b;
    e[tot].nex=head[a];
    head[a]=tot;
}
bool find(ll x){
    ll xx;
    for(ll i=head[x];i;i=e[i].nex){
        xx=e[i].to;
        if(!vis[xx]){
            vis[xx]=1;
            if(!to[xx]||find(to[xx])){
                to[xx]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    cin>>n>>m>>x>>y;
    while(x!=-1&&y!=-1){
        if(x<=n&&y<=m) add(x,y);
        cin>>x>>y;
    }
    for(ll i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(find(i)) ans++;
    }
    cout<<ans<<endl;
    for(ll i=n+1;i<=m;i++){
        if(to[i]) cout<<to[i]<<" "<<i<<endl;
    }
    return 0;
}