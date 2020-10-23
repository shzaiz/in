#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

char in[20],out[20];

int RAND(int l,int r){
    return rand()%(r-l+1)+l;
}

int n;

char s[N],t[N];

bool check(){
    for(int i=1;i<=n;i++){
        if(s[i]<t[i]){
            return 1;
        }
        else if(s[i]>t[i]){
            return 0;
        }
    }
    return 0;
}

int main(){
    srand(time(NULL));
    // for(int tt=1;tt<=6;tt++){
    //     sprintf(in,"midstr%d.in",tt);
    //     // sprintf(out,"midstr%d.out",tt);
    //     freopen(in,"w",stdout);
    //     n=RAND(1,12);
    //     printf("%d\n",n);
    //     for(int i=1;i<=n;i++){
    //         s[i]=RAND('a','z');
    //     }
    //     for(int i=1;i<=n;i++){
    //         t[i]=RAND('a','z');
    //     }
    //     t[n]=((t[n]>>1)<<1)|((t[n]&(s[n]&1))|(s[n]&1));
    //     s[n+1]=t[n+1]=0;
    //     if(check()){
    //         printf("%s\n%s\n",s+1,t+1);
    //     }
    //     else{
    //         printf("%s\n%s\n",t+1,s+1);
    //     }
    //     fclose(stdout);
    // }
    for(int tt=7;tt<=12;tt++){
        sprintf(in,"midstr%d.in",tt);
        // sprintf(out,"midstr%d.out",tt);
        freopen(in,"w",stdout);
        n=RAND(900,1000);
        printf("%d\n",n);
        for(int i=1;i<=n;i++){
            s[i]=RAND('a','z');
        }
        for(int i=1;i<=n;i++){
            t[i]=RAND('a','z');
        }
        t[n]=((t[n]>>1)<<1)|((t[n]&(s[n]&1))|(s[n]&1));
        s[n+1]=t[n+1]=0;
        if(check()){
            printf("%s\n%s\n",s+1,t+1);
        }
        else{
            printf("%s\n%s\n",t+1,s+1);
        }
        fclose(stdout);
        // freopen(out,"w",stdout);

        // fclose(stdout);
    }
    for(int tt=13;tt<=20;tt++){
        sprintf(in,"midstr%d.in",tt);
        // sprintf(out,"midstr%d.out",tt);
        freopen(in,"w",stdout);
        n=RAND(19e4,2e5);
        printf("%d\n",n);
        for(int i=1;i<=n;i++){
            s[i]=RAND('a','z');
        }
        for(int i=1;i<=n;i++){
            t[i]=RAND('a','z');
        }
        t[n]=((t[n]>>1)<<1)|((t[n]&(s[n]&1))|(s[n]&1));
        s[n+1]=t[n+1]=0;
        if(check()){
            printf("%s\n%s\n",s+1,t+1);
        }
        else{
            printf("%s\n%s\n",t+1,s+1);
        }
        fclose(stdout);
        // freopen(out,"w",stdout);

        // fclose(stdout);
    }
    return 0;
}