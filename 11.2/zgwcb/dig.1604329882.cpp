#include <bits/stdc++.h>
using namespace std;

#define N 200005
#define int long long
#define fo(i,x) for(int i = 1;i<=(x);i++)
#define D double
#define vi(m,x) for(int i = 1;i<=(x);i++) cout<<(m)[i]<<" ";
D n,d;
D dis[N],tim[N];
int cntd=0,cntt=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("D:\\Testcases\\in.ac","r",stdin);
	cin>>n>>d;
	
	fo(i,n){
		char a,b,c,d;int m=1000;cin>>a>>b>>c>>d;
		if(a=='T') tim[++cntt] = m;
		else dis[++cntd] = m;
	}
	sort(dis+1, dis+1+cntd,cmp);
	sort(tim+1, tim+1+cntt,cmp);
	//
	for(int i = 1;i<=cntt;i++) cout<<tim[i]<<" ";
	cout<<endl; 
	for(int i = 1;i<=cntd;i++) cout<<dis[i]<<" "; 
	cout<<endl; 
	//
	D mz = 1,t = 0,cur = 0;
	for(int i = 1;i<=n;i++){
		
		D stp = dis[cntd];
		D ttp = tim[cntt];
		D t1 = (stp-cur)*mz;
		if(cntt == 0){
			//
			printf("From stpp\n");
			//
			t +=(stp-cur)*mz ;
			cntd--;
			cur = stp;
			mz++;
			//
			cout<<mz<<" "<<t<<" "<<cur<<endl;
			//
			continue;
		}
		if(cntd == 0){
			//
			printf("From ttp\n");
			//
			mz++;
			cntt--;
			cur += (1/(mz-1))*ttp;
			t += ttp;
			//
			cout<<mz<<" "<<t<<" "<<cur<<endl;
//
			continue;
		}
		if(t1>ttp){
			printf("From ttp\n");
			mz++;
			cntt--;
			cur += (1/(mz-1))*ttp;
			t += ttp;
		}else if(t1==ttp){
			cur = stp;
			mz+=2;
			cntt-- , cntd--;
			t = ttp;
		}else if(t1<ttp){
			printf("From s\n");
			mz++;
			cntd--;
			t += t1;
			cur = stp;
		}
		cout<<mz<<" "<<t<<" "<<cur<<endl;
	}
	t += (d-cur)*mz;
	cout<<(int)t<<endl;
}
