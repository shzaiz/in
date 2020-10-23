#include<bits/stdc++.h>
using namespace std;
const int N=55,M=9,O=0x7fffffff;
int f[M][N][N];
int s[N][N];
int n,k,ans=O;
struct node{
	int x,y;
}point[N];
inline void dp(){
	for(register int i=1;i<=n;i++){
		int min_x=point[i].x,max_x=point[i].x,min_y=point[i].y,max_y=point[i].y;
		for(register int j=i+1;j<=n;j++){
			min_x=min(min_x,point[j].x),max_x=max(max_x,point[j].x);
			min_y=min(min_y,point[j].y),max_y=max(max_y,point[j].y);
			f[1][i][j]=s[i][j]=abs(max_x-min_x)*abs(max_y-min_y);
		}
	}
	for(register int i=2;i<=k;i++)
		for(register int j=1;j<=n;j++)
			for(register int l=j+1;l<=n;l++){
				f[i][j][l]=O;
				for(register int m=j;m<l;m++)
					f[i][j][l]=min(f[i][j][l],f[i-1][j][m]+s[m+1][l]);
			}
	ans=min(ans,f[k][1][n]);
}
bool cmp_x(node a,node b){
	if(a.x^b.x)
		return a.x<b.x;
	return a.y<b.y;
}
bool cmp_y(node a,node b){
	if(a.y^b.y)
		return a.y<b.y;
	return a.x<b.x;
}
inline void work(bool step){
	if(step)
		sort(point+1,point+1+n,cmp_x);
	else sort(point+1,point+1+n,cmp_y);
	dp();
}
void init(){
	cin>>n>>k;
	for(register int i=1;i<=n;i++){
		cin>>(point[i].x);cin>>(point[i].y);
	}
	
}
int main(){
	init();
	work(0),work(1);
	printf("%d\n",ans);
	return 0;
}
