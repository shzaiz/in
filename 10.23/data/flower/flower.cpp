#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n,tot;
ll ans;
struct data{int t,d;}a[100001];
inline bool cmp(data a,data b)
{return a.t*b.d<a.d*b.t;}
int main()
{
    freopen("flower10.in","r",stdin);
    freopen("flower10.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i].t=read(),a[i].d=read();
        tot+=a[i].d;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        tot-=a[i].d;
        ans+=2*a[i].t*tot;
    }
    printf("%I64d",ans);
    return 0;
}
