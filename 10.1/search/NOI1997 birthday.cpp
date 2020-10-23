#include <bits/stdc++.h>
using namespace std;
int fans = 998244353;
#define N 100010
int n,m;
int s[N];int cnt = 0;
void dfs(int left,int r,int h,int x,int nans){
    
    if(x>m+1) return;
    if(left == 0 && x== m+1){
        // printf("%d,%d\n",nans,s[1]);
        if(nans+s[1]*s[1]<=fans){
            // printf("%d\n",s[2]);
            fans = nans+s[1]*s[1];
        }
    }
    for(int rp = r-1; rp >0;rp--){
        for(int hp = h-1; hp >0;hp--){
            if((left - rp*rp*hp)<0) continue;
            if(left>=(rp*rp*hp)*2 ) continue;
           if(nans+2*rp*hp>=fans-s[1]*s[1]) continue;
            if(nans>=fans) continue;
            else{
                s[++cnt] = rp;
                dfs((left-rp*rp*hp),rp,hp,x+1,nans+2*rp*hp);
                cnt--;
            }
        }
    }
}
int main(){
    
    freopen("10.1/search/wa.in","r",stdin);
    freopen("10.1/search/wa.out","w",stdout);
    cin>>n>>m;
    dfs(n,25,900,1,0);
    cout<<(fans==998244353 ? 0: fans);
    return 0;
}