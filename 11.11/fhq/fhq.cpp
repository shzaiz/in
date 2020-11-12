#include <bits/stdc++.h>
using namespace std;
#define ls(o) t[o].ls
#define rs(o) t[o].rs
#define N 1000010
struct FHQ{
    int ls,rs,sz ,val, k;
}t[N];
int n,m,k;
string s[N];
int cnt = 0;
int cntw = 0;
int rt, x,y,z,a;
void upd(int o){
    t[o].sz = t[ls(o)].sz+t[rs(o)].sz+1;
}
void split(int o,int x,int &l,int &r){
    if(!o) {l = 0, r = 0; return;}
    if(x <= t[ls(o)].sz){
        r = o; split(ls(o),x,l,ls(r));
        upd(o);
        return;
    } else{
        l = o; split(rs(o),x-t[ls(o)].sz-1,rs(l),r);
        upd(o);
        return;
    }
}
int merge(int u,int v){
    if(!u || !v) return u|v;
    if(t[u].k<=t[v].k){
        t[u].rs = merge(t[u].rs,v);
        upd(u);
        return u;
    }else{
        t[v].ls = merge(u,t[v].ls);
        upd(v);
        return v;
    }
}
int newnode(int val){
    t[++cnt].val = val;
    t[cnt].k = rand();
    t[cnt].sz = 1;
    return cnt;
}
int r1,r2,r3,r4;
inline void insert(int r, int o) {
	split(rt, r, r1, r2);
	rt = merge(r1, merge(newnode(o), r2));
}
inline void query(int r) {
	split(rt, r, r1, r2);
	split(r2, 1, r3, r4);
	cout << s[t[r3].val] << endl;
	rt = merge(r1, merge(r3, r4));
}
int sc(){
    int x;cin>>x;return x;  
}
int main(){
    srand(20041029);
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    n = sc();
	for( int i = 1; i <= n; ++i) {
		cin >> s[++cntw];
		insert(i - 1, cntw);
	}
	m = sc();
	while(m--) {
		cin >> s[++cntw];
		int x = sc();
		insert(x, cntw);
	}
	m = sc();
	while(m--) {
		int x = sc();
		query(x);
	}
}