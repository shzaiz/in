#include <bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(b==0) {
        x = 1,y = 0;
        return a;
    }else{
        int n = exgcd(b,a%b,y,x);
        y -= n*(a/b);
    }
}
int main(){
    
}