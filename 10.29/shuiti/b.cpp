#include<iostream>
using namespace std;
int n;
double ok=0;
struct ans{
	int xh,a1,a2;
}a[1010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].xh>>a[i].a1>>a[i].a2;
		ok=a[i].a1*0.7+a[i].a2*0.3;
		if(ok>80&&a[i].a1+a[i].a2>140){
			cout<<"Excellent"<<endl;
		}else{
			cout<<"Not excellent"<<endl;
		}
	}
	return 0;
}