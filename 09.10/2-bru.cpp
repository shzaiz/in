#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
#define mod 1000000007
using namespace std;
int T;
int a[4][4],b[4][4];
int n;


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
        if(n&1)mul(a,b,a);
        mul(b,b,b);
        n>>=1;        
    }
}
signed main(){
    cin>>T;
    for(int l=1;l<=T;l++){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=3;i++)a[i][i]=1;
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