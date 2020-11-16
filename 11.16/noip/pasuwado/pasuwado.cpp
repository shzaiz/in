#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 500005
#define fov(i,v) for(int i = 0,szfuckc = v.size();i<szfuckc;i++)
char a[N],st[N];
int n,t[N],c[N],kill[N],tp=0, sh,len;
vector<int > mp[N];
int lbt(int x){ return x & -x;}
using namespace std;
#define n len
void add(int x, int num) {while (x <= n) {t[x] += num;x += lbt(x);}}
int query(int x) {int ans = 0;while (x) {ans += t[x];x -= lbt(x);}return ans;}
void addlr(int x,int y,int k){add(x, k);add(y + 1, -k);}
#undef n
int main(){
    
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("pasuwado.in","r",stdin);
    freopen("pasuwado.out","w",stdout);
    #endif
    cin>>n>>a;
    len = strlen(a);
    fo_(i,0,len-1){
        mp[a[i]-'a'+1].push_back(i+1);
    }
    fo_(i,2,len) add(i,1);
    // cout<<query(4);
    int flag = 1;
    int last =-1;
    fo(i,26){
         if(!flag) break;
        fov(j,mp[i]){
            int num = query(mp[i][j]);
            if(n-num>=0){
                kill[mp[i][j]-1] = 1;
                addlr(mp[i][j]+1,n,-1);
                st[tp++] = (char)(i-1+'a'); 
                n-=num;
            }else{
                last = mp[i][j];
                flag = 0;
            }
        }
    } 
    bool lstok = 0;
    fo_(i,0,len-1){
        if(kill[i]) continue;
        else st[tp] = a[i];
        if(last==i && !lstok) last = tp-1,lstok=1;
        tp++;
    }
    if(last!=-1)swap(st[last],st[last-n]);
    cout<<st;
    return 0;
} 
//eqqhshk