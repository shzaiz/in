#include <bits/stdc++.h>
using namespace std;
pair<int,int> aa[10010];
int n,m,k;
struct ans{
	int x,y,z,a;
}Q[10010];
int cnt = 0;
void deb(pair<int,int> a[]){
	for(int i=1;i<=n;i++) cout<<a[i].first<<" "<<a[i].second<<endl;
	cout<<endl;
}

void input(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		aa[i] = make_pair(t,i);
	}
}

void dfs(pair<int,int> a[],int pt){
	cout<<a<<" "<<pt<<endl;
	for(int i = n;i>pt+1;i--){
		sort(a+pt+1,a+n+1);
		cout<<"Considering"<<pt<<" "<<i<<endl;
		if(a[pt+1].first + a[pt+i].first<k){
			cout<<"!"<<endl;
			return;
		}
		if(pt>k) {
			cout<<"!!"<<endl;
			return;
		}
		
		int tmp = a[pt+i].first;
		a[pt+i].first =a[pt+i].first- (k-a[pt+1].first);
		int tmp1 = a[pt+i].first;
		a[pt+1].first=0;
		deb(a);
		dfs(a,pt+1);
		a[pt+i].first =tmp;
		a[pt+1].first = tmp1;
	} 
	
}

int main(){
	freopen("D:\\in.txt","r",stdin);
	input();
	dfs(aa,0);
	
} 
