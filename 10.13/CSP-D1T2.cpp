#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n;
string str;
int judge(int l,int r){
    char q[N],tp = 0;
    for(int i = l; i <= r;i++){
        q[++tp] = str[i];
        if(q[tp] == ')'){
            if(q[tp-1]=='('){
                tp-=2;
            }
        }
    }
    if(tp==0) return 1;
    else return 0;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
    #endif
    
    cin>>n>>str;
    int ans = 0;
    for(int i = 0;i<=n;i++){// End place
        int ans2 = 0;
        for(int a = 0;a<i;a++){ 
            for(int b = a;b<i;b++){
                // printf("%d %d = %d\n",a,b,judge(a,b));
                if(judge(a,b)) ans2++;
            }
        }
        // cout<<ans2*i<<endl;
        ans = ans xor (ans2*(i));
    }
    printf("%d\n",ans);
    
}