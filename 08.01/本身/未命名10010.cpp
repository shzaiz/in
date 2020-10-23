#include <iostream>
using namespace std;
int c[50010];
int l[50010],r[50010];
int dis1[50010],dis2[50010];
int ans1[50010],ans2[50010];
int n,ans;
bool err;

void deb(){
	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
}

void input(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	
}

void build(){
//	 c[1]=1;
//    c[n]=l[1];
//    c[2]=r[1];
//  for (int i=3; i<n; i++)
//        if (l[c[i-1]]==c[i-2]) c[i]=r[c[i-1]];
//        else c[i]=l[c[i-1]];
	c[1] = 1, c[n] = l[1] , c[2] = r[1];
	for(int i=2;i<=n-1;i++){
		if(l[c[i]]==c[i-1]) c[i+1] = r[c[i]];
		else if(r[c[i]]==c[i-1]) c[i+1] = l[c[i]];
		else{
			err = 1; return;
		}  
	}
}

void solve(){
	for(int i=1;i<=n;i++){
		ans1[(c[i]-i+n)%n]++;
        ans2[(c[i]+i-1)%n]++;
	}
	for (int i=0;i<n;++i){
    	if (ans<ans1[i]) ans=ans1[i];
    	if (ans<ans2[i]) ans=ans2[i];
	}
	cout<<n-ans<<endl;
}


int main(){
	input();
	build();
	if(err==1){
		cout<<"-1"<<endl;
	}else{
		solve();
	}
}
