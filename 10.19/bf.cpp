#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define MOD 998244353
#define ll long long 
int f[2][N];
int s[N] = { 0, 0, 0, 0, 1, 0, 1, 0, 0, 2 };
int cnt0 = 0;
int pv = -1;
int bk = -1;
int ans1 = 1;
int ans2 = 1;
bool combo = false;
int n , k , mood;
ll add(ll a,ll b){return ((a%MOD)+(b%MOD)%MOD);}
ll mul(ll a,ll b){return ((a%MOD)*(b%MOD)%MOD);}
ll qpow(ll u, ll v){
    ll rep = 1;
    while (v > 0) {
        if (v & 1) {
            rep = mul(rep , u);
        }
        u = mul(u,u);
        v >>= 1;
    }
    return rep;
}
ll sub(ll a,ll b){return ((a%MOD)-(b%MOD)+MOD)%MOD;}
ll div(ll a,ll b){return mul(a,qpow(b,MOD-2));}
struct Edge{
    int to,nxt;
}e[N];
int head[N],cnt = 0;
void adde(int u,int v){
    e[++cnt].to =v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void dfs(int u,int fa){
    
}

int main(){
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/ac2.in", "w", stdout);
    
    cin >> n >> k >> mood;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 1;i<n;i++){
        adde(i,i+1);
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[0][i] =add (f[1][i - 1] , mul((k - 2) , f[0][i - 1]));
        f[1][i] = mul((k - 1) ,f[0][i - 1]);
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 && s[i] == 0) {
            ans2 = mul(ans2 , k);
            printf("pos[%d] :%d  ...(1)\n", i, mul(ans2 , ans1));
        } else if (s[i] == 0) {
            cnt0++;
            combo = 1;
            if (!combo)
                pv = i - 1;
            ans2 = mul(ans2 , (k - 1));
            printf("pos[%d] :%d   ...(2)\n", i, mul(ans2 , ans1));
        } else {
            bk = i;
            if (combo) {
                if (pv == -1) {
                    printf("%d %d\n",k-1,bk-1);
                    ans1 = mul(1,qpow(k-1, bk));
                } else if (s[pv] == s[bk]) {
                    ans1 = mul(ans1 ,f[1][bk - pv - 1]);
                } else {
                    ans1 = mul(ans1,f[0][bk - pv - 1]);
                }
                printf("pos[%d] :%d   ...(3)\n", i, ans1);
                ans2 = 1;

            } else {
                printf("pos[%d] :%d   ...(4)\n", i, ans1);
            }
            pv = i, bk = -1;
            combo = false;
            cnt0 = 0;
        }
    }
}