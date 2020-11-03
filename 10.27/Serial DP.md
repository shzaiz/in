Hi. 我是一个什么DP都不会的蒟蒻. 

# Serial DP

## Problem 1. [Zero Remainder Sum](https://codeforces.com/problemset/problem/1433/F)

- Hint: You may use search algorithm to handle this complicated transitions between states.

- Takeaway: setting states like$f[i][j]$ as the current coordinate is quite common in graphs like this.

Code implementation:

```cpp
// CF 1433F.
// http://codeforces.com/problemset/problem/1433/F

#include <bits/stdc++.h>
using namespace std;
#define N 75
int a[N][N];
int f[N][N][N][N];
int dp[N][N][N][N];
#define INF 998244353
#define fo(i,n) for(int i =1;i<=(int)n;i++) 
#define fo0(i,n)for(int i =0;i<=(int)n;i++) 
#define mmax(x,y) (x) = max((x),(y))
int n,m,u,k;

int dfs(int x,int y,int chose, int remain ){
    // printf("%d %d %d %d\n",x,y,chose,remain);
    // f[x][y][chose][remain] = 0;
    if(x==n+1) return remain == 0? -999: 0;
    if(chose == m/2 || y==m+1) return  dfs(x+1,1,0,remain);
    
    if(f[x][y][chose][remain]!=-1)  return f[x][y][chose][remain];
    return f[x][y][chose][remain] = max(dfs(x,y+1,chose, remain),a[x][y]+dfs(x,y+1,chose+1, (remain+a[x][y])%u));
}

int solve(int i,int j,int mod,int taken) {
	if(dp[i][j][mod][taken]!=-1)return dp[i][j][mod][taken];
	if(i==n)
		return mod?-999999:0;
	if(j==m || taken==m/2)
		return solve(i+1,0,mod,0);
	return dp[i][j][mod][taken]=max(solve(i,j+1,mod,taken),a[i][j]+solve(i,j+1,(mod+a[i][j])%k,taken+1));
}

int main() {
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
	cin>>n>>m>>u;
	memset(dp,-1,sizeof(dp));
	memset(f,-1,sizeof(f));
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			cin>>a[i][j];
	cout<<dfs(1,1,0,0)<<endl;
	return 0;
}

```

## Problem2.  [Number of Subsequences](https://codeforces.com/problemset/problem/1426/F)

This one is not smooth for its states. But investing a problem is a good start to first downgrade it to the problem that I could solve. 

