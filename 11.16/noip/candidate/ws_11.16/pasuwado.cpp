#include<bits/stdc++.h>
using namespace std;
string s;
int a[3005];
int sum;
int main(){
	freopen("pasuwado.in","r",stdin);
	freopen("pasuwado.out","w",stdout);
	int k;
	cin>>k;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		a[i+1]=s[i]-'a';
	}
	for(int i=1;i<=l-1;i++){
    	for(int j=1;j<=l-i;j++){
        	if(a[j]>a[j+1]){
            	swap(a[j],a[j+1]);
            	sum++;
        	}
        	if(sum==k)
        	break;
    	}
    	if(sum==k)
    	break;
	}
	for(int i=1;i<=l;i++)
	cout<<(char)(a[i]+'a');
}
