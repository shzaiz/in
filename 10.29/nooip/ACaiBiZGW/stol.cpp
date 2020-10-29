#include <bits/stdc++.h>
using namespace std;
#define N 405
#define fo(i, x) for (int i = 1; i <= (x); i++)
#define fo2(i, x) for (int i = 2; i <= (x); i++)
#define rep(i, x) for (int i = (x); i >=1; i--)
char mp[N][N];
int up[N][N];
int lft[N][N];
int rt[N][N];
int main()
{
    #ifdef FUCKCCF
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    freopen("stol.in","r",stdin);
    freopen("stol.out","w",stdout);
    #endif
    int n, m;
    cin >> n >> m;
    fo(i, n) fo(j, m) { cin >> mp[i][j]; if(mp[i][j]=='X') up[i][j] =rt[i][j] =  lft[i][j] = 0;else up[i][j] = lft[i][j] = 1; }
    fo(i,n) fo(j,m){
        if(mp[i][j]=='X') continue;
        up[i][j] = up[i-1][j]+1;
        lft[i][j] = lft[i][j-1]+1;
    }
    fo(i,n) for(int j = m;j>=0;j--){
        if(mp[i][j]=='X') continue;
        rt[i][j] = rt[i][j+1]+1;
    }
    int C = -1;
    fo(i,n) fo(j,m){
        int minexpand = 9999;
        fo(k,i){
            // printf("left[%d][%d] = %d\n",k,j,lft[k][j]);
            // printf("rt[%d][%d] = %d\n",k,j,rt[k][j]);
            int tmp = max(lft[k][j],rt[k][j]);
            minexpand = min(minexpand,tmp);
        }
        C = max(C,(minexpand+up[i][j])*2);
    }
    printf("%d\n",C-1);
    return 0;

}