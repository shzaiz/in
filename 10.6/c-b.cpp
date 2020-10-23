#include <bits/stdc++.h>
#define N 100010
using namespace std;
#define int long long
int a[N],b[N],vis[N];
vector<int > v;
signed main(){
    // freopen("10.6/wa1.in","r",stdin);
    // freopen("10.6/wa1.out","w",stdout);
    int day;
    int n;cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    int m;cin>>m;for(int i = 1;i<=m;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=m;i++){
        int obj = -1,val = 1e17;
        for(int j = 1;j<=n;j++){
            // printf("b[%lld] = %lld a[%lld]= %lld\n",j,b[j],i,a[i]);
            if((!vis[j]) && (b[j]%a[i]==0)){
                if(val>=b[j]){
                    val = b[j];
                    obj = j;
                }
            }
        }
        if(obj==-1){day=i; break;}
        else {
            // printf("Pushed val");
            v.push_back(val);
            vis[obj] = 1;
        }
    }
    int c = v.size();
    cout<<c<<endl;
    for(int i =0;i<c;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}