#include<bits/stdc++.h>
using namespace std;
#define int long long
int t[100001],ans;
int n;
signed main( )
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
    cin>>n;
    while(1)
    {
        int l=0;
        ans++;
        for(int i=1;i<=n;i++)
        {
           if(t[i]==0)
           {
               t[i]=ans;
               l=1;
               break;
           }
           else
           {
               int u=sqrt(ans+t[i]);
               if(u*u==ans+t[i])
               {
                   t[i]=ans;
                   l=1;break;
               }
            }
        }
        if(l==0)break;
    }
    cout<<ans-1;
}
