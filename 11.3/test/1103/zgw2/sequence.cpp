#include <bits/stdc++.h>
using namespace std;
#define N 5000005
#define int long long
int a[N],n;
signed main(){
	#ifdef XBZAKIOI
	freopen("D:/Testcases/in.ac","r",stdin);
	freopen("D:/Testcases/out.ac","w",stdout);
	#else
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	#endif
	cin>>n;
	int mx = -1, mi = 1e11;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		mx = max(a[i],mx);
		mi = min(mi, a[i]);
	}
	cout<<(mx-mi-n+1)<<endl;
	return 0;
}
