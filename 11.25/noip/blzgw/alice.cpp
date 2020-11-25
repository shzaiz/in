#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i = 1;i<=n;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define N 100001
#define x1 xxxxxxx
#define y1 yyyyyyy
#define x2 cxxxcxc
#define y2 dsfhosg
#define debuggg 0
#define deb if(debuggg)
using namespace std;
int n,m,a[50][50];
int ans,ct,s[50],as[50];
void dfs(int x){
	if(ct>=ans) return ;
	int i,num;
	if(x==0){
		if(ct<ans){
			ans=ct;
		    for(i=1;i<=n;i++) as[i]=s[i];
		   }
	    return ;
	   }
	if(a[x][x]){
		num=a[x][n+1];
	    for(i=x+1;i<=n;i++)if(a[x][i]) num^=s[i];
	    s[x]=num;
	    if(num==1) ct++;
	    dfs(x-1);
	    if(num==1) ct--;
	   }
	else{
		s[x]=0; dfs(x-1);
	    s[x]=1; ct++; dfs(x-1); ct--;
	   }
}
int main(){
	freopen("alice.in","r",stdin);
	freopen("alice.out","w",stdout);
	scanf("%d%d",&n,&m);
	#define i diiiiiiiiiiii
	#define x jjjdsfjjjjjjjjj
	#define y dsfdsfsdfdsa
	int i,x,y;
	for(i=1;i<=n;i++)
	   {scanf("%d",&x); a[i][i]=1; a[i][n+1]=x^1;}
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
	    a[x][y]=a[y][x]=1;
	}
	#undef i
	#undef x
	#undef y
	#define i iiiiiiiiiiii
	#define j jjjjjjjjjjjj
	#define k kkkkkkkkkk
	int i,j,k;
	for(i=1;i<=n;i++){
		j=i;
	    while(j<=n&&a[j][i]==0) j++;
	    if(j>n) continue;
	    if(j!=i){
			for(k=1;k<=n+1;k++)
		       swap(a[i][k],a[j][k]);
		   }
		for(j=1;j<=n;j++){
			if(a[j][i]==1&&i!=j)
		      for(k=1;k<=n+1;k++) a[j][k]^=a[i][k];
		  }
	   }
	   #undef i
	   #undef j
	   #undef k
	ans=1<<30; dfs(n);
	printf("%d\n",ans);
	int i;
	for(i=1;i<=n;i++)
	   if(as[i]) printf("%d ",i);
	return 0;
}
