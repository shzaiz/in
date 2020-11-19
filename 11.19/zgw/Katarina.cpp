#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 500005
int n,m,ans;
#define int long long
char ch[N][2];
int x[N],mn[N];
priority_queue<int,vector<int>,greater<int> >q;
signed main(){
    freopen("Katarina.in","r",stdin);
	freopen("Katarina.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){scanf("%s",ch[i]+1);cin>>x[i];}
	int now=1e9;
	for(int i=n;i>=1;i--){
		if(ch[i][1]=='p')now=min(x[i]-1,now);
		mn[i]=now;
	}
	for(int i=1;i<=n;i++){
		if(ch[i][1]=='d')q.push(x[i]);
		while(q.size()>mn[i])q.pop();
	}
	if(q.size()<m){puts("-1");return 0;}
	while(!q.empty())ans+=q.top(),q.pop();
	cout<<ans;
	return 0;
}
