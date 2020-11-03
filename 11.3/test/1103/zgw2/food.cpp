#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define int long long
int n;
int T;
#define fo0(i,x) for(register int i =0;i<x;++i)
#define fo3(i,x) for(register int i =3;i<=x;++i)
#define fo(i,b,x) for(register int i =(int)(b);i<=(int)(x);++i)
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
	
	#ifdef XBZAKIOI
	freopen("D:/Testcases/in.ac","r",stdin);
	freopen("D:/Testcases/out.ac","w",stdout);
	#else
	freopen("food.in","r",stdin);
	freopen("food.out","w",stdout);
	#endif
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
		printf("%lld\n",anss);
	}
	return 0;
}


//#include <bits/stdc++.h>
//using namespace std;
//#define N 5000005
//#define int long long
//int f[N][3][3],n;
//#define y 0
//#define r 1
//#define q 2
//#define fo0(i,x) for(int i =0;i<x;i++)
//#define fo3(i,x) for(int i =3;i<=x;i++)
//
//signed main(){
//	freopen("D:\\in.in","r",stdin);
//	freopen("D:\\out.out","w",stdout);
//	fo0(i,3) fo0(j,3) f[2][i][j] = 1;
//	n = 4;
//	fo3(i,n){
//		f[i]0 = f[i-1][8] + f[i-1][4];
//		f[i][1] = f[i-1][7] + f[i-1][6];
//		f[i][2] = f[i-1][3] + f[i-1][5];
//		f[i][3] = f[i-1]0 + f[i-1][8];
//		f[i][4] = f[i-1][3] + f[i-1][2];
//		f[i][5] = f[i-1][7] + f[i-1][1];
//		f[i][6] = f[i-1][5] + f[i-1][2];
//		f[i][7] = f[i-1]0 + f[i-1][6] + f[i-1][8];
//		f[i][8] = f[i-1][6] + f[i-1][7] + f[i-1][1];
//	}
//	int ans = 0;
//	fo0(i,3) fo0(j,3) ans+= f[n][i][j];
//	cout<<ans;
//}

