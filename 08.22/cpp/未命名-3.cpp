#include <bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
ll c1[N], c2[N], n, m, h[N] = { INT_MAX }, dist1[N], dist2[N];
double minv = INT_MAX;
int main(){
    cin>>n;
    for (int i = 1; i <= n; ++i)cin>>h[i];
    for (int i = n - 1; i >= 1; --i){
        register ll minn = i + 1, minn2 = 0;
        dist1[i] = abs(h[i] - h[i + 1]);
        for (int j = i + 2; j <= n; ++j){
            if (dist1[i] > abs(h[i] - h[j]) || (dist1[i] == abs(h[i] - h[j]) && h[j] < h[minn])){
                dist2[i] = dist1[i];
                dist1[i] = abs(h[i] - h[j]);
                minn2 = minn;
                minn = j;
            }else if (dist2[i] == 0 || dist2[i] > abs(h[i] - h[j]) || (dist2[i] == abs(h[i] - h[j]) && h[j] < h[minn2])){
                dist2[i] = abs(h[i] - h[j]);
                minn2 = j;
            }
        }
        c1[i] = minn;
        c2[i] = minn2;
    }
    ll x0;
	cin>>x0;ll ans = 0;
    for (int i = 1; i <= n; ++i){
        ll a = 0, b = 0, loc = i, turn = 0;
        while (1){
            if (turn){
                if (a + b + dist1[loc] > x0 || !c1[loc])break;
                b += dist1[loc];
                loc = c1[loc];
            }else{
                if (a + b + dist2[loc] > x0 || !c2[loc])break;
                a += dist2[loc];
                loc = c2[loc];
            }
            turn ^= 1;
        }
        if (!ans || 1.0*a / b - minv < -0.00000001 || (fabs(1.0*a / b - minv) <= 0.00000001&&h[ans] < h[i])){
            minv = 1.0*a / b;
            ans = i;
        }
    }
    printf("%lld\n", ans);
    cin>>m;
    while (m--){
        ll s , x , a = 0, b = 0, turn = 0;
        cin>>s>>x;
        while (1){
            if (turn){
                if (a + b + dist1[s] > x || !c1[s])break;
                b += dist1[s];
                s = c1[s];
            }
            else{
                if (a + b + dist2[s] > x || !c2[s])break;
                a += dist2[s];
                s = c2[s];
            }
            turn ^= 1;
        }

        printf("%lld %lld\n", a, b);
    }
    return 0;
}
