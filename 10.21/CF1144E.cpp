#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ull unsigned long long
#define fo(i,x,y) for(register int i=x;i<=y;++i)
#define go(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;
int main(){
	int n;
    cin >>n;
	ull sum=1;
	fo(i,n/2+1,n-1) sum*=i;
	fo(i,2,n/2-1) sum*=i;
	cout<<sum;
	return 0;
}