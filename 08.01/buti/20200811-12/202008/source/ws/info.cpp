//�ӵ㣺�ֿ�����ߵ��˱��ұߵ������Ҵ����ĸ��࣬��֮Ҳ�п��� 
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
	for(int i=1;i<=n;i++){//�ӵ�i���˴��� 
		bool L=false,R=false;
		int startl=i,startr=i;//��ôת��ͷ�ӿ�ʼ����i
		int endl,endr;
		int tim=0;
		while(L==false||R==false){//������û����������ұ�û�����꣬�ͼ������� 
			int x1=a[startl].li,x2=a[startr].ri;//������ͷ�������ܴ���������
			int max1=0,max2=0;//�����ȽϿ�˭�����Ķ� 1Ϊ��2Ϊ�� 
			for(int j=1;j<=x1;j++){//���󴫲� 
				int now1=startl;//��������ڴ���˭ 
				now1--;
				if(now1==0){
				now1=n;//ʵ�ʴ������ǵ�n����
				L=true;//����������
				}
				if(a[now1].li>=max1){
					max1=a[now1].li;//��˭�����Ķ࣬�͸���˭����������·�� 
					endl=now1;
				}
				if(a[now1].ri>=max2){
					max2=a[now1].ri;
					endr=now1;
				}		
			}
			for(int j=1;j<=x2;j++){//���Ҵ��� 
				int now2=startr;
				now2++;
				if(now2==n+1){
					now2=1;//ʵ���ϴ������ǵ�1����
					R=true;//�ұ�������� 
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
