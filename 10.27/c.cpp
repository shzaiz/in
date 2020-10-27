#include <bits/stdc++.h>
using namespace std;
#define tm fuckccf
#define clock nmsl
#define N 500010
int indeg[N];
int indegg[N];
int n, k1, k2;
struct Edge {
    int to, nxt;
} e[N];
int head[N], cnt = 0;
void adde(int u, int v)
{
    indeg[v]++;indegg[v]++;
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
int clock = 0;
int vis[N], tm[N];
queue<int > Q;
void topo(int u)
{
    Q.push(u);
    vis[u] = 1;
    tm[u] = ++clock;
    while(!Q.empty()){
        // int v = e[i]
        // for(int i = head[u];i;i = e[i].nxt){

        }
    }
}
int main()
{
#ifdef FUCKCCF
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
    freopen("dizzy.in", "r", stdin);
    freopen("dizzy.out", "w", stdout);
#endif
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= k1; i++) {
        int a, b;
        cin >> a >> b;
        adde(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if(indeg[i] == 0) {topo(i);}
    }
    for (int i = 1; i <= k2; i++) {
        int a, b;
        cin >> a >> b;
        if (tm[a] > tm[b])
            printf("%d %d\n", b, a);
        else
            printf("%d %d\n", a, b);
    }
    return 0;
}