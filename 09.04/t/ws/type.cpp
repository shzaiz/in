#include<bits/stdc++.h>
using namespace std;
struct xxx{
	char x1;
	char x2;
}a[100005];
char xx[100005];
char yy[100005];
char ques[100005];
int main(){
	freopen("type.in","r",stdin);
	freopen("type.out","w",stdout);
	int n;
	cin>>n;
	//int num=0;//记录输出的个数 
	for(int i=1;i<=n;i++){
		cin>>xx[i]>>yy[i];
	}
	for(int i=1;i<=n;i++){
		if(xx[i]=='T'){		
			a[i].x1='T';
			a[i].x2=yy[i];
		}
		else if(xx[i]=='U'){
			int numx;
			numx=yy[i]-'0';
			for(int j=i;j>=i-numx;){
				if(a[j].x1=='T'){
					a[j].x1='N';
					j--;
				}
			}
		}
		else if(xx[i]=='Q'){
			int numq;
			numq=yy[i]-'0';
			int num2=0;
			for(int j=1;;j++){
				if(num2==numq){
					ques[i]=a[j].x2;
				//	cout<<a[j].x2<<endl;
					break;
				}
				if(a[j].x1!='N'){
					num2++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].x1=='T')
		cout<<a[i].x2<<endl;
		else if(a[i].x1=='Q'){
			cout<<ques[i]<<endl;
		}
	}
	return 0;
}