- Problem 2.1 What if there are no ‘?’.

  - set state$f[i][0]$ means how many sequence of ‘a’ before. $f[i][1]$ means how many sequence of ‘ab’ before. $f[i][3]$ means how many sequence of ‘abc’ before.

  - Then consider the letter on $f[i]$. if it is:

  - $$
    f[i][j][0] = \begin{cases}
    &f[i][j-1][0]+1&(\text{if f[i] = a}) 
    \end{cases}\\f[i][j][0] = \begin{cases}
    &f[i][j-1][1]+f[i][j-1][1]&(\text{if f[i] = b}) 
    \end{cases}\\f[i][j][2] = \begin{cases}
    &f[i][j-1][1]+f[i][j-1][0]&(\text{if f[i] = c}) 
    \end{cases}
    $$

  - This is a trivial transformation of state movement. 

  - So the code would work like :

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    string s = "acbbac";
    int f[10010][3];
    int main(){
        #ifdef FUCKCCF
        freopen("D:/Testcases/in.ac","r",stdin);
        freopen("D:/Testcases/out.ac","w",stdout);
        #endif
        int l  = s.length();
        f[0][s[0]-'a'] = 1;
        for(int i = 1;i<l;i++){
            f[i][0] = f[i-1][0] + (s[i]=='a' ? 1:0);
            f[i][1] = f[i-1][1] + (s[i]=='b'?f[i-1][0]:0);
            f[i][2] = f[i-1][2] + (s[i]=='c'?f[i-1][1]:0);
        }
        printf("%d\n",f[l-1][2]);
    }
    ```

- Problem 2.2 What things will happen if there are changer ‘?’

  - If we add ‘?’ as an changer , then there will be some problem. Let’s separate into two situation:

  - I. What if ? is on the current $id$?
    - Assume you are now standing on a ?, and before there is no ? . What will the answer change comparing to no ? .
    - Since this char is a ‘?’, it could be ‘a’ or ‘b’ or ‘c’. So when you are here making this transfer, it might need all of the things recalculated. 
    - Consider the perspective of problem. We can treat ? chars separately. So in this case, since it will transfer to $3^{c-1}$ legal strings that can get this thing done.
    - So adding number in the first will be $3^{n-1}$.
    - So every time we multiple one thing, we will $\times3$ before it.

  - So the code will be like this:

    ```cpp
    // https://codeforces.com/problemset/problem/1426/F
    
    #include <bits/stdc++.h>
    const int MOD = 1e9+7;
    using namespace std;
    #define ll long long
    #define int unsigned long long
    int l;
    string s = "acbbac";
    int f[500005][4];
    int cnt[500005];
    
    int mul(int x,int y){return ((x%MOD)*(y%MOD))%MOD;}
    int add(int x,int y){return ((x%MOD)+(y%MOD))%MOD;}
    int qp(int a,int n){
        ll res  =1,bs = a;
        while(n>0){
            if(n&1) res = mul(res ,bs);
            bs = mul(bs,bs);
            n>>=1;
        }
        return res;
        // int res=  1;
        // for (int i =1;i<=n;i++){
        //     res = res*a;
        // }
        // return res;
    }
    signed main()
    {
    #ifdef FUCKCCF
        freopen("D:/Testcases/in.ac", "r", stdin);
        freopen("D:/Testcases/out.ac", "w", stdout);
    #endif
        string s;cin>>l;cin>>s;
        l = s.length();
        s = "_"+s;
        for(int i =1;i<=l;i++){
            cnt[i] = cnt[i-1];
            if(s[i]=='?'){ cnt[i]++;}
        }
        // printf("%d\n",qp(3,2));
        for (int i = 1; i <= l; i++) {
            if (s[i] != '?') {
                f[i][0] = add(f[i - 1][0],(s[i] == 'a' ? qp(3,cnt[i-1]) : 0)) ;
                f[i][1] = add(f[i - 1][1],(s[i] == 'b' ? f[i - 1][0] : 0)) ;
                f[i][2] = add(f[i - 1][2],(s[i] == 'c' ? f[i - 1][1] : 0)) ;
            } else {
                f[i][0] = add(3*f[i - 1][0] ,qp(3,cnt[i-1])) ;
                f[i][1] = add(3*f[i - 1][1], f[i - 1][0]) ;
                f[i][2] = add(3*f[i - 1][2],f[i - 1][1]) ;
            }
        }
        printf("%d\n", f[l][2]%MOD);
    }
    
    
    
    ```

## Problem3. [1437C - Chef Monocarp](https://codeforces.com/problemset/problem/1437/C)

- First thought: greedy. But I got wrong answer on Test 2. So there’s no way greddy may work.

- Then we think about using dp. According to some solutions on the internet, they say it is a 01backpack problem.

- **Problem 3.1 Backpack problem**

  - $f[i][j] = \max(f[i-1][j],f[i-1][j-v[i]]+c[i])$.

  - According to the syntaxes of the backpack problem, we can cancel off one dimension,

  - $f[j] = \max(f[j],f[j-v[i]])$.

  - And here is the postcode:

    ```cpp
    for i = 1 to n;
    for j = n to 1;
    if(j-v[i]>0)
    f[j] = max(f[j],f[j-v[i]]);
    ```

- And he said are kind of similar?

  - If we regard a dish as a capacity, and then the time as the item, the value is the parameter we wanna minimize. Then we would see: if $f[i][j]$ represents at time $i$ handle $j$ plates in a row,
  - $f[i][j] = \min(f[i-1][j-1],f[i-1][j-1]+|t_{j-1}-i|)$
  - And That’s it! In fact There’s a lot of similarity of this one and that one!

```cpp
//1437C - Chef Monocarp
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n;
int t[N];
int dp[505][505];
void solve(){
    for(int i = 0;i<505;i++) for(int j = 0;j<505;j++) dp[i][j] = 998244353;
    dp[0][0] = 0;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>t[i];
    }
    sort(t,t+n);
    for(int i = 0;i<=205;i++){dp[i][0] = 0;}
    for(int i = 1;i<=2*n+1;i++){
        for(int j  =1;j<=n;j++){
            dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]+abs(i-t[j-1]));
        }
    }
    cout<<dp[2*n][n]<<endl;
}
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int T;cin>>T;while(T--) solve();
    
}
```

## Problem 4.[Golden Sword](https://www.luogu.com.cn/problem/P5858)

- 经过手%样例我们可以发现应该如何设计状态: $f[i][j]$表示当前有了$i$个物品, 放入的物品编号为$j$的情况.
- 状态转移 : $f[i][j] = \max(f[i-u][j-1]),u\in[0,s]$.
- 代码实现.

## Problem5. [绝世好题](https://www.luogu.com.cn/problem/P4310)

- 首先想法: f[i]表示从0到i的&值不等于0的数

- 状态转移: $f[i] = f[u]+1 (i \and u \neq 0)$.

- 代码实现:

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define N 100005
  int n,f[N],a[N];
  int main(){
      #ifdef FUCKCCF
      freopen("D:/Testcases/in.ac","r",stdin);
      freopen("D:/Testcases/out.ac","w",stdout);
      #endif
      cin>>n;
      for(int i = 1;i<=n;i++){
          cin>>a[i];
      }
      f[1] =1;
      for(int i = 2;i<=n;i++){
          for(int j = 1;j<i;j++){
              if(a[j] & a[i]){
                  f[i] = max(f[i],f[j]+1);
              }
          }
      }
      int ans = 0;
      for(int i = 1;i<=n;i++) ans = max(ans,f[i]);
      printf("%d\n",ans);
  }
  ```

