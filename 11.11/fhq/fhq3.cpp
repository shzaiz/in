#include<bits/stdc++.h>
using namespace std;
const int N=80000+5;
int n, m, id[N], a[N], root, r1, r2, r3, r4, cnt = 0;
struct treap{
    int ch[2], fa, size, rd, val;
}t[N];
int gi(){
    int ans = 0, f = 1; char i = getchar();
    while(i<'0' || i>'9'){ if(i == '-') f = -1; i = getchar(); }
    while(i>='0' && i<='9') ans = ans*10+i-'0', i = getchar();
    return ans * f;
}
int newnode(int val){
    t[++cnt].val = val; t[cnt].rd = rand(), t[cnt].size = 1;
    id[val] = cnt; return cnt;
}
void up(int x){ t[x].size = t[t[x].ch[0]].size+t[t[x].ch[1]].size+1; }

void split(int x, int k, int &a, int &b, int faa = 0, int fab = 0){
    if(x == 0){ a = b = 0; return; }
    if(k <= t[t[x].ch[0]].size) t[x].fa = fab, b = x, split(t[x].ch[0], k, a, t[x].ch[0], faa, x);
    else t[x].fa = faa, a = x, split(t[x].ch[1], k-t[t[x].ch[0]].size-1, t[x].ch[1], b, x, fab); up(x);
}

int merge(int x, int y){
    if(x == 0 || y == 0) return x+y;
    if(t[x].rd < t[y].rd){
		t[x].ch[1] = merge(t[x].ch[1], y);
		t[t[x].ch[1]].fa = x; up(x); return x;
    }
    else {
		t[y].ch[0] = merge(x, t[y].ch[0]);
		t[t[y].ch[0]].fa = y; up(y); return y;
    }
}

void insert(int pos, int val){
    split(root, pos, r1, r2);
    root = merge(r1, merge(newnode(val), r2));
}

bool get(int x){ return t[t[x].fa].ch[1] == x; }

int find(int cnt){
    int node = cnt, res = t[t[cnt].ch[0]].size+1;
    while(node != root && cnt){
		if(get(cnt)) res += t[t[t[cnt].fa].ch[0]].size+1;
		cnt = t[cnt].fa;
    }
    return res;
}

int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    char opt[10]; int x, y, k; n = gi(), m = gi(); srand(998246556443543);
    for(int i=1;i<=n;i++) a[i] = gi(), insert(i-1, a[i]);
    for(int i=1;i<=m;i++){
		scanf("%s", opt); x = gi();
		
		if(opt[0] == 'T'){
		    k = find(id[x]);
		    split(root, k, r1, r3);
		    split(r1, k-1, r1, r2);
		    root = merge(r2, merge(r1, r3));
		}
		
		if(opt[0] == 'B'){
		    k = find(id[x]);
		    split(root, k, r1, r3, 0);
		    split(r1, k-1, r1, r2, 0);
		    root = merge(r1, merge(r3, r2));
		}
		
		if(opt[0] == 'I'){
		    y = gi(); k = find(id[x]);
		    if(y){
				if(y > 0){
				    split(root, k+1, r3, r4);
				    split(r3, k, r2, r3);
				    split(r2, k-1, r1, r2);
				    root = merge(r1, merge(r3, merge(r2, r4)));
				}
				else {
				    split(root, k, r3, r4);
				    split(r3, k-1, r2, r3);
				    split(r2, k-2, r1, r2);
				    root = merge(r1, merge(r3, merge(r2, r4)));
				}
		    }
		}
		
		if(opt[0] == 'A'){
		    k = find(id[x]);
		    printf("%d\n", k-1);
		}
		
		if(opt[0] == 'Q'){
		    split(root, x, r1, r2);
		    int node = r1;
		    while(t[node].ch[1]) node = t[node].ch[1];
		    printf("%d\n", t[node].val);
		    root = merge(r1, r2);
		}
    }
    return 0;
}