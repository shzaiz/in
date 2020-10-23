#include<bits/stdc++.h>
#define int long long
using namespace std;
int uu,dd,ll,rr,u,d,l,r,T;
string ch;
signed main(){
    freopen("robot.in","r",stdin);
    freopen("robot.out","w",stdout);
    cin>>ch;
    int len= ch.length();
    for(int i=0;i<len;i++){
    	if(ch[i]=='E')rr++;
       	else if(ch[i]=='S') dd++;
       	else if(ch[i]=='W') ll++;
       	else if(ch[i]=='N') uu++;
    }
    scanf("%lld",&T);
    int p = T/len, q = T%len;
    u=p*uu;d=p*dd;l=p*ll;r=p*rr;
    for(int i=0;i<q;i++){
    	if(ch[i]=='E') r++;
       	else if(ch[i]=='S') d++;
       	else if(ch[i]=='W') l++;
       	else if(ch[i]=='N') u++;
    }


    printf("%lld %lld",r-l,u-d);
    return 0;
}