- 考虑优化

## Problem6. [最长括号匹配](https://www.luogu.com.cn/problem/P1944)

- 感觉这不是一个DP试题. 
- 直接把所有的括号压入一个stack里面. 然后进行~~乱搞~~就行.

```cpp
#include <bits/stdc++.h>
#define siz 1000100
using namespace std;
int la, top, cnt, l, ansl, ansr, ans;
int sta[siz][2];
char a[siz];
bool vis[siz];
int main()
{

    scanf("%s", a);
    la = strlen(a);
    for (int i = 0; i < la; ++i)
        if ((sta[top][0] == '[' && a[i] == ']') || (sta[top][0] == '(' && a[i] == ')'))
            vis[sta[top--][1]] = vis[i] = 1;
        else
            sta[++top][0] = a[i], sta[top][1] = i;
    for (int i = 0; i < la; ++i)
        if (!vis[i])
            cnt = 0, l = i + 1;
        else {
            cnt++;
            if (cnt > ans)
                ansl = l, ansr = i, ans = cnt;
        }
    for (int i = ansl; i <= ansr; ++i)
        putchar(a[i]);
    return 0;
}
```

## Problem 7. [ZJOI2006物流运输](https://www.luogu.com.cn/problem/P1772)

- 7.1 如果没有有一些顶点不可用的限制: 直接最短路即可.
- 7.2 如果加上最短路? 对于每一天进行整理?
  - 可以想到处理出每一天的最短路
- 决策是什么?
  - 我们来构想一下，当我们到第n天的时候，有两种选择，一是继续原先的路，二是换一条新的路，当然，如果在这一天原先的路不能走了就必须要换一条路，然而换成什么路当然是用最短路求啦。
  - 所以 $f[i] = \min_{j=1}^i \{f[i],f[j]+(j-i+1)\times L \}$. L是更换之后的路线.

```cpp
#include <bits/stdc++.h>
#define soo (1e8)
#define ll long long
using namespace std;
int d, cnt, head[25], dis[25], vis[25], cant_vis[25];
ll co[105][105], dp[105];
int n, m, k, ee, cl[25][105];
struct Edge {
    int v, nx, s;
} e[10005];
void add(int x, int y, int z)
{
    e[++cnt].v = y;
    e[cnt].s = z;
    e[cnt].nx = head[x];
    head[x] = cnt;
}
void spfa()
{
    for (int i = 1; i <= m; i++)
        dis[i] = soo, vis[i] = 0;
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = e[i].nx) {
            int v = e[i].v;
            if (cant_vis[v])
                continue;
            if (dis[v] > dis[x] + e[i].s) {
                dis[v] = dis[x] + e[i].s;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
signed main()
{
    cin>>n>>m>>k>>ee;
    for (int i = 1; i <= ee; i++) {
        int x,y,z;
        cin>>x>>y>>z;
        add(x, y, z);
        add(y, x, z);
    }
    cin>>d;
    for (int i = 1; i <= d; i++) {
        int t,x,y;
        cin>>t>>x>>y;
        for (int j = x; j <= y; j++)
            cl[t][j] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            memset(cant_vis, 0, sizeof(cant_vis));
            for (int r = i; r <= j; r++)
                for (int l = 1; l <= m; l++)
                    if (cl[l][r])
                        cant_vis[l] = 1;
            spfa();
            co[i][j] = dis[m];
        }
    memset(dp, 0x7f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i] = (ll)co[1][i] * i;
        for (int j = i - 1; j >= 0; j--)
            dp[i] = min(dp[i], dp[j] + co[j + 1][i] * (i - j) + k);
    }
    printf("%lld", dp[n]);
    return 0;
}
```

## Problem 8. [守卫者的挑战](https://blog.csdn.net/liaojiqing/article/details/14390359)

