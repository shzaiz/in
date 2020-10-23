#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

char in[20],out[20];

int RAND(int l,int r){
    return rand()%(r-l+1)+l;
}

int n,k,m;

int a[N];

int main(){
    srand(time(NULL));
    // for(int tt=1;tt<=2;tt++){
    //     sprintf(in,"color%d.in",tt);
    //     freopen(in,"w",stdout);
    //     n=20;k=4;m=0;
    //     printf("%d %d %d\n",n,k,m);
    //     for(int i=1;i<=n;i++){
    //         a[i]=RAND(1,k);
    //     }
    //     for(int i=1;i<=10;i++){
    //         a[RAND(1,n)]=0;
    //     }
    //     for(int i=1;i<=n;i++){
    //         printf("%d%c",a[i]," \n"[i==n]);
    //     }
    //     fclose(stdout);
    // }
    // for(int tt=3;tt<=3;tt++){
    //     sprintf(in,"color%d.in",tt);
    //     freopen(in,"w",stdout);
    //     n=1000;k=RAND(900,1000);m=0;
    //     printf("%d %d %d\n",n,k,m);
    //     for(int i=2;i<=n;i++){
    //         a[i]=0;
    //     }
    //     a[1]=RAND(1,k);
    //     for(int i=1;i<=n;i++){
    //         printf("%d%c",a[i]," \n"[i==n]);
    //     }
    //     fclose(stdout);
    // }
    // for(int tt=4;tt<=4;tt++){
    //     sprintf(in,"color%d.in",tt);
    //     freopen(in,"w",stdout);
    //     n=1000;k=RAND(900,1000);m=0;
    //     printf("%d %d %d\n",n,k,m);
    //     for(int i=2;i<n;i++){
    //         a[i]=0;
    //     }
    //     a[1]=a[n]=RAND(1,k);
    //     for(int i=1;i<=n;i++){
    //         printf("%d%c",a[i]," \n"[i==n]);
    //     }
    //     fclose(stdout);
    // }
    // for(int tt=5;tt<=5;tt++){
    //     sprintf(in,"color%d.in",tt);
    //     freopen(in,"w",stdout);
    //     n=1000;k=RAND(900,1000);m=0;
    //     printf("%d %d %d\n",n,k,m);
    //     for(int i=2;i<n;i++){
    //         a[i]=0;
    //     }
    //     a[1]=RAND(1,k);
    //     a[n]=RAND(1,k);
    //     while(a[1]==a[n]){
    //         a[n]=RAND(1,k);
    //     }
    //     for(int i=1;i<=n;i++){
    //         printf("%d%c",a[i]," \n"[i==n]);
    //     }
    //     fclose(stdout);
    // }
    // for(int tt=6;tt<=7;tt++){
    //     sprintf(in,"color%d.in",tt);
    //     freopen(in,"w",stdout);
    //     n=2e5;k=RAND(19e4,2e5);m=0;
    //     printf("%d %d %d\n",n,k,m);
    //     for(int i=1;i<=n;i++){
    //         a[i]=RAND(1,k);
    //     }
    //     for(int i=1;i<=18e4;i++){
    //         a[RAND(1,n)]=0;
    //     }
    //     for(int i=1;i<=n;i++){
    //         printf("%d%c",a[i]," \n"[i==n]);
    //     }
    //     fclose(stdout);
    // }
    // for(int tt=8;tt<=11;tt++){
    //     sprintf(in,"color%d.in",tt);
    //     freopen(in,"w",stdout);
    //     n=20;k=4;m=1;
    //     printf("%d %d %d\n",n,k,m);
    //     for(int i=1;i<=n;i++){
    //         a[i]=RAND(1,k);
    //     }
    //     for(int i=1;i<=10;i++){
    //         a[RAND(1,n)]=0;
    //     }
    //     for(int i=1;i<=n;i++){
    //         printf("%d%c",a[i]," \n"[i==n]);
    //     }
    //     fclose(stdout);
    // }
    // for(int tt=12;tt<=14;tt++){
    //     sprintf(in,"color%d.in",tt);
    //     freopen(in,"w",stdout);
    //     n=1000;k=RAND(900,1000);m=1;
    //     printf("%d %d %d\n",n,k,m);
    //     for(int i=1;i<=n;i++){
    //         a[i]=RAND(1,k);
    //     }
    //     for(int i=1;i<=1300;i++){
    //         a[RAND(1,n)]=0;
    //     }
    //     for(int i=1;i<=n;i++){
    //         printf("%d%c",a[i]," \n"[i==n]);
    //     }
    //     fclose(stdout);
    // }
    for(int tt=15;tt<=17;tt++){
        sprintf(in,"color%d.in",tt);
        freopen(in,"w",stdout);
        n=2e5;k=RAND(19e4,2e5);m=1;
        printf("%d %d %d\n",n,k,m);
        for(int i=1;i<=n;i++){
            a[i]=RAND(1,k);
        }
        for(int i=1;i<=35e4;i++){
            a[RAND(1,n)]=0;
        }
        for(int i=1;i<=n;i++){
            printf("%d%c",a[i]," \n"[i==n]);
        }
        fclose(stdout);
    }
    // for(int tt=18;tt<=20;tt++){
    //     sprintf(in,"color%d.in",tt);
    //     freopen(in,"w",stdout);
    //     n=2e5;k=RAND(19e4,2e5);m=1;
    //     printf("%d %d %d\n",n,k,m);
    //     for(int i=1;i<=n;i++){
    //         a[i]=RAND(1,k);
    //     }
    //     for(int i=1;i<=48e4;i++){
    //         a[RAND(1,n)]=0;
    //     }
    //     for(int i=1e4;i<=18e4;i++){
    //         a[i]=0;
    //     }
    //     for(int i=1;i<=n;i++){
    //         printf("%d%c",a[i]," \n"[i==n]);
    //     }
    //     fclose(stdout);
    // }
    return 0;
}