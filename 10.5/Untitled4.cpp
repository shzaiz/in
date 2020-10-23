#include <bits/stdc++.h>
using namespace std;
#define MAXN 500010
int fa[MAXN];
int vis[MAXN];
int sta[MAXN];int tp= 0;
int g[1005][1005];
//inline void init(int n){
//    for (int i = 1; i <= n; ++i)
//        fa[i] = i;
//} 
//int find(int x){
//    return x == fa[x] ? x : (fa[x] = find(fa[x]));
//}
//inline void merge(int i, int j){
//    fa[find(i)] = find(j);
//}
int flag = 0;
int main(){
	int n,m,q;
	cin>>n>>m>>q;
//	init(n);
	for(int i = 1;i<=m;i++){
		int x,y;cin>>x>>y;
//		merge(x,y);
		g[x][y] = g[y][x] = 1;
	}
	for(int i = 1;i<=q;i++){
		memset(sta,0,sizeof sta);memset(vis,0,sizeof vis);tp=0;flag=0;
		int ti;cin>>ti;
		for(int i =1;i<=ti;i++){
			
			int lx,rx;cin>>lx>>rx;
			for(int i = lx;i<=rx;i++){
				if(!vis[i]){
					sta[++tp] = i;
					vis[i] = 1;
				}
			}
			
		}
//		for(int i =1;i<=tp;i++){
//			printf("%d ",sta[i]);
//		}
//		printf("\n");
		for(int i =1;i<tp;i++){
			for(int j = i;j<=tp;j++){
				if(g[sta[i]][sta[j]]==1) {
					flag=1;
					break;
				}
			}
		}
		if(flag == 0){
			printf("SAFE\n");
		}else if(flag==1){
			printf("GG\n");
		}
	}
	return 0; 
}
