#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
typedef long long ll;
ll n, a[30010], s[30010], m, f[4][30010], c[60010], ans;
ll val(int x) { return lower_bound(s+1, s+m+1, x) - s; }
ll ask(int x, ll sum = 0) {
	for(; x; x -= (x & (-x))) sum += c[x];
	return sum;
}
void add(int x, ll v) { for(; x <= m; x += (x & (-x))) c[x] += v; }
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i],  s[i] = a[i];
	sort(s+1, s+n+1);
	m = unique(s+1, s+n+1) - s - 1;
	for(int i = 1; i <= n; i++) f[1][i] = 1, a[i] = val(a[i]);
	for(int i = 2; i <= 3; i++) {
		memset(c, 0, sizeof(c));
		for(int j = 1; j <= n; j++) {
			f[i][j] = ask(a[j]-1);
			add(a[j], f[i-1][j]);
		}
	}
	for(int i = 1; i <= n; i++) ans += f[3][i];
	cout << ans << endl;
	return 0;
}