> 题目描述:
>
> 打开了黑魔法师Vani的大门，队员们在迷宫般的路上漫无目的地搜寻着关押applepi的监狱的所在地。 
> 突然，眼前一道亮光闪过。“我，Nizem，是黑魔法圣殿的守卫者。如果你能通过我的挑战，那么你可以带 
> 走黑魔法圣殿的地图……”瞬间，队员们被传送到了一个擂台上，==最初身边有一个容量为K的包包==。 
> 　　擂台赛一共有N项挑战，各项挑战 ==依次==进行。第i项挑战有一个属性ai，如果ai>=0，表示这次挑战成功 
> 后可以再获得一个 ==容量为ai的包包==；如果ai=-1，则表示这次挑战成功后可以得到一个 ==大小为1 的地图残片==。 
> 地图残片必须装在包包里才能带出擂台，包包没有必要全部装满，但是队员们必须把 【获得的所有的】 
> 地图残片都带走（没有得到的不用考虑，只需要完成所有N项挑战后背包容量足够容纳地图残片即可）， 
> 才能拼出完整的地图。并且他们至少要挑战成功L次才能离开擂台。 
> 　　队员们一筹莫展之时，善良的守卫者Nizem帮忙预估出了每项挑战成功的概率，其中 ==第i项挑战成功的 
> 概率为pi%==。现在，请你帮忙预测一下，队员们能够带上他们获得的地图残片离开擂台的概率。 
>
> ***\*Input\****
>
> 　　第一行三个整数N,L,K。 
> 　　第二行N个实数，第i个实数pi表示第i项挑战成功的百分比。 
> 　　第三行N个整数，第i个整数ai表示第i项挑战的属性值. 
>
> ***\*Output\****
>
> 　　一个整数，表示所求概率，四舍五入保留6 位小数。 
>
> ***\*Sample Input\****
>
> ```
> Sample Input
> 样例输入1
> 3 1 0
> 10 20 30
> -1 -1 2
> 样例输入2
> 5 1 2
> 36 44 13 83 63
> -1 2 -1 2 1
> ```
>
> Sample Output
>
> ```
> Sample Output
> 样例输出1
> 0.300000
> 样例输出2
> 0.980387
> HINT
> 　　对于 100% 的数据，保证0<=K<=2000，0<=N<=200，-1<=ai<=1000，0<=L<=N，0<=pi<=100。
> ```

- 首先考虑一些变量:

  - 背包的容积.
  - 挑战胜利的次数.
  - 获得的地图碎片个数
  - 当前背包的容积.

- 考虑决策点: 当前决策 = p×下一个挑战成功的状态 + (1-p)×下一个挑战失败的状态.

- 考虑设计状态$f[i][j][k]$表示当前考虑了前$i$个物品,  获得了$j$次胜利, 背包容量为$k$. 注意: 这里的容量可正可负. $+k$的话表示背包还空着$k$, $-k$的话表示之后的过程中还需要容量为$k$的背包.

- 状态转移:
  $$
  f[i][j][k] = pf[i+1][j+1][k+W]+(1-p)f[i+1][j][k].
  $$
  其中$W$表示
  $$
  W=\begin{cases} &a_i&(a_i\neq-1) \\&-1 &(\text{else})\end{cases}
  $$

  ```cpp
  
  #include <bits/stdc++.h>
  #define N 215
  using namespace std;
  #define fo(i,x) for(int i = 1;i<=(x);i++)
  #define fo0(i,x) for(int i = 0;i<=(x);i++)
  #define fo2(i,x) for(int i = 2;i<=(x);i++)
  int n,l,k,a[N];
  //i场时，胜利数为k，容积数为j
  double p[N],f[N][N*2][N],ans;
  int main(){
      #ifdef FUCKCCF
      freopen("D:/Testcases/in.ac","r",stdin);
      freopen("D:/Testcases/out.ac","w",stdout);
      #else
      freopen("guard.in","r",stdin);
      freopen("guard.out","w",stdout);
      #endif
  	cin>>n>>l>>k;
  	fo(i,n) {cin>>p[i];p[i]=p[i]/100;}
  	fo(i,n) cin>>a[i];
  	f[0][n][0]=1;
  	fo(i,n)
  		fo0(k,3*n){
  			f[i][k][0]+=f[i-1][k][0]*(1-p[i]);
  			for(int j=1;j<=i;j++){
  				f[i][min(k+a[i],2*n)][j]+=f[i-1][k][j-1]*(p[i]);
  				f[i][k][j]+=f[i-1][k][j]*((1-p[i]));
  			}
  		}
   
  	for(int i=n-k;i<=3*n;i++)
  		for(int j=l;j<=n;j++){
  			ans+=f[n][i][j];
  		}
  	cout<<fixed<<setprecision(6)<<ans<<endl;
      return 0;
  }
  
  ```







# Backpack x Dynamic Programming

## Problem 9. [01背包问题](https://www.acwing.com/problem/content/2/)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int v[N];
int w[N];
int f[N];
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int n,m;cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = m;j>=v[i];j--){
            f[j] = max(f[j],f[j-v[i]]+w[i]);
        }
    }
    printf("%d",f[m]);
}
```

## Problem 10. [多重背包问题 I,II,III,IV](https://www.acwing.com/problem/content/4/)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[20002],q[20002],g[20002];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int v,w,s;
        cin>>v>>w>>s;
        memcpy(g,f,sizeof(f));
        for(int j=0;j<v;j++){
            int hh=0,tt=-1;
            for(int k=j;k<=m;k+=v){
                f[k]=g[k];
                if(hh<=tt && k-s*v>q[hh]){
                    hh++;
                }
                if(hh<=tt){
                    f[k]=max(f[k],g[q[hh]]+(k-q[hh])/v*w); 
                }
                while(hh<=tt && g[q[tt]]-(q[tt]-j)/v*w <= g[k]-(k-j)/v*w){
                    tt--;
                }
                q[++tt]=k;
            }
        }
    }
    cout<<f[m]<<endl;
}

```

