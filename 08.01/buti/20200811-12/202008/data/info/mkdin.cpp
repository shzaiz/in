#include<bits/stdc++.h>

using namespace std;

const int N=1e6+6;

int n,a[N],b[N];

char in[20];

int tt;

int RAND(int l,int r){
    return rand()%(r-l+1)+l;
}

int main(){
//    for(int t=1;t<=6;t++){
//        sprintf(in,"c%d.in",t);
//        freopen(in,"w",stdout);
//        n=RAND(50,100);
//        printf("%d\n",n);
//        for(int i=1;i<=n;i++){
//            a[i]=RAND(1,n);
//            b[i]=RAND(1,n);
//        }
//        for(int i=1;i<=n;i++){
//            printf("%d%c",a[i]," \n"[i==n]);
//        }
//        for(int i=1;i<=n;i++){
//            printf("%d%c",b[i]," \n"[i==n]);
//        }
//        fclose(stdout);
//    }
//    for(int t=7;t<=12;t++){
//        sprintf(in,"c%d.in",t);
//        freopen(in,"w",stdout);
//        n=RAND(950,1000);
//        int qwq=RAND(80,93);
//        printf("%d\n",n);
//        for(int i=1;i<=n;i++){
//            a[i]=1;b[i]=1;
//            if(RAND(0,100)>=qwq){
//                a[i]=RAND(1,n);
//            }
//            else{
//                a[i]=RAND(1,10);
//            }
//            if(RAND(0,100)>=qwq){
//                b[i]=RAND(1,n);
//            }
//            else{
//                b[i]=RAND(1,10);
//            }
//            // a[i]=RAND(1,n);
//            // b[i]=RAND(1,n);
//        }
//        for(int i=1;i<=n;i++){
//            printf("%d%c",a[i]," \n"[i==n]);
//        }
//        for(int i=1;i<=n;i++){
//            printf("%d%c",b[i]," \n"[i==n]);
//        }
//        fclose(stdout);
//    }
//    for(int t=13;t<=14;t++){
//        sprintf(in,"c%d.in",t);
//        freopen(in,"w",stdout);
//        n=RAND((int)99e3,(int)1e5);
//        printf("%d\n",n);
//        int qwq=RAND(80,93);
//        for(int i=1;i<=n;i++){
//            a[i]=1;b[i]=1;
//            if(RAND(0,100)>=qwq){
//                a[i]=RAND(1,(n/3));
//            }
//            else{
//                a[i]=RAND(1,10);
//            }
//            if(RAND(0,100)>=qwq){
//                b[i]=RAND(1,(n/3));
//            }
//            else{
//                b[i]=RAND(1,10);
//            }
//            // a[i]=RAND(1,n);
//            // b[i]=RAND(1,n);
//        }
//        for(int i=1;i<=n;i++){
//            printf("%d%c",a[i]," \n"[i==n]);
//        }
//        for(int i=1;i<=n;i++){
//            printf("%d%c",b[i]," \n"[i==n]);
//        }
//        fclose(stdout);
//    }
//    for(int t=17;t<=20;t++){
//        sprintf(in,"c%d.in",t);
//        freopen(in,"w",stdout);
//        n=RAND((int)99e3,(int)1e5);
//        printf("%d\n",n);
//        for(int i=1;i<=n;i++){
//            a[i]=RAND(1,100);
//            b[i]=RAND(1,100);
//        }
//        for(int i=1;i<=n;i++){
//            printf("%d%c",a[i]," \n"[i==n]);
//        }
//        for(int i=1;i<=n;i++){
//            printf("%d%c",b[i]," \n"[i==n]);
//        }
//        fclose(stdout);
//    }
    for(int t=21;t<=25;t++){
        sprintf(in,"info%d.in",t);
        freopen(in,"w",stdout);
        n=RAND((int)4900,(int)5000);
        printf("%d\n",n);
        for(int i=1;i<=n;i++){
            a[i]=RAND(1,100);
            b[i]=RAND(1,100);
        }
        for(int i=1;i<=n;i++){
            printf("%d%c",a[i]," \n"[i==n]);
        }
        for(int i=1;i<=n;i++){
            printf("%d%c",b[i]," \n"[i==n]);
        }
        fclose(stdout);
    }
    return 0;
}
