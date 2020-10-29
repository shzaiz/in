#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    printf("%.0lf\n",floor(log(n)/log(k))+1);
    return 0;
}