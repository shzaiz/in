#include <bits/stdc++.h>
using namespace std;
int n,k,m;
int ned[1001];
int spo[1001];
int wt[1001];
int flag=0,ans=-1;
map<string,int>mp;
struct node {
	int enc[1001];
	int t;
}
now,nxt;
void bdf() {
	string ans;
	for (int i=1;i<=n;i++)
	        ans=ans+(char)(ned[i]+48);
	mp[ans]=2;
}
int mke(node how) {
	string w;
	for (int i=1;i<=n;i++)
	         w=w+(char)(how.enc[i]+48);
	if(mp[w]==2) {
		ans=how.t;
		flag=1;
		return 1;
	}
	if(mp[w]==0) {
		mp[w]=1;
		return 1;
	}
}
void bfs() {
	for (int i=1;i<=n;i++) now.enc[i]=spo[i];
	now.t=0;
	queue<node>q;
	q.push(now);
	while(q.size()!=0) {
		node p=q.front();
		q.pop();
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) {
				if(wt[j]+i<=n) {
					memset(nxt.enc,0,sizeof(nxt.enc));
					for (int k=1;k<=n;k++)nxt.enc[k]=p.enc[k];
					for (int k=i;k<=i+wt[j]-1;k++) {
						if(nxt.enc[k]==0)nxt.enc[k]=1;
					    else nxt.enc[k]=0;
						nxt.t=p.t+1;
					}
					if(mke(nxt)==1) {
						if(flag==1) {
							printf("%d",ans);
							break;
						}
						q.push(nxt);
					}
				}
				if(flag==1)break;
			}
			if(flag==1) break;
		}
		if(flag==1)break;
	}
}
int main() {
	freopen("password.in","r",stdin);
	freopen("password.out","w",stdout);
	cin>>n>>k>>m;
	for (int i=1;i<=k;i++) {
		int p;
		cin>>p;
		ned[p]=1;
	}
	for (int i=1;i<=m;i++)cin>>wt[i];
	bdf();
	bfs();
	if(flag==0) {
		printf("-1");
	}
	return 0;
}
