#include <bits/stdc++.h>

using namespace std;

#define root 1, m, 1
#define ls l, mid, rt << 1
#define rs mid + 1, r, rt << 1 | 1

int m, d, q[12345678], t;

void build(int l, int r, int rt) {
  q[rt] = -214783647;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(ls);
  build(rs);
}

int input_int;

char input_char;

void plusa(int l, int r, int rt, int p, int v) {
  if (l == r) {
    q[rt] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    plusa(ls, p, v);
  else
    plusa(rs, p, v);
  q[rt] = max(q[rt << 1], q[rt << 1 | 1]);
}

int sth;

int ask(int l, int r, int rt, int nowl, int nowr) {
  if (nowl <= l && r <= nowr) return q[rt];
  int mid = (l + r) >> 1;
  int minn = -2147483647;
  if (nowl <= mid) minn = ask(ls, nowl, nowr);
  if (nowr > mid) minn = max(minn, ask(rs, nowl, nowr));
  return minn;
}
int main() {
  scanf("%d%d", &m, &d);
  build(root);
  for (int i = 1; i <= m; ++i) {
    cin >> input_char >> input_int;
    if (input_char == 'A') {
      sth++;
      plusa(root, sth, (input_int + t) % d);
    } else {
      t = ask(root, sth - input_int + 1, sth);
      cout << t << endl;
    }
  }
  return 0;
}