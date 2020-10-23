#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x1,y1,x2,y2,sum;
};
int f[55][55][55][55];
int ma[55][55];
int dx[5] = {-1,0,0,1};
int dy[5] = {0,-1,1,0};

int n,m,q;
int ex=3,ey=2,sx=1,sy=2,tx=2,ty=2;
int ans = 0x7f7f7f7f;
void bfs(){
	queue<Node > Q;
	Q.push((Node){ex,ey,sx,sy,0});
	while(!Q.empty()){
		Node now = Q.front();
		int x1 = now.x1,x2=now.x2,y1 = now.y1,y2 = now.y2,sum = now.sum;
		Q.pop();
		if(sum>ans) continue;
		if(f[x1][y1][x2][y2]<sum) continue;
		f[x1][y1][x2][y2] = sum;
		if(x2==tx && y2==ty) {
			ans = min(ans,sum);
			continue;
		}
		for(int i=0;i<4;i++){
			int cur_x1 = x1+dx[i];
			int cur_y1 = y1+dy[i];
			if(!ma[cur_x1][cur_y1] || !ma[x2][y2]) continue;
			if(cur_x1<1 ||cur_x1>n ||x2<1||x2>n) continue;
			if(cur_y1<1 ||cur_y1>m ||y2<1||y2>m) continue;
			if(cur_x1 == x2 && cur_y1==y2){
				Q.push((Node){x2,y2,x1,y1,sum+1});
				continue;
			}
			Q.push((Node){cur_x1,cur_y1,x2,y2,sum+1});
			
		}
	}
}

void ip(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ma[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		memset(f,0x7f7f7f7f,sizeof f);
		ans = 0x7f7f7f7f;
		cin>>ex>>ey>>sx>>sy>>tx>>ty;
		f[ex][ey][sx][sy]=0;
		bfs();
		if(ans==0x7f7f7f7f) ans=-1;
		printf("%d\n",ans);
	}
}

int main(){
	freopen("D:\\in.txt","r",stdin);
	memset(f,0x7f7f7f7f,sizeof f);
	ip();
	
}
