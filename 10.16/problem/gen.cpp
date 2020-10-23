#include <bits/stdc++.h>
#include <string.h>
#include <windows.h>
#define int long long
using namespace std;

signed main(){
	 for(int i = 10;i<=20;i++){
	 	srand((unsigned)time(0));
        freopen((to_string(i)+".in").c_str(),"w",stdout);
		srand((unsigned)time(0));
       	int T = rand()%5+195;
        cout<<T<<endl;
		for(int i = 1;i<=T;i++){
			int n = rand()%2000+1999990000;
			cout<<n<<"\n";
		}
        fclose(stdout);
       Sleep(1000);
	 }
    return 0;
}
