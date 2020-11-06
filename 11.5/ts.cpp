/*
  Author : EnderDeer
  OnlineJudge : Luogu
*/

#include<bits/stdc++.h>

#define int long long

using namespace std;

int read(){
   int s = 0,w = 1;
   char ch = getchar();
   while(ch < '0' || ch > '9'){if(ch == '-')w = -1;ch = getchar();}
   while(ch >= '0' && ch <= '9')s = s * 10 + ch - '0',ch = getchar();
   return s * w;
}

struct node{
    int to;
    int nxt;
    int w;
}e[100010];

int cnt=0,head[100010];
int t;
int n,s;
int dis[100010];
int dep[100010];
int f[100010][26];

void add(int x,int y,int w){
    e[++cnt].to = y;
    e[cnt].nxt = head[x];
    e[cnt].w = w;
    head[x] = cnt;
}

void dfs(int u,int fa){
    // dep[x] = dep[father] + 1;
    // f[x][0] = father;
    // for(int i = 1;i * 2 <= dep[x];i ++){
    //     f[x][i] = f[f[x][i - 1]][i - 1];
    // }
    for(int i = head[u];i;i = e[i].nxt){
        int v = e[i].to;
        if(v== fa) continue;
        dfs(v,u);
    }
    // for(int i = head[x];i;i = e[i].nxt){
    //     int now = e[i].to;
    //     if(now == father)continue;
    //     // dis[now] = dis[x] + e[i].w;
    //     dfs(now,x);
    // }
}

int lca(int x,int y){
    if(dep[x] < dep[y])swap(x,y);
    for(int i = 25;i >= 0;i --){
        if(dep[f[x][i]] >= dep[y])x = f[x][i];
        if(x == y)return x;
    }
    for(int i = 25;i >= 0;i --){
        if(f[x][i] != f[y][i]){
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int query(int a,int b,int c){
    int zhong = lca(a,b);
    if(dep[a] - dep[zhong] + 1 >= c){
        int ans = dep[a] - c + 1;
        for(int i = 25;i >= 0;i --){
            if(i * 2 <= dep[a] - ans){
                a = f[a][i];
            }
        }
        return a;
    }
    else {
        int ans = dep[zhong] * 2 - dep[a] + c - 1;
        for(int i = 25;i >= 0;i --){
            if(dep[b] - i * 2 >= ans){
                b = f[b][i];
            }
        }
        return b;
    }
}

signed main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>t;
    while(t --){
        memset(e,0,sizeof(e));
        memset(dis,0,sizeof(dis));
        memset(head,0,sizeof(head));
        memset(dep,0,sizeof(dep));
        memset(f,0,sizeof(f));
        cnt = 0;
        s = 1;
        cin>>n;
        for(int i = 1;i < n;i ++){
            int x,y,w;
            x = read(),y = read(),w = read();
            add(x,y,w);
            add(y,x,w);
        }
        dfs(s,0);
        string op;
        while(1){
            int a,b,c;
            cin>>op;
            if(op == "DONE")break;
            else if(op == "DIST"){
                a = read(),b = read();
                int zhong = lca(a,b);
                cout<<dis[a] + dis[b] - 2 * dis[zhong]<<endl;
            }
            else if(op == "KTH") {
                a = read(),b = read(),c = read();
                cout<<query(a,b,c)<<endl;
            }
        }
    }
    return 0;
}