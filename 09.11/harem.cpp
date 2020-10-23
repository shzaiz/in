#include<bits/stdc++.h>
#define mod (100000007)
#define M 101
using namespace std;
int v[M][M],tmp[M][M],a[M][M];
char ch[M][M];
int n,m;
int ans;
void mul(int aa[M][M],int bb[M][M],int cc[M][M]){
    for(int i=0;i<=m;i++)
     	for(int j=0;j<=m;j++)
      		for(int k=0;k<=m;k++)
       		tmp[i][j]=(tmp[i][j]+aa[i][k]*bb[k][j])%mod;
    for(int i=0;i<=m;i++)
     	for(int j=0;j<=m;j++)
      		cc[i][j]=tmp[i][j],tmp[i][j]=0;
}
void qp(int n){
	n--;
    while(n){
        if(n%2!=0)mul(a,v,a);
        mul(v,v,v);
        n/=2;        
    }
}
int main(){
	freopen("harem.in","r",stdin);
	freopen("harem.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%s",ch[i]+1);
    // dp[i][j] += dp[i-1][k], k \in (0,i-1)
    // Mat A = rev[对角矩阵].
    // Mat B = 01 -10 - 10- 01相似
    for(int i=1;i<=m;i++)
     	for(int j=1;j<=m;j++)
      		if(ch[i][j]=='0') 
      			v[i][j]=a[i][j]=1;
    for(int i=0;i<=m;i++) v[0][i]=v[i][0]=a[i][0]=a[0][i]=1;
    qp(n);
    for(int i=0;i<=m;i++) ans=(ans+a[i][0])%mod;
    printf("%d",ans);
}
