#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define int long long
#define D long double
int F(int x){
    if(x%2==0){
        return pow(4,x)+pow(4,x/2);
    }else{
        return pow(4,x)/2;
    }
}
int M(int x){
    if(x%2) return 0;
    else {
        D tmp = pow(4,x/2)*(x/4);
        for(int k = 2;k<=sqrt(x/2);k++){
            if(x%k==0) tmp-= pow(4,x/(2*k))*(k/2);
        }
        return tmp;
    }
    
}
int n(int y){
    if(y==1) return 2;
    else{
        
    }
}
int main(){

}