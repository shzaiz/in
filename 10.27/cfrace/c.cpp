#include <bits/stdc++.h>
using namespace std;
int b[205];
int vis[205];
void solve(){
int n;cin>>n;
    for(int i = 1;i<=n;i++){
        int x;cin>>x;
        b[x]++;
    }
    int ans = 0;
    for(int i = 1;i<205;i++){
         printf("Exam %d\n",i);
        if(b[i]!=0){
            int l = i-(b[i]/2);
            if(l<=0) l = 1;
            for(int j = l,cnt = 0; cnt<b[i];j++){
                if(!vis[j]){
                     printf("Put on %d with Δt = %d\n",j,(i-j));
                    cnt++; vis[j] =1; ans+= abs(i-j);
                } 
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int T;cin>>T; while(T--){
        memset(b,0,sizeof b);
        memset(vis,0,sizeof vis);
        solve();
    }
}