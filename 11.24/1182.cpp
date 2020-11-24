#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
using namespace std;
int n,m;
int lef,rig,mid;
int total,tim;
inline bool judge(int x,int a[]){
    for(int i=0;i<n;i++){
        if(total+a[i]<=x)total+=a[i];
        else total=a[i],tim++;
    }
    return tim>=m;
}
int main(){
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        rig+=a[i];
        lef=lef>a[i]?lef:a[i];
    }
    while(lef<=rig){
        mid=(lef+rig)/2;
    	total=0,tim=0;
        if(judge(mid,a))lef=mid+1;
        else rig=mid-1;
    }
    cout<<lef;
    return 0;
}