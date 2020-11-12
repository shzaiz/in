
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const int SIZEN=200010;
class Point{
public:
	LL x,y;
	double ang;
};
bool cmp(const Point &a,const Point &b){
	return a.ang<b.ang;
}
LL cross(const Point &a,const Point &b){
	return a.x*b.y-b.x*a.y;
}
int N;
Point P[SIZEN];
void work(void){
	sort(P+1,P+1+N,cmp);
	for(int i=1;i<=N;i++) P[N+i]=P[i];
	LL ans=(LL)N*(N-1)*(N-2)/6;
	for(int i=1,j=1;i<=N;i++){
		while(j<i+N&&cross(P[i],P[j])>=0) j++;
		LL k=j-i-1;
		ans-=k*(k-1)/2;
	}
	printf("%lld\n",ans);
}
void read(void){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%lld%lld",&P[i].x,&P[i].y);
		P[i].ang=atan2(P[i].y+0.0,P[i].x+0.0);
	}
}
int main(){
	freopen("tricount.in","r",stdin);
	freopen("baoli.out","w",stdout);
	read();
	work();
	return 0;
}

