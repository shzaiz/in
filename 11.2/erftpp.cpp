#include <bits/stdc++.h>
using namespace std;
#define N 55
int n,m,e,ans=0,match[50];
bool a[N][N], vis[N];
bool dfs(int x){
    for(int i =1;i<=m;i++){
        if(!vis[i] && a[x][i]){
            vis[i] = 1;
            if(!match[i] || dfs(match[i])){
                match[i] =x;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin >> n >> m >> e;
	for (int i = 1; i <= e; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		if (v <= m) a[u][v] = 1;
	}
	for (int i = 1; i <= n; i++){
		ans += dfs(i);
		memset(vis, 0, sizeof(vis));
	}
	cout << ans;
	return 0;
}