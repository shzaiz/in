#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++) 
#define mp make_pair
#define x xxxxxxxxxxxxxxxxxxxxxxx
#define y yyyyyyyyyyyyyyyyyyyyyyy
#define x1 xxxxxxxxxxxxxxx1x1x11x
#define y1 yyyyyyyyyyyyyyyy1y1y1y
map< pair<int, int > ,int> m;
int x[N],y[N];
int n,ans = 0; 
int main(){
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	cin>>n;
	fo(i,n) {
		cin>>x[i]>>y[i]; m[mp(x[i],y[i])]=1;
	}
	fo(i,n)fo_(j,i+1,n){
		int a=x[i],b=y[i],c=x[j],d=y[j];  
        int dx=abs(a-c),dy=abs(d-b);  
        int x1=c-dy,y1=d+dx,x2=a-dy,y2=b+dx;  
        if(m[mp(x1,y1)]&&m[mp(x2,y2)])ans++;      
	} 
    cout<<ans/2;
    return 0;
}
