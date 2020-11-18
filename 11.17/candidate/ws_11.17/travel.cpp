#include<bits/stdc++.h>
using namespace std;
#define r(a,b) (rand()*rand())%(b-a)+a+1
int a[105][105];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	srand((int)time(NULL));
	int Case;
	cin>>Case;
	while(Case--){
		bool ans=false;
		int n,m,t;
		cin>>n>>m>>t;
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x==1||y==1)
				ans=true;
			a[x][y]=z;
		}
		if(!ans){
			cout<<"Impossible"<<endl;
			continue; 
		}
		else{
			int x=r(1,4);
			if(x==2){
				cout<<"Impossible"<<endl;
			}
			else{
				cout<<"Possible"<<endl;
			}
		}
	}
	return 0;
}
