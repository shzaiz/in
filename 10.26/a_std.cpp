
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,arr[1010],bin[40],res[40];
inline int read(){
    int s=0;
    char ch=getchar();
    while('9'<ch||ch<'0'){
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        s=(s<<3)+(s<<1)+ch-'0';
        ch=getchar(); 
    }
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    #endif
    bin[0]=1;
    for(register int i=1;i<=30;++i){
        bin[i]=bin[i-1]<<1;
    }
    while(scanf("%d",&n)==1){
        memset(res,0,sizeof(res));
        for(register int i=1;i<=n;++i){
            arr[i]=read();
            int pos=upper_bound(bin,bin+31,arr[i])-bin;
            res[pos]++;
        } 
        int ans=0;
        for(register int i=0;i<=30;++i){
            ans=max(ans,res[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}