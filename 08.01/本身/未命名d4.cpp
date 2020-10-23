#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,maxm=500005,inf=0x3f3f3f3f;
double e[1005][1005];
int wz[1005][11];
int n,tf;
double dist(int a,int b,int c,int d){
	return sqrt((a-b)*(a-b)*1.0+1.0*(c-d)*(c-d));
}
double dist1(int a,int b,int c,int d){
	return (a-b)*(a-b)*1.0+1.0*(c-d)*(c-d);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		scanf("%d%d%d%d",&n,&tf,&a,&b);
		for(int i=1;i<=4*n;i++)
		  for(int j=1;j<=4*n;j++)
		    e[i][j]=inf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=6;j++)
			  scanf("%d",wz[i]+j);
			for(int j=1;j<=5;j+=2){
				wz[i][7]+=wz[i][j];
				wz[i][8]+=wz[i][j+1];
			}
			scanf("%d",wz[i]+9);
			double tp[3];
			int tp2=inf,tp3;
			tp[0]=dist1(wz[i][4],wz[i][6],wz[i][3],wz[i][5]);
			tp[1]=dist1(wz[i][2],wz[i][6],wz[i][1],wz[i][5]);
			tp[2]=dist1(wz[i][2],wz[i][4],wz[i][1],wz[i][3]);
			if(tp[0]+tp[1]==tp[2]){
				wz[i][7]-=2*wz[i][5];wz[i][8]-=2*wz[i][6];
			}
			else if(tp[1]+tp[2]==tp[0]){
				wz[i][7]-=2*wz[i][1];wz[i][8]-=2*wz[i][2];
			}
			else if(tp[0]+tp[2]==tp[1]){
				wz[i][7]-=2*wz[i][3];wz[i][8]-=2*wz[i][4];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=4;j++)
			  for(int k=j;k<=4;k++){
					int u=(i-1)*4+j,v=(i-1)*4+k;
					double dis=dist(wz[i][j*2-1],wz[i][k*2-1],wz[i][j*2],wz[i][k*2]);
					e[u][v]=e[v][u]=dis*wz[i][9];
				}
		}
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++)
		    if(i!=j){
		  	for(int k=1;k<=4;k++)
		  	  for(int l=1;l<=4;l++){
		  	    	int u=(i-1)*4+k,v=(j-1)*4+l;
					double dis=dist(wz[i][k*2-1],wz[j][l*2-1],wz[i][k*2],wz[j][l*2]);
					e[u][v]=dis*tf;
				  }
		  }
		for(int k=1;k<=n*4;k++)
		  for(int i=1;i<=n*k;i++)
		    for(int j=1;j<=n*4;j++)
		      if(e[i][j]>e[i][k]+e[k][j])
		          e[i][j]=e[i][k]+e[k][j];
		double ans=inf;
		for(int i=(a-1)*4+1;i<=a*4;i++)
		  for(int j=(b-1)*4+1;j<=b*4;j++)
		    ans=min(ans,e[i][j]);
		printf("%.1lf",ans);
	}
	return 0;
}
