#include <bits/stdc++.h>
using namespace std;
int conn[50][50],ma[50][50];
int n = 10;
int cnt = 0;
struct Edge{
	int frm,to;
}e[10010];
void adde(int u,int v){
	e[++cnt].frm = u;
	e[cnt].to = v;
	ma[u][v] = ma[v][u] = 1;
}
struct ask{
	int x,y;
}a[10010];
int cntb = 0;
void adda(int u,int v){
	a[++cntb].x = u;
	a[cntb].y = v;
} 
int main(){
	freopen("destiny.in","r",stdin);
	freopen("destiny.out","w",stdout);
	int ans=0;
	memset(ma,-1,sizeof ma);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		adde(x,y);
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		adda(x,y);
	}
	for(int i=0;i<(1<<(n-1));i++){
		for(int j=0;j<(n-1);j++){
			
			int p = (i>>j)&(1);
			cout<<p<<" " ;
			if((i>>j)&1){
				for(int k=0;k<n;k++){
					int let = ma[e[j].frm][k];
					if(let!=-1){
						conn[e[j].frm][k] = 1;
					}
				}
			}
			for(int i=1;i<=n;i++){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
