#include <bits/stdc++.h>
#define N 100010
using namespace std;
int pr[N],cnt,phi[N],low[N];
void shai(int n) {
    for(int i = 2;i<=n;i++){
        if(low[i] == 0){
            phi[i] = i-1;
            pr[++cnt] = i;
            low[i] = i;
        }else{
            for(int j = 1;j<=cnt && i*pr[j]<=n;j++){
                low[i*pr[j]] = low[pr[j]];
                if(i%pr[j] == 0){
                        phi[i*pr[j]] = phi[i]*pr[j];
                    }else{
                        phi[i*pr[j]] = phi[i]*phi[pr[j]];
                }
            }
        }
    }
}
int main(){

}