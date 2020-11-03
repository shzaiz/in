#include <bits/stdc++.h>
using namespace std;
int main() {
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    int cnt = 1;
    string s = "hiiro";
    while(prev_permutation(s.begin(),s.end())){
        cout<<s<<"  ";
        if(cnt %6==0) printf("\n");
        cnt++;
    }
    // while(next_permutation(s.begin(),s.end())){
    //     cout<<s<<"  ";
    //     if(cnt %6==0) printf("\n");
    //     cnt++;
    // }
}

