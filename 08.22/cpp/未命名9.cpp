#include<cstdio>
#include<cmath>
using namespace std;
struct Edge{
    int t,nexty;Edge(){t=nexty=0;}
}edge[1000000];
int head[300000]={0},cnt=0;
void add(int a,int b){
    cnt++;
    edge[cnt].t=b,edge[cnt].nexty=head[a];
    head[a]=cnt;
}
long long w[300000]={0};
int main(){
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
    long long sum=0,maxn=0;
    long long he,rmax;
    int node;
    for(int i=1;i<=n;i++){
        node=head[i];
        he=(rmax=w[edge[node].t])%10007;
        node=edge[node].nexty;
        for(;node!=0;node=edge[node].nexty){
            sum=(sum+he*w[edge[node].t])%10007;
            maxn=max(maxn,rmax*w[edge[node].t]);
            he=(he+w[edge[node].t])%10007;
            rmax=max(rmax,w[edge[node].t]);
        }
    }
    printf("%lld %lld",maxn,(sum*2)%10007);
    return 0;
}
