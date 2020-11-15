
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
 
struct huo{
	int s;
	int f;
}a[10010];
 
int cmp(huo a, huo b){
	return a.f < b.f;
}
 
int main(){
	int i, j=0, n;
	int count=1;
	
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
	cin>>n;
	for(i=0; i<n; i++)
		cin>>a[i].s>>a[i].f;
	sort(a,a+n,cmp);
 
	for(i=1; i<n; i++){
		if(a[i].s>=a[j].f){
			j=i;
			count++;
		}
	}
 
	cout<<count<<endl;
}