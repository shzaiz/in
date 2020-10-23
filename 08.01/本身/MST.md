[题目地址](https://www.luogu.com.cn/problem/P1991)



题目可以使用最小生成树解决

# Kru 算法

1.**算法描述**：Kruskal算法是通过并查集，按照边的权重顺序（从小到大）将边加入生成树中，但是若加入该边会与生成树形成环则不加入该边,选其次。直到树中含有n - 1条边为止。

2.**例题示例**：


FJ 已经给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。为了用最小的消费，他想铺设最短的光纤去连接所有的农场。

你将得到一份各农场之间连接费用的列表，你必须找出能连接所有农场并所用光纤最短的方案。每两个农场间的距离不会超过 $$10^5$$

复杂度：$O(n\log n)$





```c++
#include <iostream>
using namespace std;
int n,m,v,k,ans,fa[1000001];
struct Node{
        int x,y,z; // z表示x连y的权值 
}stu[10001];
int find(int x){
    if(x!=fa[x]){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
int unit(int x,int y){
    int r1 = find(x);
    int r2 = find(y);
    fa[r1] = r2;
}
bool cmp(Node a,Node b){
    return a.z<b.z;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        fa[i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>v;
            if(j>i){
                m++;
                stu[m].x = i;
                stu[m].y = j;
                stu[m].z = v;
            }
        }
    }
    sort(stu+1,stu+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(find(stu[i].x) != find(stu[i].y)){
            ans+= stu[i].z;
            unit(stu[i].x,stu[i].y);
            k++;
            if(k == n-1){
                cout<<ans;
                return 0;
            }
        }
    }
}
```



# Prim算法

```c++
#include <bits/stdc++.h>//万能头 
#define INF 0x3f3f3f3f//巨大无比的一个数 
using namespace std;
int n, q[1001][1001], minn[100001], ans;//minn表示不在最小生成树中的点与在最小生成树中的点相连的最小边权 
bool f[100001];//不在最小生成树中的点f等于false，在就等于true 
int main()
{
    memset(minn, INF, sizeof(minn));//初始化 
    minn[1] = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &q[i][j]);//输入邻接矩阵 
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int k = 0;
        for(int j = 1; j <= n; j++)
        {
            if(!f[j] && minn[j] < minn[k])//寻找权值最短的边（且不能是已经在最小生成树中的点） 
            {
                k = j;
            }
        }
        f[k] = true;//把它加入最小生成树 
        for(int j = 1; j <= n; j++)
        {
            if(!f[j] && q[k][j] < minn[j])//利用新点改变其他不在最小生成树中的点的边的权值 
            {
                minn[j] = q[k][j];
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        ans += minn[i];//把所有在最小生成树中的点的权值加起来 
    }
    printf("%d", ans);
    return 0;
} 
```