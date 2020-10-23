#include <iostream>
#include <cstdio>
using namespace std;
int fa[100050], le[100050], ri[100050], pplCount;
bool vis[100050];
void init(int n){
    for(int i = 1; i <= n; i++) fa[i] = i;
}
int get(int n){
    if(fa[n] == n) return n;
    return fa[n] = get(fa[n]);
}
int merge(int x, int y){
    x = get(x);
    y = get(y);
    if(y != x){
        fa[x] = y;
    }
}
int doIt(int start, int iTime, int blocks){
    int temp2 = 999999;
    if(blocks == 1) {
        return iTime;
        //cout << iTime << endl;
    }
    vis[start] = true;
    iTime++;
    for(int j = start - le[start]; j <= start + ri[start]; j++){
        int temp = j;
        if(temp <= 0) temp += pplCount;
        if(temp > pplCount) temp -= pplCount;
        if(!vis[temp]){
            merge(start, temp);
            blocks--;
            temp2 = min(temp2, doIt(temp, iTime, blocks));
        }
    }
    vis[start] = false;
    return temp2;
}
int main() {
    freopen("info.in", "r", stdin);
    freopen("info.out", "w", stdout);
    cin >> pplCount;
    for(int i = 1; i <= pplCount; i++) cin >> le[i];
    for(int i = 1; i <= pplCount; i++) cin >> ri[i];
    for(int i = 1; i <= pplCount; i++){
        init(pplCount);
        cout << doIt(i, 0, pplCount) << " ";
    }
    return 0;
}
