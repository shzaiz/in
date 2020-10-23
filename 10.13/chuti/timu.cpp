#include <bits/stdc++.h>
using namespace std;
int found = 0;
short table[7][7] = { {0,0,0,0,0,0},
    {0,1,1,1,1,1},
    {0,0,1,1,1,1},
    {0,0,0,2,1,1},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0}};
short t[7][7];
const int dx[]={0,1,1,-1,-1,2,2,-2,-2};
const int dy[]={0,2,-2,2,-2,1,-1,1,-1};

const int dxou[]={0,1,1,-1,-1,2,2,-2,-2};
const int dyou[]={0,2,-2,2,-2,1,-1,1,-1};
int stp = 0;
int check(){
    int cnt=0;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            if(t[i][j]!=table[i][j])cnt++;
    return cnt;
}
int ok(int x,int y){
    if(x<1||x>5||y<1||y>5)return 0;
    return 1;
}
void dfs(int x, int y,int dep){
    if(dep == stp){
        if(check()==0){
            found  =1;
        }
        return;
    }
    for(int i =1;i<=8;i++){
        int xx = x + dx[i];
        int yy  = y + dy[i];
        if(ok(xx,yy)==0) continue;
        swap(t[x][y],t[xx][yy]);
        int ck = check();
        if(ck+dep<=stp){
            dfs(xx,yy,dep+1);
        }
        swap(t[xx][yy],t[x][y]);
    }
}
int solve(){
    memset(t,0,sizeof(t));
    stp = 0;
    int _x,_y;
    found = 0;
    for(int i =1;i<=5;i++){
        for(int j =1;j<=5;j++){
            char cx;cin>>cx;
            if(cx=='*') {t[i][j] = 2;_x = i,_y = j;}
            else t[i][j] = cx-'0';
        }
    }
    dfs(_x,_y,0);
    for( stp=1;stp<=15;stp++){
            dfs(_x,_y,0);
            if(found){printf("%d\n",stp);goto killer;}
    }
    printf("-1\n");
    killer:;
    return 0;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
    #endif
    int T;cin>>T;while(T--){
        solve();
    }

}

