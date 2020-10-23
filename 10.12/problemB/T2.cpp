#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define N 100005
#define D long double
#define eps 1e-9
D n1[N],n2[N];
int p1=0,p2=0;
int solve(){
	int n;D k;
	cin>>n>>k;
	n1[1] = 0; n1[n+2] = k;
	n2[1] = k; n2[n+2] = 0;
	for(int i = 2;i<=n+1;i++){
		int x;cin>>x;
		n1[i] = x;
		n2[n+3-i] = x;
	}
	p1 =1;p2 = 1;
	D x1 = 0,x2 = k,v1 = 0,v2 = 0,t =0,a1=0,a2=0;
	while(n1[p1]<n2[p2]){
        D s1 = n1[p1]-x1;D s2 = x2-n2[p2];
		D t1 = (a1==0?((s1)/(v1==0?1:v1)):(-v1+sqrt(v1*v1+2*a1*s1)));
		D t2 = (a2==0?((s2)/(v2==0?1:v2)):(-v2+sqrt(v2*v1+2*a2*s2)));
      // cout<<t1<<"  "<<t2<<" "<<x1<<" "<<x2<<" "<<endl;
	//	printf("%lf %lf\n",t1,t2);
        if(fabs(t1-t2)<=eps) {
			// printf("Crash same t\n");
			x1 = n1[p1],x2 = n2[p2],t+=t1;
			p1++,p2++,v1=v1+a1*t1+1,v2=v2+a2*t2+1,a1++,a2++;
		}
		else if(t1>t2){
			// printf("Crash t2\n");
			x2 = n2[p2];x1 = x1+v1*t2+(0.5)*a1*t2*t2; t+=t2;
			v1= v1+a1*t2;v2 = v2+a2*t2;
			p2++,v2++,a2++;
		}
        else if(t1<t2){
			// printf("Crash t1\n");
			x1 = n1[p1],x2 = x2-v2*t1-(0.5)*a2*t1*t1,t+=t1;
			v1= v1+a1*t1;v2 = v2+a2*t1;
			p1++,v1++,a1++;
		}
        
	} 
//	printf(">out: %lf %lf %lf %lf\n",x1,x2,v1,v2);
    //cout<<t<<" "<<x1<<" "<<x2<<" "<<endl;
	D xl = x2-x1;
	D tt = (a1+a2==0)?xl/(v1+v2):((-v1-v2+sqrt((v1+v2)*(v1+v2)+2*xl*a1*a2))/(a1+a2));
	t += tt;
	cout<<fixed<<setprecision(0)<<t;
	return 0;
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
    #endif
	int T;cin>>T;
	while(T--){
		memset(n1,0,sizeof n1);
		memset(n2,0,sizeof n2);
		p1 = p2 = 0;
		solve();
		printf("\n");
	}
}