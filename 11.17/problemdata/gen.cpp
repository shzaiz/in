#include <bits/stdc++.h>
#include <string.h>
//9982433
using namespace std;
// 写成函数, 方便分点测试 
void sub1(){ 
// rand()生成一个[0,int_max]的随机数, 通过取模指定范围. 
	int n = rand()%50+495000,h = rand()%10+40;
	cout<<n<<" "<<h<<endl;
	for(int i = 1;i<=n;i++){
		cout<<rand()%100000+1<<" ";
	}
	printf("\n");
	
	
} 
int main(){
	srand(time(NULL)); // 随机种子 
	for(int i = 1;i<=20;i++){
        freopen((to_string(i)+".in").c_str(),"w",stdout);
        sub1();
        fclose(stdin);
        fclose(stdout);
        cin.clear();cout.clear();
	}
    return 0;
}
