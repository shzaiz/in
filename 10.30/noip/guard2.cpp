
#include <bits/stdc++.h>
#define N 215
using namespace std;
#define fo(i,x) for(int i = 1;i<=(x);i++)
#define fo0(i,x) for(int i = 0;i<=(x);i++)
#define fo2(i,x) for(int i = 2;i<=(x);i++)
int n,l,k,a[N];
//i场时，胜利数为k，碎片数为j
double p[N],f[N][N*2][N],ans;
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    #endif
	cin>>n>>l>>k;
	fo(i,n) {cin>>p[i];p[i]=p[i]/100;}
	fo(i,n) cin>>a[i];
	f[0][n][0]=1;
    //f[i][j][k] = i场时，胜利数为k，碎片数为j
	fo(i,n)
		fo0(k,3*n){
			f[i][k][0]+=f[i-1][k][0]*(1-p[i]);
			for(int j=1;j<=i;j++){
				f[i][min(k+a[i],2*n)][j]+=f[i-1][k][j-1]*(p[i]);
				f[i][k][j]+=f[i-1][k][j]*((1-p[i]));
			}
		}
 
	for(int i=n-k;i<=3*n;i++)
		for(int j=l;j<=n;j++){
			ans+=f[n][i][j];
		}
	cout<<fixed<<setprecision(6)<<ans<<endl;
    return 0;
}
