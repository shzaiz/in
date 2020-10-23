#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int a[4][4],b[4][4];
int n;
#define mod 1000000007
void mul(int a[4][4],int b[4][4],int ans[4][4]){
     int tmp[4][4];
     for(int i=1;i<=3;i++)
         for(int j=1;j<=3;j++){
             tmp[i][j]=0;
             for(int k=1;k<=3;k++)
                 tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j])%mod;
         }
     for(int i=1;i<=3;i++)
         for(int j=1;j<=3;j++)
             ans[i][j]=tmp[i][j];
}
void qpow(int n){
	while(n){
        if(n%2!=0)mul(a,b,a);
        mul(b,b,b);
        n/=2;        
    }
}
signed main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
    cin>>T;
    for(int l=1;l<=T;l++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        a[1][1]=a[2][2]=a[3][3]=1;
        b[1][3]=b[2][1]=b[3][2]=b[3][3]=1;
        cin>>n;n--;
        qpow(n);
        int ans=0;
        for(int i=1;i<=3;i++)
            ans=(ans+a[i][1])%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
