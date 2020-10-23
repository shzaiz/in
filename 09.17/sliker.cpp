#include <bits/stdc++.h>
#include <string.h>
#include <cstring>
#include <conio.h>
#define map mp
using namespace std;
char map[55][55];int vis[55][55],T[55][55];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int N,M; // N*M
#define t T
struct w{
	int x,y,t;
};
queue<w > Q;
void bfs(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(map[i][j]=='*') Q.push(w({i,j,0})),vis[i][j] = 1;
		}
	}
	while(!Q.empty()){
		w s = Q.front();Q.pop();vis[s.x][s.y] = 0;t[s.x][s.y] = s.t;
		for(int i=0;i<4;i++){
			if(s.x+dx[i]>N|| s.x+dx[i]<=0) continue;
			if(s.y+dy[i]>M||s.y+dy[i]<=0) continue;
			if(vis[s.x+dx[i]][s.y+dy[i]]) continue;
			if(t[s.x+dx[i]][s.y+dy[i]]<s.t+1) continue;
			if(map[s.x+dx[i]][s.y+dy[i]]=='X'||map[s.x+dx[i]][s.y+dy[i]]=='D') continue;
			Q.push(w({s.x+dx[i],s.y+dy[i],s.t+1}));
			vis[s.x+dx[i]][s.y+dy[i]] = 1;
		}
	}
}
#undef t
#define Q Q2
#define vis vis2
#define t t2
struct p{
	int x,y,t;
};
queue< p > Q;
int vis[55][55],t[55][55];
void bfs2(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(map[i][j]=='S') Q.push(p({i,j,0})),vis[i][j] = 1;
		}
	}
	while(!Q.empty()){
		p s = Q.front();Q.pop();vis[s.x][s.y] = 0;t[s.x][s.y] = s.t;
	//	printf("{%d,%d,%d}\n",s.x,s.y,s.t); 
		for(int i=0;i<4;i++){
		//	cout<<"i"<<i<<endl;
		//	cout<<1<<endl;
			if(s.x+dx[i]>N|| s.x+dx[i]<=0) continue;
		//	cout<<2<<endl;
			if(s.y+dy[i]>M||s.y+dy[i]<=0) continue;
		//	cout<<3<<endl;
			if(vis[s.x+dx[i]][s.y+dy[i]]) continue;
		//	cout<<4<<endl;
			if(t[s.x+dx[i]][s.y+dy[i]]<s.t+1) continue;
		//	cout<<5<<endl;
			if(map[s.x+dx[i]][s.y+dy[i]]=='X') continue;
		//	cout<<6<<"  ";
		//	cout<<T[s.x+dx[i]][s.y+dy[i]]<<" "<<s.t+1<<endl;
			if(s.t+1>=T[s.x+dx[i]][s.y+dy[i]]) continue;
		//	cout<<7<<endl;
			Q.push(p({s.x+dx[i],s.y+dy[i],s.t+1}));
			vis[s.x+dx[i]][s.y+dy[i]] = 1;
		}
	}
}
#undef t
#undef vis
#undef Q
#undef T
int main(){
	freopen("sliker.in","r",stdin);
	freopen("sliker.out","w",stdout);
	for(int i=1;i<=50;i++) for(int j=0;j<=50;j++) T[i][j] = t2[i][j] = 269488144;
//	memset(T,16,sizeof T);memset(t2,16,sizeof t2);
	
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		string s;
		cin>>s;
		for(int j=1;j<=M;j++){
			map[i][j] = s[j-1];
		}
	}
	bfs();
	bfs2();
//	cout<<"\n";
//	for(int i=1;i<=N;i++){
//		for(int j = 1;j<=M;j++){
//			cout<<map[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
//	for(int i=1;i<=N;i++){
//		for(int j = 1;j<=M;j++){
//			cout<<T[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
//	for(int i=1;i<=N;i++){
//		for(int j = 1;j<=M;j++){
//			cout<<t2[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=N;i++){
		for(int j = 1;j<=M;j++){
			if(map[i][j]=='D'){
				if(t2[i][j]!=269488144)cout<<t2[i][j];
				else cout<<"Orz hzwer!!!";
			}
		}
	}
}
