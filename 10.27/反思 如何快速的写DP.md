# 反思: 如何快速的写DP

一般来说, 我写dp的时候总是特别慢. 要么这里跳出锅了, 要么那里又出错了. 总而言之, 调DP总是容易写错了.

到底该怎么写才可以正确的写出DP方程式?  

## 方法1. 列出转移的方程式

我们知道, DP只是搜索+记忆化. 那么考虑在搜索时搞上记忆化, 是不是就行了?

> CF1433F.Zero Remainder Sum ( $k \to u$ )

- 设计状态$f[i][j][k][l]$. 当前在第i行第j个. 选了$k$个,余数是$l$.
- 转移
  - 对于每一个数: 如果选择, 那么就是$f[i][j][k+1][l+a_{i,j}\bmod u]=\max f[i][x][k][l]+a_{i,j},x\in{[0,j]}$.
  - 如果不做出选择, 那么$f[i][j][k][l] = \max f[i][x][k][l] ,x\in[0,j]$.
  - 就需要 $f[i+1][0][0][0] = \max f[i][x][y][z], x\in[0,m],y\in[0,\frac{m}{2}],z\in[0,k-1]$.

```c++
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

```cpp
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

```cpp
    int n,m,u;cin>>n>>m>>u; 
    fo(i,n) fo(j,m) cin>>a[i][j];
    fo(i,n+1) fo(j,n) fo0(k,n) fo0(l,n) f[i][j][k][l] = -998244353;
    f[1][1][0][0] = 0; 
    f[1][2][0][0] = 0;
    fo(i,n)fo(j,m)fo0(k,(m/2))fo0(l,u-1){
        // if(f[i][j][k][l] == -998244353) continue;
        fo(x,j){
            f[i][j][k][l] = max(f[i][j][k][l],f[i][x][k][l]);
            if(k<=(m/2)){
                if(k==0)fo(df,u-1) f[i][j][0][df] = 0;
                f[i][j][k][(l+a[i][x])%u] = max(f[i][j][k][(l+a[i][x])%u],f[i][x][k-1][l]+a[i][x]); 
            }
        }
        f[i+1][1][0][l] = max(f[i][j][k][l],f[i+1][1][0][l]);
        printf("f[%d][%d][%d][%d] = %d.\n",i,j,k,l,f[i][j][k][l]);
    }
    printf("%d\n",f[n+1][1][0][0]);
```

