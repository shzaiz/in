#include<bits/stdc++.h>

using namespace std;

const int N=1e6+6;

int t,n,m,p,d;

long long x,a[N],b[N],suma,sumb,ans;

long long qpow(long long u,int v){
    long long rep=1;
    while(v>0){
        if(v&1){
            rep=(rep*u)%p;
        }
        u=(u*u)%p;
        v>>=1;
    }
    return rep;
}

int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%lld%d",&n,&m,&x,&p);
        suma=0;sumb=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            suma^=a[i];
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&b[i]);
            sumb^=b[i];
        }
        if(suma!=sumb){
            printf("0\n");
            continue;
        }
        ++x;
        x%=p;
        ans=qpow(x,n-1);
        ans=qpow(ans,m-1);
        printf("%lld\n",ans);
    }
    return 0;
}
