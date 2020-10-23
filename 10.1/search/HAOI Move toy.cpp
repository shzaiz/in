#include<bits/stdc++.h>
using namespace std;
#define maxn 20
#define maxm (1 << 16) + 5
#define file(a) freopen(#a".in","r",stdin); freopen(#a".out","w",stdout);
typedef long long ll;
int v[2][maxm], q[2][maxm];
int s, e, h[2], t[2], now, u, k, f;
char c;
inline int read(){
	int x;
    x=0;char ch=0;bool sign=false;
    while(ch < '0' || ch > '9'){
        sign|=(ch == '-');
        ch=getchar();
    }
    while(!(ch < '0' || ch > '9')){
        x=x*10+(ch^48);
        ch=getchar();
    }
    x=sign ? -x : x;
    return x;
}

inline void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void init(){
	
}

void expand(int m, int b){
	if(now & (1 << m)) return;
	int k = now + (1 << m);
	if(v[b][k]) return;
	if(v[b ^ 1][k]){
		printf("%d", v[b ^ 1][k] + v[b][u] - 1);
		f = 1;
		return;
	}
	v[b][k] = v[b][u] + 1;
	q[b][++t[b]] = k;
}

void bfs(){
	h[0] = t[0] = h[1] = t[1] = 1;
	q[0][h[0]] = s; v[0][s] = true;
	q[1][h[1]] = e; v[1][e] = true;
	if(s == e){
		printf("0");
		return;
	}
	while(h[0] <= t[0] && h[1] <= t[1]){
		u = q[0][h[0]++];
		for(int i = 15; i >= 0; i--){
			if(! (u & (1 << i))) continue;
			now =  u ^ (1 << i);
			if(i / 4 < 3) expand(i + 4, 0); if(f) return;
			if(i / 4 > 0) expand(i - 4, 0); if(f) return;
			if(i % 4 != 3) expand(i + 1, 0); if(f) return;
			if(i % 4 != 0) expand(i - 1, 0);  if(f) return;
		}
		u = q[1][h[1]++];
		for(int i = 15; i >= 0; i--){
			if(! (u & (1 << i))) continue;
			now =  u ^ (1 << i);
			if(i / 4 < 3) expand(i + 4, 1); if(f) return;
			if(i / 4 > 0) expand(i - 4, 1); if(f) return;
			if(i % 4 != 3) expand(i + 1, 1); if(f) return;
			if(i % 4 != 0) expand(i - 1, 1);  if(f) return;
		}
	}
}

int main(){
	for(int i = 1; i <= 16; i++){
		cin >> c;
		s = (s << 1) + c - '0';
	}
	for(int i = 1; i <= 16; i++){
		cin >> c;
		e = (e << 1) + c - '0';
	}
	
	bfs();
	return 0;
}