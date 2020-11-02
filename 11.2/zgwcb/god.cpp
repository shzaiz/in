#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
struct E {
	ll l, r;
} a[N];
bool cmp(E &a, E &b) {
	return a.l==b.l?a.r>b.r:a.l<b.l;
}
int n, s[N], tp, fa[N],x,r;
ll sum[N];
int main() {
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)  {
		cin>>x>>r;
		a[i].l=x-r;
		a[i].r=x+r;
	}
	sort(a+1, a+1+n, cmp);
	for(int i = 1;i<=n;i++) {
		while(tp && a[s[tp]].r<a[i].r) {
			tp--;
		}
		fa[i]=s[tp];
		s[++tp]=i;
	}
	for(int i = 1;i<=n;i++){
		sum[fa[i]]+=a[i].r-a[i].l;
	}
	int ans=n+1;
	for(int i = 1;i<=n;i++) {
		if(sum[i]==a[i].r-a[i].l) ans++;
	}
	cout<<ans;
	return 0;
}
