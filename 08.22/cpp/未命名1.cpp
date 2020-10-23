#include <bits/stdc++.h>
using namespace std;
#define MAXN 10010
int frm[MAXN],to[MAXN],tim[MAXN];
int go[MAXN],dis[MAXN];
int n,m,k;
int main(){
	freopen("D:\\in.txt","r",stdin);
	memset(go,0,sizeof go);
	cin>>n>>m>>k;
	for(int i=1;i<n;i++){
		cin>>dis[i];
	}
	for(int i=1;i<=m;i++) {
		cin>>tim[i]>>frm[i]>>to[i];
		go[frm[i]] = max(tim[i],go[frm[i]]);
	}
	
	for(int i=1;i<n;i++){
		if(go[i]+dis[i]<=go[i+1]) continue;
		else go[i+1] = go[i]+dis[i];
	}
	int ans = 0;
	for(int i=1;i<=m;i++){
		ans+= (go[to[i]]-go[frm[i]]+1);
	}
	cout<<ans;
}
