#include <bits/stdc++.h>
using namespace std;
#define SIZE 300005
int n,m,tot,h[SIZE],deep[SIZE],fa[SIZE][20],w[SIZE];
struct Edge{
	int to,nxt;
}E[SIZE*2],e1[SIZE*2],e2[SIZE*2];
int tot1,tot2,h1[SIZE],h2[SIZE];
void add1(int x, int y){
	e1[++tot1].to=y;
	e1[tot1].nxt=h1[x];
	h1[x]=tot1;
}
void add(int x, int y)
{
	E[++tot].to=y;
	E[tot].nxt=h[x];
	h[x]=tot;
}
void add2(int x, int y){
	e2[++tot2].to=y;
	e2[tot2].nxt=h2[x];
	h2[x]=tot2;
}
void dfs1(int x)
{
	for(int i=1; (1<<i)<=deep[x]; i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=h[x]; i; i=E[i].nxt)
	{
		int y=E[i].to;
		if(y==fa[x][0])	continue;
		fa[y][0]=x;
		deep[y]=deep[x]+1;
		dfs1(y);
	}
}

int get_lca(int x, int y)
{
	if(x==y) return x;
	if(deep[x]<deep[y]) swap(x, y);
	int t=log(deep[x]-deep[y])/log(2);
	for(int i=t; i>=0; i--)
	{
		if(deep[fa[x][i]]>=deep[y])
			x=fa[x][i];
		if(x==y)
			return x;
	}
	t=log(deep[x])/log(2);
	for(int i=t; i>=0; i--)
	{
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i], y=fa[y][i];
	}
	return fa[x][0];
}
int b1[SIZE*2],b2[SIZE*2],js[SIZE],dist[SIZE],s[SIZE],t[SIZE],l[SIZE],ans[SIZE];
/*
e1,tot1,h1,add1��ʹ����ʽǰ���ǵķ����洢ÿ�������Ϊ�յ��Ӧ��·������
e2,tot2,h2,add2��ʹ����ʽǰ���ǵķ����洢ÿ�������ΪLCA��Ӧ��·������
b1,b2������Ͱ���ֱ��������н׶κ����н׶εĹ���ͳ��
js[SIZE]����ͳ����ÿ�������Ϊ����·������
dist[SIZE], s[SIZE], t[SIZE]����ͳ��m��·����Ӧ�ĳ��ȣ������յ���Ϣ
ans[SIZE]�洢�������Ĵ𰸣���ÿ�����۲�Ա����������
*/ 

void dfs2(int x){
	int t1 = b1[w[x]+deep[x]],t2 = b2[w[x]-deep[x]+SIZE];
	for(int i = h[x];i;i = E[i].nxt){
		int y = E[i].to;
		if(y==fa[x][0]) continue;
		dfs2(y);
	}
	b1[deep[x]]+=js[x];
	for(int i = h1[x];i;i = e1[i].nxt){
		int y = e1[i].to;
		b2[dist[y]-deep[t[y]]+SIZE]++;
	}
	ans [x] += b1[w[x]+deep[x]]-t1+b2[w[x]-deep[x]+SIZE]-t2;
	for(int i = h2[x];i;i = e2[i].nxt){
		int y = e2[i].to;
		b1[deep[s[y]]]--;
		b2[dist[y]-deep[t[y]]+SIZE]--;
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1; i<n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	deep[1]=1;
	fa[1][0]=1;
	dfs1(1);
	for(int i=1; i<=n; i++) scanf("%d", &w[i]);
	for(int i=1;i<=m;i++){
		cin>>s[i]>>t[i];
		int lca = get_lca(s[i],t[i]);
		dist[i] = deep[s[i]]+deep[t[i]]-2*deep[lca];
		js[s[i]]++;
		add1(t[i],i);
		add2(lca,i);
		if(deep[lca]+w[lca]==deep[s[i]]) ans[lca]--;
	}
	dfs2(1);
	for(int i=1; i<=n; i++) printf("%d ", ans[i]);
}
