#include<bits/stdc++.h>
using namespace std;
long long f[10001][11][11],ans=0,n;
bool check(int x)
{
    if(x==1) return(false);
    int mid=sqrt(x);
    for (int i=2;i<=mid;i++)
    if (x % i ==0) return(false);
    return(true);
}
int main()
{
    memset(f,0,sizeof(f));
    for (int i=1; i<=9;i++)
    for (int j=1; j<=9;j++)
    {
        int tmp=0;
        for (int k=1; k<=9;k++)
        if (check(100*k+10*i+j)){
        	cout<<(100*k+10*i+j)<<endl;
        	tmp++;
		} 
        f[3][i][j]=tmp;
    }
    scanf("%lld",&n);
    for (int i=4; i<=n;i++)
    for (int k=1; k<=9;k++) 
    for (int e=1; e<=9;e++)
    {
        for (int j=1;j<=9;j++)
        if (check(100*j+10*e+k)) f[i][e][k]=(f[i][e][k]+f[i-1][j][e]) % 1000000009;
    }
    for (int i=1;i<=9;i++)
    for (int j=1;j<=9;j++)
    ans=(ans+f[n][i][j]) % 1000000009;
    printf("%lld\n",ans);
}

