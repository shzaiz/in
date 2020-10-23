#include <bits/stdc++.h>
using namespace std;
bool pan[200010];
int n, m, x, y, fa[200010], gb[200010], sum = 0, ans[200010];
int head[400010], nxt[400010], son[400010], tot;
int get(int x) {
  if (x == fa[x]) return x;
  return fa[x] = get(fa[x]);
}
void merge(int x, int y) { fa[get(x)] = get(y); }
void adde(int x, int y) {
  son[++tot] = y;
  nxt[tot] = head[x];
  head[x] = tot;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;  //并查集基本操作
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    adde(x, y), adde(y, x);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &gb[i]);
  for (int i = n; i >= 1; i--) {
    sum++;
    pan[gb[i]] = 1;
    for (int j = head[gb[i]]; j; j = nxt[j])
      if (pan[son[j]] && get(gb[i]) != get(son[j]))
        merge(gb[i], son[j]), sum--;  //连边并维护
    if (sum == 1) ans[i] = 1;
  }
  for (int i = 1; i <= n; i++) puts(ans[i] == 1 ? "YES" : "NO");
}