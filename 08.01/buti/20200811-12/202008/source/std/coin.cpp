#include<bits/stdc++.h>

using namespace std;

int a,b,p;

int t,k;

long long n;

long long ans[3],base[3][3];

long long rep12[3],rep22[3][3];

long long plu(long long u,long long v){
    return (u+v)%p;
}

long long mul(long long u,long long v){
    return u*v%p;
}

void exgcd(int u,int v,int &x,int &y){
    if(v==0){
        x=1;y=0;
        return;
    }
    exgcd(v,u%v,y,x);
    y-=u/v*x;
}

int inv(int u){
    int x,y;
    exgcd(u,p,x,y);
    return ((x%p)+p)%p;
}

void mtxinit(){
    ans[1]=0;ans[2]=1;
    base[1][1]=base[2][1]=k;
    base[1][2]=0;base[2][2]=1;
}

void mtxmula(){
    memset(rep12,0,sizeof rep12);
    for(int i=1;i<3;i++){
        for(int j=1;j<3;j++){
            rep12[i]=plu(rep12[i],mul(ans[j],base[j][i]));
        }
    }
    for(int i=1;i<3;i++){
        ans[i]=rep12[i];
    }
}

void mtxmulb(){
    memset(rep22,0,sizeof rep22);
    for(int i=1;i<3;i++){
        for(int j=1;j<3;j++){
            for(int k=1;k<3;k++){
                rep22[i][j]=plu(rep22[i][j],mul(base[i][k],base[k][j]));
            }
        }
    }
    for(int i=1;i<3;i++){
        for(int j=1;j<3;j++){
            base[i][j]=rep22[i][j];
        }
    }
}

void mtxqpow(long long v){
    while(v>0){
        if(v&1){
            mtxmula();
        }
        mtxmulb();
        v>>=1;
    }
}

int solve(long long u){
    mtxinit();
    mtxqpow(u);
    return ans[1];
}

int main(){
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d%d%d",&a,&b,&p);
    k=mul(b,inv(a));
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        printf("%d\n",solve(n));
    }
    return 0;
}