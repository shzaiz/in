#include<bits/stdc++.h>
#define MAXN 3001
using namespace std;
int ka[MAXN][MAXN],l[MAXN],nn[MAXN],r[MAXN],rr[MAXN];
int c[MAXN],cc[MAXN],tot,ans;
int n,m;

void inp(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>nn[i]; 
	for(int i=1;i<=m;i++)
		cin>>r[i]>>rr[i]>>c[i]>>cc[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){	
			if(nn[i]<=nn[j])	ka[i][j]=1;
		}
	}	
}

int  main(){
	freopen("tears.in","r",stdin);
	freopen("tears.out","w",stdout);
	inp();
	for(int i=1;i<=m;i++){
		ans=0;
		memset(l,0,sizeof(l)); 
		for(int j=1;j<=n;j++){
			if(j>=r[i]&&j<=rr[i]&&nn[j]>=c[i]&&nn[j]<=cc[i])	l[j]=1;
		}
		for(int j=1;j<=n;j++){
			if(l[j]==0)	continue;
			for(int k=1;k<=n;k++){
				if(l[k]==0)	continue;
				ans=ans+ka[j][k];
			}
		}
		cout<<ans<<endl;
	}
}
