#include<cstdio>
#include<cstdlib>
using namespace std;
const int SIZE=200005;
int m,n,ta,tb,k,a[SIZE],b[SIZE],ans,p;
inline int max(int x,int y){
	if(x>y) return x;
	else return y;
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	if(k>=n||k>=m){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<=k;++i){
		while(a[i+1]+ta>b[p]&&p<=m) ++p;
		if(p+k-i>m){
			ans=-1;break;
		}
		ans=max(ans,b[p+k-i]+tb);
	}
	printf("%d\n",ans);
	return 0;
} 
