#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define int long long
char l[N][N];
int n,m,Q;
set<string> mp;

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
    cin>>n>>m>>Q;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>l[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        string s = "";
        for(int j = 1;j<=m;j++){
            s = s+l[i][j];
        }
        // printf("Found %s\n",s.c_str());
        mp.insert(s);
    }

    for(int i = 1;i<=m;i++){
        string s = "";
        for(int j = 1;j<=n;j++){
            s = s+l[j][i];
        }
        // printf("Found %s\n",s.c_str());
        
        mp.insert(s);
    }
    printf("%d\n",mp.size());
    for(int i = 1;i<=Q;i++){
        int x,y;char ch;cin>>x>>y>>ch;
        l[x][y] = ch;
        string s1 = "";
        string s2 = "";
        for(int i = 1;i<=n;i++){
            s1 = s1+l[i][y];
        }
        for(int i = 1;i<=m;i++){
            s2 = s2+l[x][i];
        }
        // printf("%s %s\n",s1.c_str(),s2.c_str());
        mp.insert(s1);mp.insert(s2);
        printf("%d\n",mp.size());
    }
}