#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
int a,b,p;
int T,k;
ll n;
ll ans[3],base[3][3];
ll m1[3],m2[3][3];
ll plu(ll u,ll v){return (u+v)%p;}
ll mul(ll u,ll v){return u*v%p;}
void exgcd(int u,int v,int &x,int &y){if(v==0){ x=1;y=0;return;}exgcd(v,u%v,y,x);y-=u/v*x;}
int inv(int u){int x,y;exgcd(u,p,x,y);return ((x%p)+p)%p;}
void init(){ans[1]=0;ans[2]=1;base[1][1]=base[2][1]=k;base[1][2]=0;base[2][2]=1;}
void mula(){
    memset(m1,0,sizeof m1);
    fo(i,2)fo(j,2)m1[i]=plu(m1[i],mul(ans[j],base[j][i]));
    fo(i,2) ans[i]=m1[i];
}
void mulb(){
    memset(m2,0,sizeof m2);
    fo(i,2)fo(j,2)fo(k,2)m2[i][j]=plu(m2[i][j],mul(base[i][k],base[k][j]));
    fo(i,2)fo(j,2)base[i][j]=m2[i][j];
}
void qp(ll v){while(v>0){if(v&1){mula();}mulb();v>>=1;}}
int solve(ll u){init();qp(u);return ans[1];}
int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    cin>>a>>p;k=mul(a,inv(1));cin>>T;
    while(T--){cin>>n;cout<<solve(n)<<endl;}
    return 0;
}