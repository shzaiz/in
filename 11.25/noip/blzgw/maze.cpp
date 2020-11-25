#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 1;i<=n;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define N 1001
#define x1 xxxxxxx
#define y1 yyyyyyy
#define x2 cxxxcxc
#define y2 dsfhosg
#define debuggg 0
#define deb if(debuggg)
char mm[N][N];
int w,h,dis[N][N],x1=0,y1=0,x2=0,y2=0,cnt=0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct Node{
	int x,y,step;
};
int maxx = -1;
queue<Node > Q;
void bfs(){
	while(!Q.empty()){
		Node u = Q.front(); Q.pop();
		int cx = u.x,cy = u.y, cstep = u.step;
		for(int i = 0;i<4;i++){
			int xx = cx+dx[i],yy = cy+dy[i];
			int ss = cstep+1;
			if(xx<=0 || xx>2*w+1 || yy<=0 || yy>=2*w+1 || mm[xx][yy]!=' ') continue;
			if(ss>= dis[xx][yy] ) continue;
			dis[xx][yy] = ss;
			Q.push((Node){xx,yy,ss});
			deb printf("push %d %d %d\n",xx,yy,ss);
			maxx = max(ss,maxx);
		}
	}
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	fo(i,N-1) fo(j,N-1) dis[i][j] = 1e9;
	scanf("%d%d",&w,&h); getchar();
	int m = 2*w+1,n = 2*h+1;
	fo(i,2*h+1) gets(mm[i]+1);
	fo(i,m)
        if(mm[1][i]==' '){
        	Q.push((Node){1,i,0});dis[1][i]=1;
        	deb printf("1,%d\n",i);
		}
    fo(i,m)
        if(mm[n][i]==' '){
        	Q.push((Node){n,i,0});dis[n][i]=1;
        	deb printf("%d,%d\n",n,i);
		}
    fo(i,n)
        if(mm[i][1]==' '){
        	Q.push((Node){i,1,0});dis[i][1]=1;
        	deb printf("%d,1\n",i);
		}
    fo(i,n)
        if(mm[i][m]==' '){
        	Q.push((Node){i,m,0});dis[i][m]=1;
        	deb printf("%d,%d\n",i,m);
		}
	bfs();
	cout<<(maxx+1)/2;
	
} 

