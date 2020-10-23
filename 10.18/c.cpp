#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #else
    #endif
    string s;cin>>s;
    int l = s.length();
    printf("2\nL %d\nR %d",l-1,2*(l-1)-1);
    return 0;
}