#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int ma[305][305];
int dis[305][305];
void floyd(int n){
	for(int k =1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
} 
int n,m,v,e,t1[10010],t2[10010];
double prob[10010];
int input(){
	cin>>n>>m>>v>>e;
	for(int i=1;i<=n;i++){
		cin>>t1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t2[i];
	}
	for(int i=1;i<=n;i++){
		cin>>prob[i];
	}
	memset(dis,0x7f,sizeof dis);
	for(int i=1;i<=v;i++) for(int j=1;j<=e;j++) if(i==j) dis[i][j] = 0;
	for(int i=1;i<=v;i++){
		int qq,qqq,qqqq;
		cin>>qq>>qqq>>qqqq;
		dis[qq][qqq] =min(dis[qq][qqq],qqqq); dis[qqq][qq] = qqqq;
		
	}
	floyd(v);
}
int main(){
	freopen("D:\\in.txt","r",stdin);
	input();
	double ans  =0.0;
	for(int i=1;i<n;i++){
		ans+= dis[t1[i]][t1[i+1]];
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
}
