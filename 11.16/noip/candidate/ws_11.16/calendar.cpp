#include<bits/stdc++.h>
using namespace std;
int yue[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool ans[2015][15][35];
bool cmp[2015][15][35];//判断是否已经算过这个数了 
bool run(int x){
	if(x==2000)
		return true;
	else if(x%100==0)
		return false;
	else if(x%4==0)
		return true;
	else
		return false;
}
bool zhuanyi(int a,int b,int c){
	if(a==2012&&b==12&&c==22){
		ans[a][b][c]=false;
		cmp[a][b][c]=true;
		return false;
	}
	if(cmp[a][b][c])
	return ans[a][b][c];
	
	int w=false;
	if(a==2012&&b==12&&c>22)
	w=true;
	if(a>2012)
	w=true;
	if(w==true){
		ans[a][b][c]=true;
		cmp[a][b][c]=true;
		return true;
	}
	int i=a,j=b,k=c+1;//判断年月日，就是处理进位
	int num=yue[j];
	if(j==2)
		if(run(i))
			num++;
	if(k>num){
		k-=num;
		j++;
	}
	if(j>12){
		i++;
		j=1;
	}
	
	if(zhuanyi(i,j,k)==false){
		ans[a][b][c]=true;
		cmp[a][b][c]=true;
		return true;
	}
	 i=a,j=b+1,k=c;
	if(j>12){
		j=1;
		i++;
	}
	int sum=yue[j];
	if(j==2)
		if(run(i))
			sum++;
	if(k>sum){
		a=2013;//直接赋值为2013
	}
	if(zhuanyi(i,j,k)==false){
		ans[a][b][c]=true;
		cmp[a][b][c]=true;
		return true;
	} 
	ans[a][b][c]=false;
	cmp[a][b][c]=true;
	return false;
}
int main(){
	freopen("calendar.in","r",stdin);
	freopen("calendar.out","w",stdout);
	int y,m,d;
	while(cin>>y>>m>>d){
		if(!zhuanyi(y,m,d))
		cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
	}
	return 0;
}
