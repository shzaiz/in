#include <bits/stdc++.h>
using namespace std;
#define N 100010
int color[N],t[N][26];
int k=1;
void insert(string s){
    int l = s.length();
    int p = 0;
    for(int i=0; i<l; i++){
        int f = s[i]-'a';
        if(!t[p][f]){
            t[p][f] = ++k;
        }
        p = t[p][f];
    }
    color[p] = 1;
}

bool find(string a){
    int l = a.length();int p = 0;
    for(int i=0; i<l; i++){
        if(!t[p][a[i]-'a']){
            return false;
        }
        p = t[p][a[i]-'a'];
    }
    if(color[p]) return true;
    else return 0;
}

int main(){
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
    int t,q;
    char s[20];
    scanf("%d%d", &t,&q);
    while(t--){
        scanf("%s", s);
        insert(s);
    }
    while(q--){
        scanf("%s", s);
        if(find(s)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}