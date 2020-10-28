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

