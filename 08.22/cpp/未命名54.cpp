#include <bits/stdc++.h>
#define inf 1e8+7.0
#define eps 1e-1 
using namespace std;
const int maxn=1e4+5;
double dis[maxn];
int used[maxn],head[maxn],num[maxn];
double l,r;
int size=0,n,m,cas,t;
struct EDGE{
	int u,v,nxt;
	double w;
}edge[maxn];
void add(int u,int v,double w){
	edge[size].u=u;
	edge[size].v=v;
	edge[size].w=w;
	edge[size].nxt=head[u];
	head[u]=size++;
}
bool SPFA(){
	deque<int>q;
	for(int i=1;i<=n;i++){
		used[i]=0;
		num[i]=0;
	}
	for(int i=1;i<=n;i++)
	q.push_back(i),dis[i]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		used[u]=0;
		for(int i=head[u];~i;i=edge[i].nxt){
			int v=edge[i].v;
			if(dis[v]-(dis[u]+edge[i].w)>eps){
				dis[v]=dis[u]+edge[i].w;
				if(used[v])continue;
				used[v]=0;
				if(!q.empty()){
					if(dis[q.front()]-dis[v]>eps)q.push_front(v);
					else q.push_back(v);
				}
				else q.push_back(v);
				num[v]++;
				if(num[v]>n)return true;
			}
		}
	}
	return false;
}

bool check(double mid){
	for(int i=0;i<size;i++){
		edge[i].w-=mid;
	}
	bool flag=SPFA();
	for(int i=0;i<size;i++){
		edge[i].w+=mid;
	}
	return flag;
}



void readdata(){
	memset(head,-1,sizeof(head));
	memset(edge,0,sizeof(edge));
	size=0;
	l=inf,r=-inf;
	scanf("%d%d",&n,&m);
	int u,v;
	double w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&u,&v,&w);
		add(u,v,w);
		r=max(r,w);
		l=min(l,w);
	}
	printf("Case #%d: ",++cas);
}

void work(){
	if(!check(r+1)){
		printf("No cycle found.\n");  
        return;
	}	
	while(r-l>=eps){
		double mid=l+(r-l)/2;
		if(check(mid)){
			r=mid;
		}else {
			l=mid;
		}
	}
	printf("%.2lf\n",r);
}


int main(){
	scanf("%d",&t);
	while(t--){
		readdata();
		work();
	}
	return 0;
}
