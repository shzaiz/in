#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

char in[20],out[20];

int RAND(int l,int r){
    return rand()%(r-l+1)+l;
}

long long RANDll(long long l,long long r){
    return 1LL*rand()*rand()%(r-l+1)+l;
}

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

int lcm(int u,int v){
    return u*v/gcd(u,v);
}

int a,b,p,t;

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

long long n;

int main(){
    srand(time(NULL));
    // for(int tt=1;tt<=7;tt++){
    //     sprintf(in,"coin%d.in",tt);
    //     freopen(in,"w",stdout);
    //     a=1;b=2;p=998244353;int lft=1e7;
    //     printf("%d %d %d\n",a,b,p);
    //     t=RAND(1,1e5);
    //     printf("%d\n",t);
    //     for(int i=1;i<=t;i++){
    //         n=RAND(0,int((int)lft/(t+1-i)));
    //         lft-=n;
    //         printf("%lld\n",n);
    //     }
    //     fclose(stdout);
    // }
    // for(int tt=8;tt<=10;tt++){
    //     sprintf(in,"coin%d.in",tt);
    //     freopen(in,"w",stdout);
    //     a=1;b=2;p=RAND(1,998244353)|1;int lft=1e7;
    //     if(p%3==1){
    //         p+=2;
    //     }
    //     if(p%3==2){
    //         p+=4;
    //     }
    //     printf("%d %d %d\n",a,b,p);
    //     t=RAND(1,1e5);
    //     printf("%d\n",t);
    //     for(int i=1;i<=t;i++){
    //         n=RAND(0,int((int)lft/(t+1-i)));
    //         lft-=n;
    //         printf("%lld\n",n);
    //     }
    //     fclose(stdout);
    // }
    // for(int tt=11;tt<=15;tt++){
    //     sprintf(in,"coin%d.in",tt);
    //     freopen(in,"w",stdout);
    //     a=1;b=2;p=RAND(1,998244353)|1;
    //     if(p%3==1){
    //         p+=2;
    //     }
    //     if(p%3==2){
    //         p+=4;
    //     }
    //     printf("%d %d %d\n",a,b,p);
    //     t=RAND(8e4,1e5);
    //     printf("%d\n",t);
    //     for(int i=1;i<=t;i++){
    //         n=RANDll(1000000000000000LL,1000000000000000000LL);
    //         printf("%lld\n",n);
    //     }
    //     fclose(stdout);
    // }
    // for(int tt=16;tt<=20;tt++){
    //     sprintf(in,"coin%d.in",tt);
    //     freopen(in,"w",stdout);
    //     a=RAND(1,1e6);b=RAND(a+1,998244352);p=998244353;
    //     int g=gcd(a,b);
    //     a/=g;b/=g;
    //     printf("%d %d %d\n",a,b,p);
    //     t=RAND(8e4,1e5);
    //     printf("%d\n",t);
    //     for(int i=1;i<=t;i++){
    //         n=RANDll(1000000000000000LL,1000000000000000000LL);
    //         printf("%lld\n",n);
    //     }
    //     fclose(stdout);
    // }
    // for(int tt=21;tt<=23;tt++){
    //     sprintf(in,"coin%d.in",tt);
    //     freopen(in,"w",stdout);
    //     a=RAND(1,1e6);b=RAND(a+1,998244352);p=998244353;int lft=1e7;
    //     int g=gcd(a,b);
    //     a/=g;b/=g;
    //     printf("%d %d %d\n",a,b,p);
    //     t=RAND(1,1e5);
    //     printf("%d\n",t);
    //     for(int i=1;i<=t;i++){
    //         n=RAND(0,int((int)lft/(t+1-i)));
    //         lft-=n;
    //         printf("%lld\n",n);
    //     }
    //     fclose(stdout);
    // }
    for(int tt=24;tt<=30;tt++){
        cerr<<"case:"<<tt<<"\n";
        sprintf(in,"coin%d.in",tt);
        freopen(in,"w",stdout);
        a=RAND(1,2e4);b=RAND(a+1,4e4);int lft=1e7;
        int g=gcd(a,b);
        a/=g;b/=g;
        p=a*b+1;
        int lc=lcm(a,b);
        while(pr(p)&&p<998244352-lc){
            p+=lc;
        }
        g=gcd(1LL*a*inv(b),p);
        cerr<<a<<" "<<b<<" "<<p<<"\n";
        cerr<<1LL*a*inv(b)<<"\n";
        cerr<<gcd(1LL*a*inv(b),p)<<"\n";
        while(g>1){
            if(gcd(g,a)==1){
                break;
            }
            a/=gcd(g,a);
            g=gcd(a*inv(b),p);
        }
        printf("%d %d %d\n",a,b,p);
        t=RAND(1,1e5);
        printf("%d\n",t);
        for(int i=1;i<=t;i++){
            n=RAND(0,int((int)lft/(t+1-i)));
            lft-=n;
            printf("%lld\n",n);
        }
        fclose(stdout);
    }
    for(int tt=31;tt<=50;tt++){
        cerr<<"case:"<<tt<<"\n";
        printf("at %d:\n",tt);
        sprintf(in,"coin%d.in",tt);
        freopen(in,"w",stdout);
        a=RAND(1,2e4);b=RAND(a+1,4e4);
        int g=gcd(a,b);
        a/=g;b/=g;
        p=a*b+1;
        int lc=lcm(a,b);
        while(pr(p)&&p<998244352-lc){
            p+=lc;
        }
        g=gcd(1LL*a*inv(b),p);
        cerr<<a<<" "<<b<<" "<<p<<"\n";
        cerr<<1LL*a*inv(b)<<"\n";
        cerr<<gcd(1LL*a*inv(b),p)<<"\n";
        while(g>1){
            if(gcd(g,a)==1){
                break;
            }
            a/=gcd(g,a);
            g=gcd(a*inv(b),p);
        }
        printf("%d %d %d\n",a,b,p);
        t=RAND(99e3,1e5);
        printf("%d\n",t);
        for(int i=1;i<=t;i++){
            n=RANDll(900000000000000000LL,1000000000000000000LL);
            printf("%lld\n",n);
        }
        fclose(stdout);
    }
    return 0;
}