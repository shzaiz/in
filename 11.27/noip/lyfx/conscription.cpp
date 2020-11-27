//
//  main.cpp
//  2
//
//  Created by mac on 2020/11/27.
//
/*
 2
 5 5 8
 4 3 6831 1 3 4583 0 0 6592 0 1 3063
 3 3 4975
 1 3 2049
 4 2 2104
 2 2 781
 5 5 10
 2 4 9820
 3 2 6236
 3 1 8864
 2 4 8326
 2 0 5156
 2 0 1463
 4 1 2439
 0 4 4373
 3 4 8889
 2 4 3133
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct cxk{
    int x,y,zhi;
}e[5000001];
int t;
int fa[1000001],ans;
bool cmp(cxk a,cxk b){return a.zhi>b.zhi;}
int read( )
{
    int x=0;
    int f=1;
    char ch=getchar( );
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar( );
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar( );
    }
    return x*f;
}
int n,m,r;
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
signed main( )
{
	freopen("conscription.in","r",stdin);
	freopen("conscription.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        n=read();
        m=read( );
        r=read( );
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=n+1;i<=n+m+1;i++)fa[i]=i;
        for(int i=1;i<=r;i++)
        {
            e[i].x=read( );
            e[i].y=read( );
            e[i].zhi=read( );
            e[i].x++;
            e[i].y=e[i].y+n+1;
        }
        sort(e+1,e+r+1,cmp);
        for(int i=1;i<=r;i++)
        {
            int xx=find(e[i].x);
            int yy=find(e[i].y);
            if(xx!=yy)
            {
                fa[xx]=yy;
                ans+=e[i].zhi;
            }
        }
        cout<<(10000*m+10000*n-ans)<<endl;
    }
}
