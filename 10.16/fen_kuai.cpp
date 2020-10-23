#include <cmath>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int block, len;
int a[N], l[N], r[N], pos[N], add[N];

void change(int x, int y, int z) {
  if (pos[x] == pos[y]) {
    for (int i = x; i <= y; i++) {
      a[i] += z;
    }
    return;
  }

  for (int i = pos[x] + 1; i <= pos[y] - 1; i++) {
    add[i] += z;
  }

  for (int i = x; i <= r[pos[x]]; i++) {
    a[i] += z;
  }
  for (int i = l[pos[y]]; i <= y; i++) {
    a[i] += z;
  }
}

int ask(int x) { return a[x] + add[pos[x]]; }

int main() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  block = sqrt(n);
  len = n / block;

  for (int i = 1; i <= block; i++) {
    l[i] = (i - 1) * len + 1;
    r[i] = i * len;
  }

  if (n % block) {
    block++;
    l[block] = r[block - 1] + 1;
    r[block] = n;
  }

  for (int i = 1; i <= block; i++) {
    for (int j = l[i]; j <= r[i]; j++) {
      pos[j] = i;
    }
  }

  int opt, l, r, c;
  int T = n;
  while (T--) {
    cin >> opt >> l >> r >> c;

    if (opt == 0) {
      change(l, r, c);
    } else {
      cout << ask(r) << endl;
    }
  }

  return 0;
}