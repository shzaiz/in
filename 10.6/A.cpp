#include <bits/stdc++.h>
#define N 100010
using namespace std;
#define int long long
int mul(int a, int b,int p){
    return ((a%p)*(b%p)%p);
}




signed main(){
    freopen("10.6/wa1.in","r",stdin);
    freopen("10.6/wa1.out","w",stdout);
    int m,n,mod;
    cin>>m>>n>>mod;
    if(m==1){
        vector<int > p;
        vector<int > q;
        int s1 = 1;int t1 = n;
        int ps;cin>>ps;
        for(int i=0;i<ps;i++) {int x;cin>>x; s1 = max(s1,x);p.push_back(x);}
        int qs;cin>>qs;
        
        for(int i=0;i<qs;i++) {int x;cin>>x;t1 = min(t1,x);q.push_back(x);}
        int ans = 0;
        for(int i = s1;i<=t1;i++){
            ans = (ans+1)%mod;
        }
        cout<<ans<<endl;
    }else if(m==2){
        vector<int > p;
        vector<int > q;
        int s1 = 1;int t1 = n;
        int ps;cin>>ps;
        for(int i=0;i<ps;i++) {int x;cin>>x; s1 = max(s1,x);p.push_back(x);}
        int qs;cin>>qs;

        vector<int > p1;
        vector<int > q1;
        int s1 = 1;int t1 = n;
        int ps;cin>>ps;
        for(int i=0;i<ps;i++) {int x;cin>>x; s1 = max(s1,x);p.push_back(x);}
        int qs;cin>>qs;
        
        for(int i=0;i<qs;i++) {int x;cin>>x;t1 = min(t1,x);q.push_back(x);}
        int ans = 0;
        for(int i = s1;i<=t1;i++){
            ans = (ans+1)%mod;
        }
        cout<<ans<<endl;
    }
    
}

// int m,n,p;
//     cin>>m>>n>>p;
//     int ans = 1;
//     for(int i = 1;i<=m;i++){
//         int p1;cin>>p1;int mx = 1;
//         for(int i = 1;i<=p1;i++){
//             int m;cin>>m;
//             mx = max(mx,m);
//         }
        
//         int p2;cin>>p2;int mi = n;
//         for(int i = 1;i<=p2;i++){
//             int m;cin>>m;
//             mi = min(mi,m);
//         }
//         ans = mul(ans,(mx-mi),p);
//     }
//     cout<<(ans%p);
//     return 0;