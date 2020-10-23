#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500505
int a[N],b[N],tp=0;
pair<int,int> p[N];
signed main(){
    // freopen("10.7/wa1.in","r",stdin);
    // freopen("10.7/wa1.out","w",stdout);
    int n,k;cin>>n>>k;
    for(int  i  =1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i =1;i<N;i++){
        if(b[i]==0) continue;
        p[++tp]  = make_pair(b[i],i);
    }
    // printf("%d\n",tp);
    sort(p+1,p+1+tp);
    for(int i = 1;i<=tp;i++){
        // cout<<" "<<p[i].first<<" "<<p[i].second<<endl;
    }
    int del = tp-k;
    int ans = 0;
    for(int i = 1;i<=del;i++){
        ans+=p[i].first;
    }
    cout<<ans<<endl;


    return 0;
}