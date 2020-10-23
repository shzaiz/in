#include <bits/stdc++.h>
using namespace std;

struct planet{
	int t,a;
}p[10010];
bool cmp(planet x,planet y){
	if( x.a>y.a || (x.t==y.t && x.t>y.t) ) return 1;
	else return 0; 
}
double ans = 0;
int main(){
	freopen("exploit.in","r",stdin);
	freopen("exploit.out","w",stdout);
	int n;
	double w,k,c;
	scanf("%d%lf%lf%lf",&n,&k,&c,&w);
	k = ((double)1-0.01*(double)k);
	c = ((double)1+0.01*(double)c);
	for(int i=1;i<=n;i++) cin>>p[i].t>>p[i].a;
	sort(p+1,p+1+n,cmp);
	for(int i=n;i;i--)
        if(p[i].t==1){
        	if(ans<ans*k+p[i].a) ans = ans*k+p[i].a;
		}else{
        	if(ans<ans*c-p[i].a) ans = ans*c-p[i].a;
		}
    printf("%.2lf\n",ans*w);
	
	return 0;
}