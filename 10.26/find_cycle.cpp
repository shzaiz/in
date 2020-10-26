#include <bits/stdc++.h>
using namespace std;
#define N 10010
struct Edge{
	int to,nxt,w;
}e[N];
int head[N],cnt=0;
void adde(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
	e[cnt].w= w;
}
int main(){
    
}