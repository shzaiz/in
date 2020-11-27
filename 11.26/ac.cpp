#include<bits/stdc++.h>
#define now c[u][*p-'a']
#define skip while(*++p<=' ')
const int N=159,S=20009,T=1000009;
char s[T<<6],o[T],*m[N];
int c[S][26],f[S],e[S],g[S],q[S],a[N],he[N],ne[N],to[N],at[N];
void dp( int x){
    for( int i=he[x];i;i=ne[i])
        dp(to[i]),a[x]+=a[to[i]];
}
int main(){
    fread(s,1,sizeof(s),stdin);
     char *p=s,*p1=o;
     int n,cnt,i,h,t,pe,u,v,mx;
    while((n=*p&15)){
        while(*++p>='0')
            n*=10,n+=*p&15;
        cnt=h=t=pe=0;
        for(i=1;i<=n;++i){
            skip;m[i]=p;
            for(u=0;*p>='a';++p)
                u=now?now:(now=++cnt);
            at[e[u]=i]=u;
        }
        skip;m[i]=p;
        for(i=0;i<26;++i)
            if(c[0][i])q[++t]=c[0][i];
        while(h<t){
            if(e[u=q[++h]])
                to[++pe]=e[u],ne[pe]=he[e[g[u]]],he[e[g[u]]]=pe;
            for(i=0;i<26;++i)
                if((v=c[u][i])){
                    f[q[++t]=v]=c[f[u]][i];
                    g[v]=e[f[v]]?f[v]:g[f[v]];
                }
                else c[u][i]=c[f[u]][i];
        }
        for(u=0;*p>='a';++p)
            u=now,++a[e[u]?e[u]:e[g[u]]];
        dp(0);
        mx=t=0;
        for(i=1;i<=n;++i)
            if(mx<a[i])mx=a[q[t=1]=i];
            else if(mx==a[i])q[++t]=i;
        sprintf(p1,"%d\n",mx);
        while(*++p1);
        for(i=1;i<=t;++i){
            memcpy(p1,m[q[i]],m[q[i]+1]-m[q[i]]);
            p1+=m[q[i]+1]-m[q[i]];
        }
        memset(c,0,++cnt*104);
        memset(f,0,cnt<<2);
        memset(e,0,cnt<<2);
        memset(g,0,cnt<<2);
        memset(a,0,++n<<2);
        memset(he,0,n<<2);
        skip;
    }
    fwrite(o,1,p1-o,stdout);
    return 0;
}
