#include <bits/stdc++.h>
using namespace std;
double h, a, b;
bool ball[30] = {};
int ans = 0;
int anss = 0;
int dfs(int x, int pos, int time) {
  if (x > h) return 0;
  printf("%d %d %d %d\n", x, pos, time, h);
  if (pos > x) return 0;
  if (x == h) {
    if (ball[pos])
      return 0;
    else {
      ball[pos] = 1;
      ans += a * time * time + b * time;
      anss+=ans;
      printf("Gain%d\n", ans);
      dfs(1, 1, time + 1);
      ball[pos] = 0;
      return 0;
    }
  }
  dfs(x + 1, pos, time);
  dfs(x + 1, pos + 1, time);
}
int solve() {
  cin >> h >> a >> b;
  double x = (6 * a + 3 * b) / 3;
  if(h==2){ cout<<fixed<<setprecision(4)<<x<<endl;return 0;}
  dfs(1, 1, 1);
  cout << anss;
  return 0;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
int T;cin>>T;while(T--)
  solve();
}