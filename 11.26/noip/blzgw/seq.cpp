#include <bits/stdc++.h>
#define fo(i,x) for(int i =1;i<=n;i++)
#define fo_(i,a,b) for(int i =a;i<=b;i++)
#define rep(i,b,a) for(int i = b;i>=a;i--)
#define N 500010
#define int long long
using namespace std;
int n,m=1,v[N];
int A[N],B[N],C[N],res[N],ans;
signed main() {
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	int n;
    cin>>n;
    fo(i,n) cin>>v[i];
    while(scanf("%lld%lld%lld",&A[m],&B[m],&C[m])==3) m++;m--;
    res[m]=ans=-A[m];
    rep(k,m-1,1) {
        int xi=v[ans],i=ans;
        int t1=A[k]*(i+1)*xi*xi+(B[k]+1)*i*xi+(C[k]+i);
        int t2=(i+1)*xi*xi+i*xi+1;
        res[k]=ans=-t1/t2;
    }
    fo_(i,2,m) printf("%lld\n",res[i]);
    return 0;
}
