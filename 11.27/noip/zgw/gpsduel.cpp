#include <bits/stdc++.h>
using namespace std;
#define  N 50010
#define fo(i,n) for(int i = 1 ;i<=n;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++)
#define rep(i,b,a) for(int i = b ;i>=a;i--)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<cstring>
#define LL long long
#define PII pair<int,int>
#define fi first
#define se second
#define mem(a,b) memset(a,b,sizeof(a))
struct Edge{
	int u,v,w1,w2,nxt;
	Edge() {}
	Edge(int XBZ,int A,int K,int IO,int I):u(XBZ),v(A),w1(K),w2(IO),nxt(I) {}
}e[N],e2[N],e3[N];
int n,m,head2[N],head3[N],head[N],cnt2=-1,cnt3=-1,cnt=-1,a,b,c,d,dis1[N],dis2[N],dis3[N];
bool vis[N];
queue<int> Q;
void adde(int a,int b,int c,int d){
	e[++cnt2]=Edge(a,b,c,d,head2[a]);head2[a]=cnt2;
	e3[++cnt3]=Edge(b,a,c,d,head3[b]);head3[b]=cnt3;
}
void adde2(int a,int b,int c){
	e2[++cnt]=Edge(a,b,c,0,head[a]);head[a]=cnt;
}
void SPFA1(){
	mem(vis,0);mem(dis1,42);
	while(Q.size())Q.pop();
	Q.push(n);vis[n]=1;dis1[n]=0;
	while(!Q.empty()){
		int now=Q.front();Q.pop();
		for(int i=head3[now];i!=-1;i=e3[i].nxt)
		    if(dis1[now]+e3[i].w1<dis1[e3[i].v]){
		    	dis1[e3[i].v]=dis1[now]+e3[i].w1;
		    	if(!vis[e3[i].v]){
					Q.push(e3[i].v);
					vis[e3[i].v]=1;
				} 
			}
		vis[now]=0;
	}
	return;
}
void SPFA2(){
	mem(vis,0);mem(dis2,42);
	while(Q.size())Q.pop();
	Q.push(n);vis[n]=1;dis2[n]=0;
	while(!Q.empty()){
		int now=Q.front();Q.pop();
		for(int i=head3[now];i!=-1;i=e3[i].nxt)
		    if(dis2[now]+e3[i].w2<dis2[e3[i].v]){
		    	dis2[e3[i].v]=dis2[now]+e3[i].w2;
		    	if(!vis[e3[i].v]){
					Q.push(e3[i].v);
					vis[e3[i].v]=1;
				} 
			}
		vis[now]=0;
		// cout<<Q.size();
	}
	return;
}
void SPFA3(){
	mem(vis,0);mem(dis3,42);
	while(Q.size())Q.pop();
	Q.push(1);vis[1]=1;dis3[1]=0;
	while(!Q.empty()){
		int now=Q.front();Q.pop();
		for(int i=head[now];i!=-1;i=e2[i].nxt)
		    if(dis3[now]+e2[i].w1<dis3[e2[i].v]) {
		    	dis3[e2[i].v]=dis3[now]+e2[i].w1;
		    	if(!vis[e2[i].v]){
					Q.push(e2[i].v);
					vis[e2[i].v]=1;
				} 
			}
		vis[now]=0;
	}
	return;
}
int main(){
	freopen("gpsduel.in","r",stdin);
	mem(head2,-1);mem(head3,-1);mem(head,-1);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c>>d;adde(a,b,c,d);
	}
	SPFA1();
	SPFA2();
	for(int l=1;l<=n;l++)
		for(int i=head2[l];i!=-1;i=e[i].nxt){
			int cnt=0;
			if(dis1[l]!=dis1[e[i].v]+e[i].w1)cnt++;
			if(dis2[l]!=dis2[e[i].v]+e[i].w2)cnt++;
			adde2(l,e[i].v,cnt);
		}
	SPFA3();
	cout<<dis3[n];
	return 0;
}

