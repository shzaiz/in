#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define maxn 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
struct Edge{
	int from,to,cap,flow;
	Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
}; 
int n, m;
vector<Edge> edges;
vector<int> G[maxn];
int a[maxn], p[maxn];

void init(int n) {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
}

void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = (int)edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}
int maxfl(int s,int t){
	int flow = 0;
	for(;;){
		memset(a,0,sizeof(a));
		queue<int > Q;
		Q.push(s);
		a[s] = 998244353;
		while(!Q.empty()){
			int x= Q.front();
			Q.pop();
			for(int i = 0;i<G[x].size();++i){
				Edge &e = edges[G[x][i]];
				if(!a[e.to] && e.cap>e.flow){
					p[e.to] = G[x][i];
					a[e.to] = min(a[x],e.cap - e.flow);
					Q.push(e.to);
				}
			}
			if(a[t]) break; // Arrival to the dest
		}
		if(!a[t]) break; // No flow
		for(int u = t;u!= s;u = edges[p[u]].from){
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
		}
		flow+=a[t];	
	}
	return flow;
}
int main(){
	AddEdge(2,1,30);
	AddEdge(4,2,30);
	AddEdge(2,3,20);
	AddEdge(1,3,30);
	AddEdge(4,3,20);
	cout<<maxfl(4,3); 
	return 0;
}

