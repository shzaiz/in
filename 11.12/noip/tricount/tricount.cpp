#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 0
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 200010 
#define int long long
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
struct Point{
	int x,y;
	double ang;
}P[N];int n;
int cross( Point x, Point y){
	return x.x*y.y-y.x*x.y;
}
bool cmp( Point x,   Point y){
	return x.ang<y.ang;
}
int C(int x){
	return x*(x-1)*(x-2)/6;
}
signed main(){
	freopen("tricount.in","r",stdin);
	freopen("tricount.out","w",stdout);
	cin>>n;
	fo(i,n){
		cin>>P[i].x>>P[i].y;
		P[i].ang = atan2(P[i].y+0.0,P[i].x+0.0);
	}
	sort(P+1,P+1+n,cmp);
	fo(i,n) P[n+i] = P[i];
	int ans = C(n);
	for(int i=1,j=1;i<=n;i++){
		deb cout<<ans<<"!\n";
		while(j<i+n&&cross(P[i],P[j])>=0) j++;
		int k=j-i-1;
		ans-=k*(k-1)/2;
	}
	cout<<ans;
	return 0;
} 
