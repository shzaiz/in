#include <bits/stdc++.h>
using namespace std;
#define N 5000005
#define int unsigned long long
int a[N],n;
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n;
	int mx = -1, mi = 1e11;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		mx = max(a[i],mx);
		mi = min(mi, a[i]);
	}
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(mi<=a[i] && a[i]<=mx){
			cnt++;
		}
	}
	cout<<mx-mi-n+1<<endl;
	return 0;
}
