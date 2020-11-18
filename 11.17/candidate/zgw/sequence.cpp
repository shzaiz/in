
#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define ll long long
using namespace std;
int n,a[1002];
ll f[1002][3000],g[1002][3000],add[1002][3000];
ll ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	#ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    #endif
	cin>>n;
	fo(i,n) cin>>a[i];
    int i,j;
	f[1][a[1]]=1; add[1][a[1]]=1;
	fo_(i,2,n){
        f[i][a[i]]++; add[i][a[i]]++;
		fo_(j,0,2999){
            if(f[i-1][j]>0){
                f[i][j^a[i]]+=f[i-1][j]; add[i][j^a[i]]+=f[i-1][j];
		        f[i][j]+=f[i-1][j]; 
		      }
		   }
	   }
	g[n][a[n]]=1;
    re(i,n-1,0){
        g[i][a[i]]++; 
		fo_(j,0,2999){
		    if(g[i+1][j]>0){
                g[i][j]+=g[i+1][j];
			    g[i][j&a[i]]+=g[i+1][j];
			   }
		   }
	   }
	fo(i,n)fo_(j,0,2999) ans+=add[i][j]*g[i+1][j];
	cout<<ans;
	return 0;
}