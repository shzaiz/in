#include<bits/stdc++.h>
using namespace std;
const int SIZE=300000;
int n, m, tot, h[SIZE], deep[SIZE], fa[SIZE][20], w[SIZE];      //w[i]表示i结点出现观察员的时间
struct edge
{
	int to, next;
}E[SIZE*2], e1[SIZE*2], e2[SIZE*2];                             //边集数组e1，e2留待备用

void add(int x, int y)                                          //加边函数
{
	E[++tot].to=y;
	E[tot].next=h[x];
	h[x]=tot;
}

void dfs1(int x)                                                //dfs的过程中完成“建树”，预处理fa[][]数组, 计算deep[]数组
{
	for(int i=1; (1<<i)<=deep[x]; i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];                           //x的2^i代祖宗就是x的2^{i-1}代祖宗的2^{i-1}代祖宗
	for(int i=h[x]; i; i=E[i].next)
	{
		int y=E[i].to;
		if(y==fa[x][0])	continue;                               //如果y是父结点，跳过
		fa[y][0]=x;
		deep[y]=deep[x]+1;
		dfs1(y);
	}
}

int get_lca(int x, int y)                                      //计算x和y的最近公共祖先
{
	if(x==y) return x;                                         //没有这一行，遇到 lca(x, x) 这样的询问时会挂掉
	if(deep[x]<deep[y]) swap(x, y);                            //保持x的深度大于y的深度
	int t=log(deep[x]-deep[y])/log(2);
	for(int i=t; i>=0; i--)                                    //x向上跳到和y同样的深度
	{
		if(deep[fa[x][i]]>=deep[y])
			x=fa[x][i];
		if(x==y)
			return x;
	}
	t=log(deep[x])/log(2);
	for(int i=t; i>=0; i--)                                    //x和y一起向上跳
	{
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i], y=fa[y][i];
	}
	return fa[x][0];
}

int main()                                                     //先把主函数写上一部分
{
	freopen("D:\\in.txt","r",stdin); 
	int n; int m; int k;
	cin>>n>>m>>k;
	deep[1] = 1;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);add(y,x);
	}
	dfs1(1);
	
	
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		cout<<get_lca(x,y)<<endl;
	} 
    /////////////////////////////////////////////////////////////
    ////////////////////////未完待续///////////////////////////
    /////////////////////////////////////////////////////////////
    
	return 0;
}
