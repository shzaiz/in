#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 998244353
#define Mem(a, x) memset(a, x, sizeof(a))
const int maxn = 30;
inline ll read(){
  ll ans = 0;
  char ch = getchar(), last = ' ';
  while(!isdigit(ch)) last = ch, ch = getchar();
  while(isdigit(ch)) ans = (ans << 1) + (ans << 3) + ch - '0', ch = getchar();
  if(last == '-') ans = -ans;
  return ans;
}
inline void write(ll x){
  if(x < 0) x = -x, putchar('-');
  if(x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}

int n, m, a[maxn], b[maxn], c[maxn];
struct Node{
  int b, c;
  bool operator < (const Node& oth)const{
  	return b < oth.b || (b == oth.b && c < oth.c);
  }
};
map<Node, Node> mp;

void dfs(int stp, int x, int y, int z, int f){
  if(stp > m){
      Node tp1 = (Node){x - z, x - y};
      if(mp.find(tp1) != mp.end()){
	        if(mp[tp1].b < x) mp[tp1] = (Node){x, f};
	    }
      else mp[tp1] = (Node){x, f};
      return;
    }
  dfs(stp + 1, x + a[stp], y + b[stp], z, f * 3);
  dfs(stp + 1, x + a[stp], y, z + c[stp], f * 3 + 1);
  dfs(stp + 1, x, y + b[stp], z + c[stp], f * 3 + 2);
}
int ans = -INF, path1, path2;
void dfs2(int stp, int x, int y, int z, int f){
  if(stp <= m){
      Node tp1 = (Node){z - x, y - x};
      if(mp.find(tp1) != mp.end()){
      	if(mp[tp1].b + x > ans){
      		ans = mp[tp1].b + x;
      		path1 = mp[tp1].c; path2 = f;
      	}
      }
      return;
    }
  dfs2(stp - 1, x + a[stp], y + b[stp], z, f * 3);
  dfs2(stp - 1, x + a[stp], y, z + c[stp], f * 3 + 1);
  dfs2(stp - 1, x, y + b[stp], z + c[stp], f * 3 + 2);
}

const char ch[3][3] = {"LM", "LW", "MW"};
int num[maxn], cnt = 0;
void print(){
	cnt = 0;
	for(int i = 1; i <= m; path1 /= 3, ++i) num[++cnt] = path1 % 3;
	for(int i = cnt; i; --i) puts(ch[num[i]]);
	for(int i = m + 1; i <= n; path2 /= 3, ++i) puts(ch[path2 % 3]);
}

int main(){
  n = read(); m = n >> 1;
  for(int i = 1; i <= n; ++i) a[i] = read(), b[i] = read(), c[i] = read();
  dfs(1, 0, 0, 0, 0);
  dfs2(n, 0, 0, 0, 0);
  if(ans == -INF) puts("Impossible");
  else print();
  return 0;
}