#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n;
int block,len;
int a[N],l[N],r[N],pos[N],add[N];
void change(int x,int y,int t){
    if(pos[x]== pos[y]){
        for(int i = x;i<=y;i++) a[i]+=t;
        return;
    }
    for(int i = pos[x]+1;i<=pos[y]-1;i++){
        add[i]+=t;
    }
    for(int i = x;i<=r[pos[x]];i++){
        a[i]+=t;
    }
    for(int i = l[pos[y]];i<=y;i++) a[i]+=t;
}
int ask(int x){
    return a[x]+add[pos[x]];
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("akioi.in","r",stdin);
    freopen("akioi.out","w",stdout);
    #endif
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    block = sqrt(n);
    len = n/block;
    for(int i = 1;i<=block;i++){
        l[i] = (i-1)*len+1;
        r[i] = i*len;

    }
    if(n%block){
        block++;
        l[block] = r[block-1]+1;
        r[block] =n;
    }

    for(int i = 1;i<=block;i++){
        for(int j = l[i];j<=r[i];j++){
            pos[j] = i;
        }
    }
    int op,l,r,c;
    int T = n;
    while(T--){
        cin>>op>>l>>r>>c;
        if(op==0){
            change(l,r,c);
        }else{
            cout<<ask(r)<<endl;
        }
    }
    return 0;
}