## Problem 11. [粉刷匠](https://www.luogu.com.cn/problem/P4158)

*由于没有读题导致的错误. 错误原因:求的是有多少个正确的,而不是多少次*

- 状态的设计: 考虑当前粉刷到$f[i][j]$表示坐标为$(i,j)$的木板. 最少容纳的错误数量. 默认从上到下, 从左往右粉刷.
- 考虑第2维度, 也就是$f[1][i]$. 考虑$f[1][i] =\min(f[1][u]+same(u,i)),u\in[1,i)$ .
- 考虑行行之间的转移: $f[i+1][1] = \max f[i][x]$. 接下来行行转移即可.

------------------

- $dp[i][j][k][0/1/2]$表示第i行第j列一共粉刷了k次，0/1/2分别表示当前格子没有涂色/涂了错的颜色/涂了对的颜色，涂色正确的个数. 然后我们考虑逐格转移：

  ```cpp
  当j=1也就是出于每行的第一个位置时，我们要考虑上一行的最后一个位置， 即
  
  dp[i][j][k][0]=max(dp[i-1][m][k][1],max(dp[i-1][m][k][2],dp[i-1][m][k][0]));
  
  dp[i][j][k][1]=max(dp[i-1][m][k-1][2],max(dp[i-1][m][k-1][1],dp[i-1][m][k-1][0]));
  
  dp[i][j][k][2]=max(dp[i-1][m][k-1][2],max(dp[i-1][m][k-1][1],dp[i-1][m][k-1][0]))+1;
  其余位置要考虑这个格子颜色是否和前一个格子的颜色相等，如果相等，就有
  
  dp[i][j][k][2]=dp[i][j-1][k][2]+1;
  可以直接接上
  
  dp[i][j][k][1]=max(dp[i][j-1][k][1],dp[i][j-1][k-1][0]);
  前面涂错或不涂
  
  dp[i][j][k][0]=max(dp[i][j-1][k][0],dp[i][j-1][k][1]);
  前面涂错或不涂 如果不相等,
  
  dp[i][j][k][2]=max(dp[i][j-1][k-1][2],max(dp[i][j-1][k][1],dp[i][j-1][k-1][0]))+1;
  前面可能有三种情况
  
  dp[i][j][k][1]=max(dp[i][j-1][k][2],dp[i][j-1][k-1][0]);
  涂对或不涂       
  
  dp[i][j][k][0]=max(dp[i][j-1][k][0],dp[i][j-1][k][2]);
  涂对或不涂
  ```
  
  所以是
  
  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  #define N 105
  int n,m,t,dp[3][N][5998][3];
  #define fo(i,x) for(register int i = 1;i<=(x);i++)
  bool col[N][N];
  int main(){
      #ifdef XBZAKIOI
      freopen("D:/Testcases/in.ac","r",stdin);
      freopen("D:/Testcases/out.ac","w",stdout);
      #endif
      cin>>n>>m>>t;
      for(int i=1;i<=n;i++){
          char c[N];
          scanf("%s",c+1);
          for(int j=1;j<=m;j++)
              col[i][j]=c[j]-'0';
      }
      fo(i,n) fo(j,m) fo(k,t){
          if(j==1){
              dp[i&1][j][k][0]=max(dp[(i-1)&1][m][k][1],dp[(i-1)&1][m][k][0]);
              dp[i&1][j][k][0]=max(dp[i&1][j][k][0],dp[(i-1)&1][m][k][2]);
              dp[i&1][j][k][1]=max(dp[(i-1)&1][m][k-1][1],dp[(i-1)&1][m][k-1][0]);
              dp[i&1][j][k][1]=max(dp[i&1][j][k][1],dp[(i-1)&1][m][k-1][2]);
              dp[i&1][j][k][2]=max(dp[(i-1)&1][m][k-1][1],dp[(i-1)&1][m][k-1][0])+1;
              dp[i&1][j][k][2]=max(dp[i&1][j][k][2],dp[(i-1)&1][m][k-1][2]+1);
          }else{
              if(col[i][j] == col[i][j-1]){
                  dp[i&1][j][k][2]=dp[i&1][j-1][k][2]+1;
                  dp[i&1][j][k][1]=max(dp[i&1][j-1][k][1],dp[i&1][j-1][k-1][0]);
                  dp[i&1][j][k][0]=max(dp[i&1][j-1][k][0],dp[i&1][j-1][k][1]);
              }else{
                  dp[i&1][j][k][2]=max(dp[i&1][j-1][k][1],dp[i&1][j-1][k-1][0])+1;
                  dp[i&1][j][k][2]=max(dp[i&1][j-1][k-1][2]+1,dp[i&1][j][k][2]);
                  dp[i&1][j][k][1]=max(dp[i&1][j-1][k][2],dp[i&1][j-1][k-1][0]);
                  dp[i&1][j][k][0]=max(dp[i&1][j-1][k][0],dp[i&1][j-1][k][2]);
              }
          }
      }
      printf("%d",max(max(dp[n&1][m][t][0],dp[n&1][m][t][1]),dp[n&1][m][t][2]));
      return 0;
  }
  ```
  
  

## Problem 12.挑战

> **时间限制：** 1.0 秒
>
> **空间限制：** 512 MB
>
> ## 题目描述
>
> 企鹅豆豆在玩一款叫做 Slay the spire 的游戏。为了简化游戏，我们将游戏规则魔改如下：
>
> 主角一开始血量为 H，游戏里一共有 N 个房间，每个房间里有一些怪物，第 i 个房间需要受到 Di 的伤害才能解决所有怪物， 解决怪物后会获得对应的 Ci 的血量恢复，Ci 严格小于 Di，一个房间的怪物只能最多打一次。主角只有在血量为负数时才会死亡，即使血量刚好为 0 主角也能凭借强大的意志继续打怪。
>
> 现在给出每个房间的数据，豆豆想知道他最多能打完多少个房间？
>
> ## 输入格式
>
> 从标准输入读入数据。
>
> 输入第一行两个正整数 N,H，表示房间数目和主角的血量。
>
> 输入第二行有 N 个正整数 Di, 第 i 个数对应第 i 个房间。
>
> 输入第三行有 N 个非负整数 Ci, 第 i 个数对应第 i 个房间。
>
> ## 输出格式
>
> 输出到标准输出。
>
> 输出一行一个整数表示最多能打完的房间数目。
>
> ## 样例1输入
>
> ```
> 4 12
> 4 8 2 1
> 2 0 0 0
> ```
>
> ## 样例1输出
>
> ```
> 3
> ```
>
> ## 样例1解释
>
> 他可以选择 1,3,4 号房间。
>
> ## 样例2
>
> 见[下发文件](http://csp.ac/download.php?type=problem&id=305)。
>
> ## 子任务
>
> 对于 30% 的数据， 1≤N≤10。
>
> 对于另外 10% 的数据， Ci=0。
>
> 对于另外 10% 的数据， Di−Ci=1。
>
> 对于另外 30% 的数据， 1≤N≤1000。
>
> 对于 100% 的数据， 1≤N≤5×103。
>
> 对于所有数据，0≤Ci<Di≤5000,1≤Di,H≤5000

首先排序然后进行0-1背包.

## Problem 13. [三角形牧场](https://www.luogu.com.cn/problem/P1284)

首先读题:==所有的木板==.

考虑一条边一条边加进来的过程:定义$f[i]$表示到达第$i$个的情况 . 发现不太行, 因为依赖于情况. $f[i][j][k][l]$表示到达第$i$条边, 三边长为$(j,k,l)$的最大长度.

因为发现所有的三角形都要有, 所以我们可以减去一维: $f[i][j][k]$表示到达了第$i$个位置, $j,k$表示两条边. 因为三条边都要用, 所以用总长度减去前两条便就是第三条的数量.

- 注意: 三角形的面积公式: $S = \sqrt{p(p-a)(p-b)(p-c)}. $ 其中$p=\frac{a+b+c}{2}$.

进行状态转移: 
$$
f[i][j][k] \leftarrow \begin{cases} 
f[i-1][j-a[i]][k]\\
f[i-1][j][k-a[i]]\\
f[i-1][j][k]
\end{cases}
$$
对于所有可能的情况, 进行判断然后算出面积. 更新出最大值即可.

```cpp
#include <bits/stdc++.h>
#define ____debug_____ 1
#define deb if(____debug_____)
#define N 1005
#define fo(i,b,x) for(register int i =b;i<=x;++i)
using namespace std;
#define D double
#define ll long long
int n,a[N],S[N],f[N][N];D ans=-1;
D calc(D a,D b,D c){
	D p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
bool tran(D a, D b,D c){
	if(a+b>c && b+c>a && a+c>b) return 1;
	else return 0; 
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("D:\\Testcases\\in.ac","r",stdin);
	freopen("D:\\Testcases\\out.ac","w",stdout);
	#endif 
	cin>>n;
	fo(i,1,n) cin>>a[i];
	S[1] = a[1];
	fo(i,2,n) S[i] = S[i-1]+ a[i];
	f[0][0] = 1;
	fo(i,1,n){
		for(int j = S[n]/2;j>=0;j--){
			for(int k = S[n]/2;k>=0;k--){
				if(j-a[i] >= 0 && f[j-a[i]][k]) f[j][k] = 1;
				if(k-a[i] >= 0 && f[j][k-a[i]]) f[j][k] = 1;
			}
		}
	}
	int m = S[n];
	for(ll i=m/2;i>0;i--)
	for(ll j=m/2;j>0;j--){
    	if(!f[i][j]) continue;
       	if(!tran(i,j,m-i-j)) continue;
    	ans=max(ans,calc(i,j,m-i-j)); 
    }	
    if(ans == -1) {cout<<"-1" ; return 0;
	}
	cout<<(int)(ans*100);
	
	
}
```

## Problem 14. [垃圾陷阱](https://www.luogu.com.cn/problem/P1156)

- 可以考虑背包入手.

- ```cpp
  #include<cstdio>
  #include<cstring>
  #include<algorithm>
  using namespace std;
  const int N=100+5,INF=2147483647;
  struct strOfRubbish {
  	int time,food,height;
  } rubbish[N];
  inline bool cmp(strOfRubbish x,strOfRubbish y) {
  	return x.time<y.time;
  }
  int d,n,res=-INF,ans,dp[N][N];
  inline int readInt(void) {
  	int __temp;
  	scanf("%d",&__temp);
  	return __temp;
  }
  int main() {
  	d=readInt(),n=readInt();
  	dp[0][0]=10;
  	for(int i=1;i<=n;i++) {
  		rubbish[i].time=readInt();
  		rubbish[i].food=readInt();
  		rubbish[i].height=readInt();
  	}
  	sort(rubbish+1,rubbish+n+1,cmp);
  	for(int i=0;i<n;i++) {
  		for(int j=0;j<=d;j++) {
  			if(dp[i][j]>=rubbish[i+1].time) {
  				int sm=j+rubbish[i+1].height;
  				if(sm>=d) {
  					printf("%d\n",rubbish[i+1].time);
  					return 0;
  				}
  				dp[i+1][j]=max(dp[i+1][j],dp[i][j]+rubbish[i+1].food);
  				dp[i+1][sm]=max(dp[i+1][sm],dp[i][j]);
  			}
  		}
  	}
  	for(int i=1;i<=n;i++) {
  		res=max(res,dp[i][0]);
  	}
  	printf("%d",res);
  	return 0;
  }
  ```

## Problem 15. [飞扬的小鸟](https://www.luogu.com.cn/problem/P1941)

- 考虑现在在$(i,j)$的位置的点击数.
- $f[i][j] = min(f[i-1][j+b],f[i-1][j-b]+1) \text{ only when not blocked}$ 

```cpp
#include<bits/stdc++.h>
using namespace std;
struct Pipe {
    int pos, up, bottom;
} pipe[10010];
const int MAXN = (1 << 30);
int n, m, k, lift[10010], down[10010], f[10010][1010];
bool cmp(Pipe a, Pipe b) {
    return a.pos < b.pos;
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= n - 1; i++)
        scanf("%d%d", &lift[i], &down[i]);
    for (int i = 1; i <= k; i++)
        scanf("%d%d%d", &pipe[i].pos, &pipe[i].bottom, &pipe[i].up);
    sort(pipe + 1, pipe + k + 1, cmp);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            f[i][j] = MAXN;
    }
    for (int i = 1; i <= m; i++) f[0][i] = 0;
    int nump = 1;
    for (int i = 1; i <= n; i++) {
        int lower = 1, upper = m;
        if (pipe[nump].pos == i) {
            upper = pipe[nump].up - 1;
            lower = pipe[nump++].bottom + 1;
        }
        for (int j = 1; j <= upper; j++) {
            for (int k = j - lift[i - 1]; k <= m; k++) {
                if (k > j - lift[i - 1] && j < m) break; 
                if (k >= 1) f[i][j] = min(f[i][j], min(f[i - 1][k], f[i][k]) + 1);
            }
        }
        for (int j = lower; j <= upper; j++) {
            if (j + down[i - 1] <= m) { 
                f[i][j] = min(f[i][j], f[i - 1][j + down[i - 1]]);
            }
        }
        for (int j = 1; j <= lower - 1; j++) f[i][j] = MAXN; 
    }
    int minn = MAXN;
    bool flag = false;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (f[i][j] != MAXN) {flag = true;minn = min(minn, f[i][j]);
            }
        }
        if (flag) {
            if (i == n) {
                printf("1\n%d", minn);
                return 0;
            }
            else {
                for (int j = k; j >= 1; j--) {
                    if (i >= pipe[j].pos) {
                        printf("0\n%d", j);
                        return 0;
                    }
                }
            }
        }
    }
    printf("0\n0");
    return 0;

}
```

## Problem 16. [多米诺骨牌](https://www.luogu.com.cn/problem/P1282)

- 首先看到反转这个操作. 可以想到背包. 考虑对于每一个反转不反转. 反转的话就是$-k$. 不反转的话就是+k.
- 定义$f[i][j]$为进行到第$i$个, 当前数量为$j$的翻转数.

```cpp
#include <cstdio>
using namespace std;
int dp[10005][6005];
bool vs[1005][60005];
int w[1005];
int v[1005];
int min(int a,int b){
	return a<b ?  a: b;
}
int main(){

	int n,i,j,x,y,base=0,tot=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&x,&y);
		if(x>y){
			v[i]=2*(x-y);
			w[i]=1;
			tot+=x-y;
		}
		if(y>x) {
			v[i]=2*(y-x);
			w[i]=-1;
			tot+=y-x;
			base++;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=tot;j++){
			dp[i][j]=dp[i-1][j];
			vs[i][j]=vs[i-1][j];
			if(vs[i-1][j-v[i]]||j-v[i]==0){
				if(!vs[i][j]){
					dp[i][j]=dp[i-1][j-v[i]]+w[i];
					vs[i][j]=1;
				}
				else dp[i][j]=min(dp[i][j],dp[i-1][j-v[i]]+w[i]);
			}
		}
	}
	for(i=tot;i>=1;i--)	if(vs[n][i]) break;
	printf("%d",base+dp[n][i]);
} 
```

## Problem 17. [排兵布阵](https://www.luogu.com.cn/problem/P5322)

- 注意到对于之后的几场, 都要有相同的策略.
- 直观的考虑: $f[i][j]$表示当前道理第$i$个, 现在剩余兵力为$j$.
- 考虑到第$i$个按谁去打.

# Interval DP

## Problem 14. [关路灯 ](https://www.luogu.com.cn/problem/P1220)

- 观察区间特征: 因为经过一个路灯的时候, 关掉总比不关好.

- 找到状态转移:

  ```cpp
  f[i][j][0] = min ( f[i+1][j][0] + ( a[i+1] - a[i] ) * ( sum[i] + sum[n] - sum[j] ) , f[i+1][j][1] + ( a[j]-a[i] ) * ( sum[i]+sum[n]-sum[j]) );
  
  f[i][j][1] = min ( f[i][j-1][0] + ( a[j] - a[i] ) * ( sum[i-1] + sum[n] - sum[j-1] ) , f[i][j-1][1] + ( a[j]-a[j-1] ) * ( sum[i-1] + sum[n] - sum[j-1] ) );
  ```

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int f[N][N][2] , n , c;
int pos[N] , w[N] , sum[N];
int main () {
    cin>>n>>c;
    for(int i = 1 ; i <= n ; ++ i) scanf("%d %d" , pos + i , w + i) ,sum[i] = sum[i - 1] + w[i];
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = 1 ; j <= n ; ++ j) f[i][j][1] = f[i][j][0] = 1000000000; 
    f[c][c][0] = f[c][c][1] = 0;
    for(int len = 2 ; len <= n ; ++ len) {
        for(int i = 1 ; i <= n - len + 1 ; ++ i) {
            int j = i + len - 1;
            f[i][j][1] = min(f[i + 1][j][1] + (pos[i + 1] - pos[i]) * (sum[n] - sum[j] + sum[i]) , f[i + 1][j][0] + (pos[j] - pos[i]) * (sum[n] - sum[j] + sum[i]));
            f[i][j][0] = min(f[i][j - 1][0] + (pos[j] - pos[j - 1]) * (sum[i-1] + sum[n] - sum[j-1]) , f[i][j - 1][1] + (pos[j] - pos[i]) * (sum[i-1] + sum[n] - sum[j-1]));
        }
    }
    printf("%d" ,min(f[1][n][1] , f[1][n][0]));
    return 0;
} 
```

