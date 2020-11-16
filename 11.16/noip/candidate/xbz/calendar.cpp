#include<bits/stdc++.h>
#define fint register int
#define H 5001
#define N 1000001
using namespace std;
int a,b,c;
string ans[2]={"NO","YES"};
int Months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},sg[2014][14][34];
inline int runs(int x,int y);
inline void SG_day();
inline void SG_month();
int SG_pre(int y,int m,int d);
int main()
{
	freopen("calendar.in","r",stdin);
  	freopen("calendar.out","w",stdout);
    memset(sg,-1,sizeof(sg));
    SG_pre(1900,1,1);
	int Y,M,D;
	while(cin>>Y>>M>>D)
	cout<<ans[sg[Y][M][D]]<<endl;
	return 0;
}

inline int runs(int x,int y)
{
	if(y!=2)
	return 0;
	if(x==2000)
	return 1;
	if(x==1900)
	return 0;
	if(x%4==0)
	return 1;
	return 0;
}

int SG_pre(int y,int m,int d)
{
	if(y==2012&&m==12&&d==22)
	return sg[y][m][d]=0;
	if(sg[y][m][d]!=-1)
	return sg[y][m][d];
	if(y>2012||(y==2012&&m==12&&d>22))
	return sg[y][m][d]=1;
	a=y,b=m,c=d;
	SG_day();
	if(!SG_pre(a,b,c))
	return sg[y][m][d]=1;
	a=y,b=m,c=d;
	SG_month();
	if(!SG_pre(a,b,c))
	return sg[y][m][d]=1;
	return sg[y][m][d]=0;
}

inline void SG_day()
{
	c++;
	if(c>Months[b]+runs(a,b))
	c=1,b++;
	if(b>12)
	b=1,a++;
	return ;
}

inline void SG_month()
{
	b++;
	if(b>12)
	a++,b=1;
	if(c>Months[b]+runs(a,b))//没有这一天 就不能这么干 
	a=2012,b=12,c=25;
	return ;
}
