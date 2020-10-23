#include<bits/stdc++.h>

using namespace std;

int a,b,p;

int t,k;

long long n;

long long gcd(long long u,long long v){
    if(!v){
        return u;
    }
    return gcd(v,u%v);
}

bool pr(int u){
    int lmt=sqrt(u);
    for(int i=2;i<=lmt;i++){
        if(u%i==0){
            return 0;
        }
    }
    return 1;
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

long long dec(long long u,long long v){
    return (((u-v)%p)+p)%p;
}

long long sum;

char in[20],out[20];

int main(){
    for(int tt=1;tt<=50;tt++){
        printf("Now at case %d:\n",tt);
        sum=0;
        sprintf(in,"coin%d.in",tt);
        freopen(in,"r",stdin);
        scanf("%d%d%d",&a,&b,&p);
        if(gcd(a,b)>1){
            printf("Bad data of gcd(a,b)\n");
        }
        if(gcd(a,p)>1){
            printf("Bad data of gcd(a,p)\n");
        }
        if(gcd(b,p)>1){
            printf("Bad data of gcd(b,p)\n");
        }
        if(a<1){
            printf("Bad a\n");
        }
        else if(a>=b){
            printf("Bad a<b\n");
        }
        else if(b>=p){
            printf("Bad b<p\n");
        }
        else if(p>998244353){
            printf("Bad p\n");
        }
        if(gcd(1LL*a*inv(b),p)>1){
            printf("Bad gcd(abp)\n");
        }
        // cerr<<inv(2)<<"\n";
        // cerr<<dec(1,1LL*a*inv(b))<<"\n";
        // cerr<<1LL*a*inv(b)<<"\n";
        // cerr<<p<<"\n";
        // cerr<<gcd(dec(1,1LL*a*inv(b)),p)<<"\n";
        if(gcd(dec(1,1LL*a*inv(b)),p)>1){
            printf("Bad gcd(fabp)\n");
        }
        if(gcd(dec(1LL*a*inv(b),1),p)>1){
            printf("Bad gcd(k-1)\n");
        }
        scanf("%d",&t);
        if(t<1||t>1e5){
            printf("Bad t\n");
        }
        while(t--){
            scanf("%lld",&n);
            sum+=n;
            if(n<0||n>1000000000000000000LL){
                printf("Bad n\n");
            }
        }
        if(tt<=10||(tt>=21&&tt<=30)){
            if(sum>1e7){
                printf("Bad sum\n");
            }
        }
        fclose(stdin);
    }   
    for(int tt=16;tt<=50;tt++){
        printf("Now at case %d(2a=b):\n",tt);
        sprintf(in,"coin%d.in",tt);
        freopen(in,"r",stdin);
        scanf("%d%d%d",&a,&b,&p);
        if(2*a==b){
            printf("Bad sp\n");
        }
        fclose(stdin);
    }   
    return 0;
}