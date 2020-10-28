# 反思: 如何快速的写DP

一般来说, 我写dp的时候总是特别慢. 要么这里跳出锅了, 要么那里又出错了. 总而言之, 调DP总是容易写错了.

到底该怎么写才可以正确的写出DP方程式?  

## 方法1. 状态设计比较简单, 转移复杂的问题

我们知道, DP只是搜索+记忆化. 那么考虑在搜索时搞上记忆化, 是不是就行了?

> CF1433F.Zero Remainder Sum (  )

- 设计状态. 当前在第i行第j个. 选了个,余数是.
- 转移
  - 对于每一个数: 如果选择, 那么就是.
  - 如果不做出选择, 那么.
  - 就需要 .

```
// assuming n*m
for i = 1 to n
    for j = 1 to m
        for k = 1 to m/2
            for l = 1 to u-1
                f[i+1][0][0] max= f[i][j][k][l]
                for x = 1 to j
                    if(k+1 <= m/2) f[i][j][k+1] max= f[i][x][k][l] + a[i][j]
                    f[i][j][k][l] max= f[i][x][k][l];

```

然后你兴致勃勃的写了代码, 结果会发生这样的事情:

```
#include <bits/stdc++.h>
using namespace std;
#define N 75
int a[N][N];
int f[N][N][N][N];
#define fo(i,n) for(int i =1;i<=(int)n;i++) 
#define fo0(i,n)for(int i =0;i<=(int)n;i++) 
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int n,m,u;cin>>n>>m>>u; 
    fo(i,n) fo(j,n) cin>>a[i][j];
    fo(i,n+1) fo(j,n) fo(k,n) fo(l,n) f[i][j][k][l] = -998244353;
    fo(i,n+1)fo(j,m)fo(k,(m/2)+1)fo(l,u-1){
        fo(x,j){
            if(k+1<=(m/2)){
                f[i][j][k+1][(l+a[i][j])%u] = f[i][x][k][l]+a[i][j]; 
            }
            f[i][j][k][l] = max(f[i][j][k][l],f[i][x][k][l]);
        }
        f[i+1][0][0][l] = max(f[i][j][k][l],f[i+1][0][0][l]);
    }
    printf("%d\n",f[n+1][0][0][0]);
}
```

样例都没有过.

再稍微改一改:

```
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int n,m,u;cin>>n>>m>>u; 
    fo(i,n) fo(j,m) cin>>a[i][j];
    fo(i,n+1) fo(j,n) fo0(k,n) fo0(l,n) f[i][j][k][l] = -998244353;
    f[1][1][0][0] = 0;
    fo(i,n)fo(j,m)fo0(k,(m/2))fo0(l,u-1){
        fo(x,j){
            // 这一个版本的问题错就错在:前面的可能重复选取.
            if(k<=(m/2)){
                mmax(f[i][j][k][l], f[i][x][k-1][(l-a[i][x]+500*u)%u]+a[i][x]);
            }
            mmax(f[i][j][k][l],f[i][x][k][l]);
        }
        mmax(f[i+1][1][0][l],f[i][j][k][l]);
    }
    printf("%d\n",f[n+1][1][0][0]);
}

```

考虑直接用搜索去模拟:

```
int solve(int i,int j,int mod,int taken) {
    if(dp[i][j][mod][taken]!=-1)return dp[i][j][mod][taken];
    if(i==n)
        return mod?-999999:0;
    if(j==m || taken==m/2)
        return solve(i+1,0,mod,0);
    return dp[i][j][mod][taken]=max(solve(i,j+1,mod,taken),a[i][j]+solve(i,j+1,(mod+a[i][j])%k,taken+1));
}
```