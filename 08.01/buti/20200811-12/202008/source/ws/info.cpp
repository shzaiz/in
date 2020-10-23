//坑点：又可能左边的人比右边的人向右传播的更多，反之也有可能 
#include<bits/stdc++.h>
using namespace std;
struct xxx{
	int i,li,ri;
}a[100005];
int n;
int main(){
	freopen("info.in","r",stdin);
	freopen("info.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].li;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].ri;
	}
	for(int i=1;i<=n;i++){//从第i个人传播 
		bool L=false,R=false;
		int startl=i,startr=i;//那么转播头子开始就是i
		int endl,endr;
		int tim=0;
		while(L==false||R==false){//如果左边没传播完或者右边没传播完，就继续传播 
			int x1=a[startl].li,x2=a[startr].ri;//看传播头子左右能传播几个人
			int max1=0,max2=0;//用来比较看谁传播的多 1为左，2为右 
			for(int j=1;j<=x1;j++){//向左传播 
				int now1=startl;//左边现在在传播谁 
				now1--;
				if(now1==0){
				now1=n;//实际传播的是第n个人
				L=true;//左边任务完成
				}
				if(a[now1].li>=max1){
					max1=a[now1].li;//看谁传播的多，就跟踪谁继续传播的路径 
					endl=now1;
				}
				if(a[now1].ri>=max2){
					max2=a[now1].ri;
					endr=now1;
				}		
			}
			for(int j=1;j<=x2;j++){//向右传播 
				int now2=startr;
				now2++;
				if(now2==n+1){
					now2=1;//实际上传播的是第1个人
					R=true;//右边任务完成 
					if(L==true){
						break;
					}
				}
				if(a[now2].ri>=max2){
					max2=a[now2].ri;
					endr=now2;
				}
				if(a[now2].li>=max1){
					max1=a[now2].li;
					endl=now2;
				}
				
			} 
		 
		 tim++;	
		 if(L==true&&R==true)
		 break;	 
	}
	cout<<tim<<" ";
	
}
return 0;
}
