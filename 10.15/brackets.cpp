#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define int unsigned long long
int s[N],id[N],how[N],tp = 0,f[N],ans = 0,head[N],cnt = 0;
char b[N];
void push(int x,char y){s[++tp] = y;id[tp] = x;}
void pop(){tp--;}
struct Edge{int to,nxt;}e[N];
void adde(int u,int v){e[++cnt].to = v;e[cnt].nxt = head[u];head[u] = cnt;}
int an = 0;
void dfs(int u,int fa){
    int tag = 0;
    int idx = -1;
        if(b[u]=='('){
            tag=1;
            push(u,'(');
            for(int i = head[u];i;i = e[i].nxt){
                int v = e[i].to;
                if(v==fa) continue;
                dfs(v,u);
            }
        }else if(b[u]==')'){
            if(s[tp]=='('){
                tag=2;
                idx = id[tp];
                pop();
                how[id[tp]]++;
                f[id[tp]] += (how[id[tp]]);
                an += (how[id[tp]]);
                for(int i = head[u];i;i = e[i].nxt){
                    int v = e[i].to;
                    if(v==fa) continue;
                    dfs(v,u);
                }
                
            }else{
                tag=3;
                push(u,')');
                for(int i = head[u];i;i = e[i].nxt){
                    int v = e[i].to;
                    if(v==fa) continue;
                    dfs(v,u);
                }
            }
        }
        // printf("[%d]Ans[%d] = %d!\n",tag,u,an);
        ans = ans^(an*u);
        if(tag==2){
            an -= (how[id[tp]]);
            f[id[tp]] -= (how[id[tp]]);
            --how[id[tp]];
            push(idx,'(');
       }else if(tag==1 || tag==3){
           pop();
       }
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    #endif
    int n;cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    for(int i =2;i<=n;i++){
        int x;cin>>x;adde(i,x);adde(x,i);
    }
    dfs(1,0);
    // for(int i = 1;i<=n;i++){
    //     // printf("%d: ",i);
    //     if(b[i]=='('){
    //         push(i,'(');
    //     }else if(b[i]==')'){
    //         if(s[tp]=='('){
    //             // printf("Plus\n");
    //             pop();
    //             how[id[tp]]++;
    //             f[id[tp]] += (how[id[tp]]);
    //             an += (how[id[tp]]);
    //         }else{
    //             // printf("Push\n");
    //             push(i,')');
    //         }
    //     }
       
    //     // printf("Ans[%d] = %d\n",i,an);
    //     ans = ans^(an*i);
    // }
    cout<<ans;
}
