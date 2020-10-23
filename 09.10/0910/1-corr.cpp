#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int l1,r1,u1,d1;
int l,r,u,d;
int T;
char ch[5001];
signed main(){
    //freopen("robot.in","r",stdin);
    //freopen("robot.out","w",stdout);
    scanf("%s",ch);
    int len=strlen(ch);
    for(int i=0;i<len;i++){
    	if(ch[i]=='E')r1++;
       	else if(ch[i]=='S')d1++;
       	else if(ch[i]=='W')l1++;
       	else if(ch[i]=='N')u1++;
    }
    scanf("%lld",&T);
    int p = T/len, q = T%len;
    r=p*r1;d=p*d1;u=p*u1;l=p*l1;
    for(int i=0;i<q;i++){
    	if(ch[i]=='E')r++;
       	else if(ch[i]=='S')d++;
       	else if(ch[i]=='W')l++;
       	else if(ch[i]=='N')u++;
    }


    printf("%lld %lld",r-l,u-d);
    return 0;
}