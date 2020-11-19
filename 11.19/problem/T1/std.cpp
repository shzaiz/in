#include<cstdio>
#define int long long
#define MAXN 100005
#define MAXK 55
using namespace std;
int a[MAXN],s[MAXK][MAXN];
signed main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/duipai.ac","w",stdout);
    #endif
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	s[1][1]=a[1];
	for(int y=2;y<=n;++y)
		s[1][y]=(s[1][y-1]+a[y])%19260817;
	for(int x=2;x<=k;++x)
		for(int y=2;y<=n;++y)
			s[x][y]=(s[x][y-1]+a[y]*s[x-1][y-1]%19260817)%19260817;
	printf("%d",s[k][n]);
	return 0;
}