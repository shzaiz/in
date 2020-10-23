#include<bits/stdc++.h>
using namespace std;
const int SIZE=300000;
int n, m, tot, h[SIZE], deep[SIZE], fa[SIZE][20], w[SIZE];      //w[i]��ʾi�����ֹ۲�Ա��ʱ��
struct edge
{
	int to, next;
}E[SIZE*2], e1[SIZE*2], e2[SIZE*2];                             //�߼�����e1��e2��������

void add(int x, int y)                                          //�ӱߺ���
{
	E[++tot].to=y;
	E[tot].next=h[x];
	h[x]=tot;
}

void dfs1(int x)                                                //dfs�Ĺ�������ɡ���������Ԥ����fa[][]����, ����deep[]����
{
	for(int i=1; (1<<i)<=deep[x]; i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];                           //x��2^i�����ھ���x��2^{i-1}�����ڵ�2^{i-1}������
	for(int i=h[x]; i; i=E[i].next)
	{
		int y=E[i].to;
		if(y==fa[x][0])	continue;                               //���y�Ǹ���㣬����
		fa[y][0]=x;
		deep[y]=deep[x]+1;
		dfs1(y);
	}
}

int get_lca(int x, int y)                                      //����x��y�������������
{
	if(x==y) return x;                                         //û����һ�У����� lca(x, x) ������ѯ��ʱ��ҵ�
	if(deep[x]<deep[y]) swap(x, y);                            //����x����ȴ���y�����
	int t=log(deep[x]-deep[y])/log(2);
	for(int i=t; i>=0; i--)                                    //x����������yͬ�������
	{
		if(deep[fa[x][i]]>=deep[y])
			x=fa[x][i];
		if(x==y)
			return x;
	}
	t=log(deep[x])/log(2);
	for(int i=t; i>=0; i--)                                    //x��yһ��������
	{
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i], y=fa[y][i];
	}
	return fa[x][0];
}

int main()                                                     //�Ȱ�������д��һ����
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
    ////////////////////////δ�����///////////////////////////
    /////////////////////////////////////////////////////////////
    
	return 0;
}
