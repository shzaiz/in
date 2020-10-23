#include<bits/stdc++.h>
using namespace std;
long long cnt;
struct Edge{
	int next,to,nxt;
}e[200001];
int head[50001],l[50001],dis[50001]; 
int n,m,a,b,c,maxx;
void adde(int x,int y,int z){cnt++;e[cnt].to=y;e[cnt].nxt=c;e[cnt].next=head[x];head[x]=cnt;}
queue<int>q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		adde(a,b,c);
	}
	for(int i=1;i<=n;i++){
		memset(l,0,sizeof(l));
		memset(dis,0x3f,sizeof(dis));
		q.push(i);
		l[i]=1;
		while(!q.empty()){
			int r=q.front();
			q.pop();
			for(int j=head[r];j;j=e[j].next){
				int t=e[j].to;
				if(l[t]==0){q.push(t);l[t]=1;}
				dis[t]=min(dis[t],e[j].nxt);
			}
		}
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(l[j]==0){
				cout<<"-1";
				return 0;
			}
			maxx=max(maxx,dis[j]);
		}
	}
	cout<<maxx;
}