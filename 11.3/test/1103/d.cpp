#include <bits/stdc++.h>
using namespace std;
#define N 5000005
#define int long long
int f[N][10],n;
int T;
#define fo0(i,x) for(register int i =0;i<x;++i)
#define fo3(i,x) for(register int i =3;i<=x;++i)
#define mod 1000000007
int a[9][9]=
{
//   0 1 2 3 4 5 6 7 8 9
	{0,0,0,0,1,0,0,0,1},
	{0,0,0,0,0,0,1,1,0},
	{0,0,0,1,0,1,0,0,0},
	{0,1,0,0,0,0,0,0,1},
	{0,0,1,1,0,0,0,0,0},
	{0,1,0,0,0,0,0,1,0},
	{0,0,1,0,0,1,0,0,0},
	{1,0,0,0,0,0,1,0,1},
	{0,1,0,0,0,0,1,1,0}
};
int s[2][10] = {
//   0 1 2 3 4 5 6 7 8 9
	{0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1}
} ;

struct M{
	int mp[9][9];
	void cls(){
		memset(mp,0,sizeof(mp));
	}
	void fi1(){
		memset(mp,0,sizeof(mp));
		fo0(i,9) mp[i][i]=1;
		
	}
};
M cheng(M x,M y){
	M ans;
	ans.cls();
	fo0(i,9)fo0(j,9)fo0(k,9)ans.mp[i][k]=(ans.mp[i][k]+x.mp[i][j]*y.mp[j][k])%mod;
	return ans;
}
M qp(M tmp,int p){
	M ans;
	ans.fi1();
	while(p){
		if(p&1){
			p^=1;
			ans=cheng(ans,tmp);
		}
		p>>=1;
		tmp=cheng(tmp,tmp);
	}
	return ans;
	
} ;
signed main(){
	freopen("D:\\in.in","r",stdin);
	freopen("D:\\out.out","w",stdout);
	M mat;
	fo0(i,9) fo0(j,9) mat.mp[i][j]=a[i][j];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		M res=qp(mat,n-2),ans;
		ans.cls();
		fo0(i,9)fo0(j,9)fo0(k,9)ans.mp[i][k]=(ans.mp[i][k]+s[i][j]*res.mp[j][k])%mod;
		int anss=0;
		fo0(i,9)anss=(anss+ans.mp[1][i])%mod;
		printf("%d\n",anss);
	}
	return 0;
}

