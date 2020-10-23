#include<bits/stdc++.h>

using namespace std;

const int N=1e7+7;

int n,pos[N];

int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
    scanf("%d",&n);
    int tmp=0;
    for(int i=1;;i++){
        tmp=(tmp*10+1)%n;
        if(!tmp){
            for(int j=1;j<=i;j++){
                putchar('1');
            }
            putchar('\n');
            return 0;
        }
        if(pos[tmp]){
            for(int j=i-pos[tmp];j>0;j--){
                putchar('1');
            }
            for(int j=pos[tmp];j>0;j--){
                putchar('0');
            }
            putchar('\n');
            return 0;
        }
        pos[tmp]=i;
    }
    return 0;
}