## Problem 15.[合唱队](https://www.luogu.com.cn/problem/P3205)

- 考虑区间的特征. 加入进来一个人的话就可以满足区间的扩展.

- 转移方程是:

  ```cpp
  if(a[i]<a[i+1])f[i][j][0]+=f[i+1][j][0];
  if(a[i]<a[j])f[i][j][0]+=f[i+1][j][1];
  if(a[j]>a[i])f[i][j][1]+=f[i][j-1][0];
  if(a[j]>a[j-1])f[i][j][1]+=f[i][j-1][1];
  ```

```cpp
#include <cstdio>
using namespace std;
int num[1001], dp[1001][1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
	    scanf("%d", num + i);
	    dp[i][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	    for (int j = 1; i + j - 1 <= n; j++){
	    	int k = i + j - 1;
	    	if (num[j] < num[j + 1])           dp[k][j] += dp[k][j + 1];
	    	if (num[j] < num[k] && j != k - 1) dp[k][j] += dp[j + 1][k];
	    	if (num[k] > num[k - 1])           dp[j][k] += dp[j][k - 1];
	    	if (num[k] > num[j] && j != k - 1) dp[j][k] += dp[k - 1][j];
	    	dp[j][k] %= 19650827, dp[k][j] %= 19650827;
		}
	printf("%d\n", (dp[1][n] + dp[n][1]) % 19650827);
	return 0;
}
```

