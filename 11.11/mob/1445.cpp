#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10000100
#define debp cout<<__LINE__<<" "<<__FUNCTION__<<endl;
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
bool npr[N];
long long sum[N];
int pr[N];
int mu[N],g[N];
int cnt;
void getmu(int n){
	   mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!npr[i]){mu[i]=-1;pr[++cnt]=i;}
        for(int j=1;j<=cnt&&pr[j]*i<=n;j++)
        {
            npr[i*pr[j]]=1;
            if(i%pr[j]==0)break;
            else mu[pr[j]*i]=-mu[i];
        }
    }
    for(int j=1;j<=cnt;j++)
        for(int i=1;i*pr[j]<=n;i++)g[i*pr[j]]+=mu[i];
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(long long)g[i];
} 
int n,m;
int main(){
    long long t;
    cin>>t;
    getmu(50000);
    while(t--)
    {
        static long long a,b,d;
        cin>>a>>b>>d;
        long long max_rep,ans;
        max_rep=min(a,b);ans=0;
        for(long long l=1,r;l<=max_rep;l=r+1)
        {
            r=min(a/(a/l),b/(b/l));
            ans+=(a/(l*d))*(b/(l*d))*(sum[r]-sum[l-1]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}