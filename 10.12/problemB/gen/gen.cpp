#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main(){
	 for(int i = 0;i<100;i++){
		 char as[100];
		 itoa(i,as,10);
		 as[strlen(as)]='.';
		 as[strlen(as)+1]='i';
		 as[strlen(as)+2]='n';
		freopen((as),"w",stdout);
		srand((unsigned)time(0));
       	int T = rand()%4+1;
        cout<<T<<endl;
		for(int i = 1;i<=T;i++){
			int n = rand()%100+2;
			int k = rand()%100000000+2;
			int max = -1;
			cout<<n<<" "<<k<<"\n";
			for(int i=1;i<=n;i++){
				cout<<i<<" ";
				
			}
			cout<<"\n";
		}
        fclose(stdout);
       
       
	 }
    return 0;
}
