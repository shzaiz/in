#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005];
ll n,f[1000005][4][3];
int main(){
	freopen("jx.in","r",stdin);
	freopen("jx.out","w",stdout);
	cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        for (int j = 1; j <= 3; j++){
            f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1]);
            f[i][j][1] = max(max(f[i-1][j-1][1],f[i-1][j-1][0]),f[i-1][j][1])+a[i];
        }
    cout<<max(f[n][3][0], f[n][3][1]);
}
