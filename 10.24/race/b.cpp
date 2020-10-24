#include <bits/stdc++.h>
using namespace std;
#define N 100010
int a[N],b[N],c[N];
int n;
int d1[N];
void sub10(){
    int len1=1;
    d1[1]=a[1];
    for(int i=2; i<=n; i++) {
		if(d1[len1]>=a[i])d1[++len1]=a[i];
        else {
            int p1=upper_bound(d1+1,d1+1+len1,a[i],greater<int>())-d1;
            d1[p1]=a[i]; 
        }
    }
    printf("%d",len1);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
    cin>>n;
    bool part1 = true;
    for(int i = 1;i<=n;i++){
        if(b[i]!=0 && c[i]!=0) part1 = 0;
        cin>>a[i]>>b[i]>>c[i];
        // a[i] = -a[i]; b[i] = -b[i]; c[i] = -c[i]; 
    }
    if(part1)cout<<n<<endl;
    else{
        for(int i = 1;i<=n;i++){
            a[i] = a[i]*1000000 + b[i]*1000+c[i];
        }
        sub10();
    }
}