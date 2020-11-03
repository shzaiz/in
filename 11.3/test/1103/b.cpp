#include <bits/stdc++.h>
using namespace std;
#define N 5000005
#define int long long
int f[N][3][3],n;
#define y 0
#define r 1
#define q 2
#define fo0(i,x) for(int i =0;i<x;i++)
#define fo3(i,x) for(int i =3;i<=x;i++)

signed main(){
	freopen("D:\\in.in","r",stdin);
	freopen("D:\\out.out","w",stdout);
	fo0(i,3) fo0(j,3) f[2][i][j] = 1;
	n = 4;
	fo3(i,n){
		f[i]0 = f[i-1][8] + f[i-1][4];
		f[i][1] = f[i-1][7] + f[i-1][6];
		f[i][2] = f[i-1][3] + f[i-1][5];
		f[i][3] = f[i-1]0 + f[i-1][8];
		f[i][4] = f[i-1][3] + f[i-1][2];
		f[i][5] = f[i-1][7] + f[i-1][1];
		f[i][6] = f[i-1][5] + f[i-1][2];
		f[i][7] = f[i-1]0 + f[i-1][6] + f[i-1][8];
		f[i][8] = f[i-1][6] + f[i-1][7] + f[i-1][1];
	}
	int ans = 0;
	fo0(i,3) fo0(j,3) ans+= f[n][i][j];
	cout<<ans;
}
