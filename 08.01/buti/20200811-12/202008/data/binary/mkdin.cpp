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
	for(int t=1;t<=25;t++){
        sprintf(in,"binary%d.out",t);
        freopen(in,"w",stdout);
//        n=RAND(1,10);
//        printf("%d\n",n);
        fclose(stdout);
    }
//    for(int t=1;t<=5;t++){
//        sprintf(in,"binary%d.in",t);
//        freopen(in,"w",stdout);
//        n=RAND(1,10);
//        printf("%d\n",n);
//        fclose(stdout);
//    }
//    for(int t=6;t<=10;t++){
//        sprintf(in,"binary%d.in",t);
//        freopen(in,"w",stdout);
//        n=RAND(1000,5000);
//        printf("%d\n",n);
//        fclose(stdout);
//    }
//    for(int t=11;t<=24;t++){
//        sprintf(in,"binary%d.in",t);
//        freopen(in,"w",stdout);
//        n=RAND((int)1e6,(int)1e7-1);
//        printf("%d\n",n);
//        fclose(stdout);
//    }
//    for(int t=25;t<=25;t++){
//        sprintf(in,"binary%d.in",t);
//        freopen(in,"w",stdout);
//        n=(int)1e7;
//        printf("%d\n",n);
//        fclose(stdout);
//    }
    return 0;
}
