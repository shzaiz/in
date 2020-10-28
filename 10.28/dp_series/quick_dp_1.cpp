// CF 1433F.
// http://codeforces.com/problemset/problem/1433/F

#include <bits/stdc++.h>
using namespace std;
#define N 75
int a[N][N];
int f[N][N][N][N];
int dp[N][N][N][N];
#define INF 998244353
#define fo(i,n) for(int i =1;i<=(int)n;i++) 
#define fo0(i,n)for(int i =0;i<=(int)n;i++) 
#define mmax(x,y) (x) = max((x),(y))
int n,m,u,k;

int dfs(int x,int y,int chose, int remain ){
    // printf("%d %d %d %d\n",x,y,chose,remain);
    // f[x][y][chose][remain] = 0;
    if(x==n+1) return remain == 0? -999: 0;
    if(chose == m/2 || y==m+1) return  dfs(x+1,1,0,remain);
    
    if(f[x][y][chose][remain]!=-1)  return f[x][y][chose][remain];
    return f[x][y][chose][remain] = max(dfs(x,y+1,chose, remain),a[x][y]+dfs(x,y+1,chose+1, (remain+a[x][y])%u));
}

int solve(int i,int j,int mod,int taken) {
	if(dp[i][j][mod][taken]!=-1)return dp[i][j][mod][taken];
	if(i==n)
		return mod?-999999:0;
	if(j==m || taken==m/2)
		return solve(i+1,0,mod,0);
	return dp[i][j][mod][taken]=max(solve(i,j+1,mod,taken),a[i][j]+solve(i,j+1,(mod+a[i][j])%k,taken+1));
}

int main() {
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
	cin>>n>>m>>u;
	memset(dp,-1,sizeof(dp));
	memset(f,-1,sizeof(f));
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			cin>>a[i][j];
	cout<<dfs(1,1,0,0)<<endl;
	return 0;
}
