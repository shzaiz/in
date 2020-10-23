#include<bits/stdc++.h>
#define MAXN 904983
using namespace std;




struct QQ{int i;int x;int j;int y;}ans[MAXN];
int a[MAXN];
int n,m,kk;
bool fan,error;
inline void dfs(int d){
	if(d==m){
		if(error)return;
		for(int cur=1;cur<=m;cur++){
//			deb();
			if(!ans[cur].i){
//				cout<<"!"<<endl;
				cout<<ans[cur].j<<" "<<ans[cur].y<<endl;
			}else if(!ans[cur].j){
				cout<<ans[cur].i<<" "<<ans[cur].x<<endl;
			}else{
//				cout<<"!!!<-- Case 3"<<endl;
				cout<<ans[cur].i<<" "<<ans[cur].x<<" "<<ans[cur].j<<" "<<ans[cur].y<<endl;
			}
			fan=1,error=1;
		}
		return ;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=a[i];j++){
			for(int k=0;k<=n;k++){
				for(int l=0;l<=a[k];l++){
					if((i!=0&&j==0)||(k!=0&&l==0))continue;
					if(i==k)continue;
					if(j+l==kk){
						if(i!=0)a[i]-=j;
						if(k!=0)a[k]-=l;
						ans[d+1].i=i,ans[d+1].x=j,ans[d+1].j=k,ans[d+1].y=l;
						dfs(d+1);
						if(i!=0)a[i]+=j;
						if(k!=0)a[k]+=l;
						ans[d+1].i=0,ans[d+1].x=0,ans[d+1].j=0,ans[d+1].y=0;
					}
			}
		}
			
				
	}
	return ;
}
int main(){
	freopen("dish.in","r",stdin);
	freopen("dish.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>kk;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		fan=0,error=0;
		dfs(0);
		if(!fan)cout<<-1<<endl;
	}
	return 0;
}
int k;
void dfss(pair<int,int> a[],int pt){
//	cout<<a<<" "<<pt<<endl;
	for(int i = n;i>pt+1;i--){
		sort(a+pt+1,a+n+1);
//		cout<<"Considering"<<pt<<" "<<i<<endl;
		if(a[pt+1].first + a[pt+i].first<k){
//			cout<<"!"<<endl;
			return;
		}
		if(pt>k) {
//			cout<<"!!"<<endl;
			return;
		}
		
		int tmp = a[pt+i].first;
		a[pt+i].first =a[pt+i].first- (k-a[pt+1].first);
		int tmp1 = a[pt+i].first;
		a[pt+1].first=0;
	//	deb(a);
		dfss(a,pt+1);
		a[pt+i].first =tmp;
		a[pt+1].first = tmp1;
	} 
	
}
