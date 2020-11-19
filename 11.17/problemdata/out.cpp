#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main(){
	for(int i = 1;i<=20;i++){
        system(("std.exe < "+to_string(i)+".in >"+to_string(i)+".out").c_str());
        printf("Finished %d.\n",i);
        cin.clear();cout.clear();
	}
}
