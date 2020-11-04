#include <bits/stdc++.h>
using namespace std;
#define fo(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(debug)
#define fil if(using_file_is_okay)
#define nline cout<<"\n"<<endl;
const bool using_file_is_okay = 1;
int debug = 0;
int p[105][105],f[105][105];
int s,n,m;
int main(){
	fil freopen("D:\\Testcases\\in.ac","r",stdin);
	fil freopen("D:\\Testcases\\out.ac","w",stdout);
	cin>>s>>n>>m;
 	fo(i,1,s)fo(j,1,n) cin>>p[j][i];
 	fo(i,1,s)fo(j,1,n) p[j][i] = p[j][i]*2+1;
 	fo(i,1,n) sort(p[i]+1,p[i]+1+s);
 	fo(i,1,s)fo(j,1,n) p[j][i] += p[j][i-1];
 	deb fo(i,1,n)fo(j,1,s) cout<<p[i][j]<<(j==s?"\n":" ");
	fo(i,1,n)re(j,m,0)fo(k,0,s){
		if(j+p[i][k]<=m) {
			f[i][j] = max(f[i][j],f[i-1][j+p[i][k]]+i*k);
		}
	}
	deb nline
	deb fo(i,1,n)fo(j,1,m) cout<<f[i][j]<<(j==m?"\n":" ");
	int ans = -1;
	fo(j,0,s) ans = max(ans, f[n][j]);
	cout<<ans;
	return 0;
}

