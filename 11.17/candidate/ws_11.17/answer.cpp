#include<bits/stdc++.h>
using namespace std;
#define re register int
int n,m,p,q;
char a[30005][505];
char ans[1005];
int main(){
	freopen("answer.in","r",stdin);
	freopen("answer.out","w",stdout);
	cin>>n>>m>>p>>q;
	for(re i=1;i<=n;i++){
		for(re j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(re i=1;i<=m;i++){
		int num=0;
		for(re j=1;j<=n;j++){
			if(a[j][i]=='N')
				num++;
		}
		if(num==p)
			ans[i]='N';
		else{
			num=0;
			for(re j=1;j<=n;j++){
				if(a[j][i]=='Y')
					num++;
			}
			if(num==p)
				ans[i]='Y';
			else{
				cout<<"-1";
				return 0;
			}
		}
	}
	for(re i=1;i<=m;i++)
		cout<<ans[i];
}
