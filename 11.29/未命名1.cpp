#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int maxn=201;

int n,k;

double f[maxn][maxn];

bool g[maxn][maxn];

double dfs(int n,int m)
{
    if (n<=0 && m<=0) return 0.5;
    if (n<=0) return 1.0;
    if (m<=0) return 0.0;
    if (g[n][m]) return f[n][m];
    g[n][m]=true;
    for (int a=1;a<=4;a++)
        f[n][m]+=0.25*dfs(n-a,m-4+a);
    return f[n][m];
}

double work(int n,int k)
{
    if (n/k>=maxn) return 1.0;
    return dfs((n/k)+(n%k?1:0),(n/k)+(n%k?1:0));
}

int main()
{
    scanf("%d%d",&n,&k);
    printf("%.6lf\n",work(n,k));

    return 0;
}
