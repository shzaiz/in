//
//  main.cpp
//  T3lemon
//
//  Created by mac on 2020/10/23.
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
int read( )
{
    int x=0;int f=1;char ch;ch=getchar( );
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar( );}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar( );}
    return x*f;
}
int n,kk;
int mod=998244353;
int k[3][100009];
int a[100001];
int cnt;
int head[100001];
int chu[100001];
struct bian{int to,next;}e[100001];
void add(int x,int y){cnt++;chu[x]++;e[cnt].to=y;e[cnt].next=head[x];head[x]=cnt;}
int s[100001];
void work(int xv,int ans,int chi,int last)
{
    if(a[xv]!=0)
    {
        if(chi==0)
        {
            s[xv]=ans;
            for(int i=head[xv];i;i=e[i].next)work(e[i].to,ans,0,a[xv]);
            return;
        }
        if(last==0)
        {
            s[xv]=k[2][chi]+(k[1][chi]*(kk-1))%mod;
            s[xv]=s[xv]%mod;
            s[xv]=s[xv]*ans%mod;
            ans=s[xv];
            for(int i=head[xv];i;i=e[i].next)work(e[i].to,ans,0,a[xv]);
            return;
        }
        if(a[xv]!=last)
        {
            ans=ans*(k[2][chi]+((kk-2)*k[1][chi])%mod)%mod%mod;//假如是不一样的
            s[xv]=ans;
            for(int i=head[xv];i;i=e[i].next)work(e[i].to,ans,0,a[xv]);
            return;
        }
        if(a[xv]==last)
        {
            ans=ans*(k[1][chi]*(kk-1)%mod)%mod;
            s[xv]=ans;
            for(int i=head[xv];i;i=e[i].next)work(e[i].to,ans,0,a[xv]);
            return;
        }
    }
    if(a[xv]==0)
    {
        chi++;
        if(last==0)
        {
            if(chi==1)s[xv]=kk;
            else s[xv]=kk*((k[2][chi-1]+((kk-1)*k[1][chi-1])%mod)%mod)%mod;
            for(int i=head[xv];i;i=e[i].next)work(e[i].to,ans,chi,last);
            return;
        }
        if(last!=0)
        {
            s[xv]=k[2][chi]+(k[1][chi]*(kk-1))%mod;
            s[xv]=s[xv]%mod;
            s[xv]=s[xv]*ans%mod;
            for(int i=head[xv];i;i=e[i].next)work(e[i].to,ans,chi,last);
            return;
        }
    }
}


signed main( )
{
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
   // freopen("14.in","r",stdin);
    //freopen("out.out","w",stdout);
    n=read( );
    kk=read( );
    k[2][0]=1;
    k[1][0]=1;
    k[1][1]=1;//是不一样的
    k[2][1]=0;//是一样的
    for(int i=2;i<=n+1;i++)
    {
        k[2][i]=k[1][i-1]*(kk-1)%mod;//第i层一样的是由第i-1层不一样的
        k[1][i]=(k[2][i-1]+k[1][i-1]*(kk-2))%mod;//第i层的不一样的是由其他
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        int fa;
        fa=read( );
        add(fa,i);
    }
    work(1,1,0,0);
    for(int i=1;i<=n;i++)
    {
        cout<<s[i]<<endl;
        s[i]=s[i]^s[i-1];
    }
    cout<<s[n];
}