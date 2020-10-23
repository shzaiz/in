#include<iostream>
#include<cstdio>
#define next nxt
using namespace std;
int n,m,k;
int hed[20002],next[20002],to[20002],tot;
int dis[10002][10002];
short q[50000001];
int head=1,tail=1;
void add(int x,int y) {
	to[++tot]=y;next[tot]=hed[x];hed[x]=tot;
	to[++tot]=x;next[tot]=hed[y];hed[y]=tot;
}
void bfs(int i){
	 int x;
	q[1]=i;
	head=1;
	tail=1;
	while(head<=tail) {
		x=q[head];
		head++;
		for(int j=hed[x]; j; j=next[j]) {
			if(!dis[i][to[j]]) {
				dis[i][to[j]]=dis[i][x]+1;
				q[++tail]=to[j];
			}
		}
	}
}
int main() {
	cin>>n>>m>>k;
	 int x,y;
	for( int i=1; i<=m; i++) {
		cin>>x>>y;
		add(x,y+n);
		add(y,x+n);
	}
	for( int i=1;i<=n;i++)
	   bfs(i);
	 int sx,sy,d;
	for( int i=1; i<=k; i++) {
		cin>>sx>>sy>>d;
		if(d%2==1) if(dis[sx][sy+n]<=d&&dis[sx][sy+n]) {puts("TAK"); continue ;}
		if(d%2==0) if(dis[sx][sy]<=d&&dis[sx][sy]) {puts("TAK"); continue ;}
		puts("NIE");
	}
	return 0; 
}
 
