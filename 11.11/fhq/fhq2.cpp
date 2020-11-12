//Coded by dy.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc getchar()
#define pc(x) putchar(x)
#define re register
const int Maxn = 1e5 + 200 + 10;
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl;
inline int sc() {
    int xx = 0, ff = 1; char cch = gc;
    while(!isdigit(cch)) {
        if(cch == '-') ff = -1; cch = gc;
    }
    while(isdigit(cch)) {
        xx = (xx << 1) + (xx << 3) + (cch ^ '0'); cch = gc;
    }
    return xx * ff;
}
inline void out(int x) {
    if(x < 0)
		pc('-'), x = -x;
    if(x >= 10)
        out(x / 10);
    pc(x % 10 + '0');
}
struct fhq_Treap {
	int ch[2];
	int siz, val, dat;
}t[Maxn];
int n, m, cnt;
int rt, r1, r2, r3, r4, tot;
string s[Maxn];
inline void pushup(int id) {
	t[id].siz = t[t[id].ch[0]].siz + t[t[id].ch[1]].siz + 1;
}
inline int cre(int r) {
	t[++tot].siz = 1, t[tot].val = r, t[tot].dat = rand();
	return tot;
}
inline void split(int id, int r, int &x, int &y) {
	if(!id)
		x = y = 0;
	else {
		if(r <= t[t[id].ch[0]].siz) {
			y = id;
			split(t[id].ch[0], r, x, t[id].ch[0]);
		}
		else {
			x = id;
			split(t[id].ch[1], r - t[t[id].ch[0]].siz - 1, t[id].ch[1], y);
		}
		pushup(id);
	}
}
inline int merge(int x, int y) {
	if(!x || !y)
		return x + y;
	if(t[x].dat < t[y].dat) {
		t[x].ch[1] = merge(t[x].ch[1], y);
		pushup(x);
		return x;
	}
	t[y].ch[0] = merge(x, t[y].ch[0]);
	pushup(y);
	return y;
}
inline void insert(int r, int id) {
	split(rt, r, r1, r2);
	rt = merge(r1, merge(cre(id), r2));
}
inline void query(int r) {
	split(rt, r, r1, r2);
	split(r2, 1, r3, r4);
	cout << s[t[r3].val] << endl;
	rt = merge(r1, merge(r3, r4));
}
int main() {
	srand(20041029);
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
	n = sc();
	for(re int i = 1; i <= n; ++i) {
		cin >> s[++cnt];
		insert(i - 1, cnt);
	}
	m = sc();
	while(m--) {
		cin >> s[++cnt];
		int x = sc();
		insert(x, cnt);
	}
	m = sc();
	while(m--) {
		int x = sc();
		query(x);
	}
    return 0;
}