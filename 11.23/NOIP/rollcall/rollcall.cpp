#include <bits/stdc++.h>
#define N 30010
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,a,b) for(int i = a;i<=b;i++) 
using namespace std;
#define int long long
int n,m,x,c[N],a[N],cnt;
set<int> aa;
set<int>::iterator it;
signed main(){
    freopen("rollcall.in","r",stdin);
    freopen("rollcall.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<=m; i++){
        cin>>x;
        c[x]++;
    }
    aa.clear();
    for(int i=1; i<=n; i++){
        aa.insert(a[i]);
        while(c[i]){
            c[i]--;
            it=aa.begin();
            for(int j=1; j<=cnt; j++)it++;
            cout<<*it<<endl;
            cnt++;
        }
    }
    return 0;
}
