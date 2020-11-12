#include <bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	int T = rand()%100;
	freopen("tricount.in","w",stdout);
	cout<<T<<endl;
	while(T--){
		int x = rand()%20000-1000,y=rand()%20000-1000;
		cout<<x<<" "<<y<<endl;
	}
} 
