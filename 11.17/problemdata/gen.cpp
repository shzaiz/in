#include <bits/stdc++.h>
#include <string.h>
//9982433
using namespace std;
void sub1(){
	int n = rand()%50+4950,h = rand()%10+40;
	cout<<n<<" "<<h<<endl;
	for(int i = 1;i<=n;i++){
		cout<<rand()%100000+1<<" ";
	}
	printf("\n");
	
	
} 

void sub2(){
	int n = rand()%1000+1,h = rand()%1000+1;
	cout<<n<<" "<<h<<endl;
	for(int i = 1;i<=n;i++){
		bool ak = rand()%3;
		int prev = rand()%h+1;
		if(ak==1){
			int x = rand()%h+1;
			cout<<x<<" ";
			prev = x;
		}else if(ak==0){
			cout<<0<<" ";
		}else {
			cout<<prev<<" ";
		}
		
	}
	printf("\n");
	for(int i = 1;i<n;i++){
		cout<<i<<" ";
	}
}

void sub3(){
	int n = rand()%1000+99000,h = rand()%1000+99000;
	cout<<n<<" "<<h<<endl;
	for(int i = 1;i<=n;i++){
		bool ak = rand()%3;
		int prev = rand()%h+1;
		if(ak==1){
			int x = rand()%h+1;
			cout<<x<<" ";
			prev = x;
		}else if(ak==0){
			cout<<0<<" ";
		}else {
			cout<<prev<<" ";
		}
		
	}
	printf("\n");
	for(int i = 1;i<n;i++){
		cout<<rand()%i+1<<" ";
	}
}

int main(){
	srand(time(NULL));
//	for(int i = 1;i<=2;i++){
//        freopen((to_string(i)+".in").c_str(),"w",stdout);
//        sub1();
//        fclose(stdin);
//        fclose(stdout);
//        cin.clear();cout.clear();
//	}
	for(int i = 1;i<=20;i++){
        freopen((to_string(i)+".in").c_str(),"w",stdout);
        sub1();
        fclose(stdin);
        fclose(stdout);
        cin.clear();cout.clear();
	}
//	for(int i = 11;i<=20;i++){
//        freopen((to_string(i)+".in").c_str(),"w",stdout);
//        sub3();
//        fclose(stdin);
//        fclose(stdout);
//        cin.clear();cout.clear();
//	}
    return 0;
}
