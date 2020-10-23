#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int calcTimes, stringSizes;
string n1, n2, b1, b2;
void chkUp(){
    for(int i = stringSizes - 1; i >= 0; i--){
        if(n1[i] > 'z'){
            n1[i - 1] += (n1[i] - 'a') / 26;
            n1[i] = (n1[i] - 'a') % 26 + 'a';
        }else{
            return;
        }
    }
}
int main(){
    freopen("midstr.in","r", stdin);
    freopen("midstr.out", "w", stdout);
    cin >> stringSizes >> n1 >> n2;
    b1 = n1;
    b2 = n2;
    while(true){
        n1[stringSizes - 1] ++;
        calcTimes++;
        if(n1[stringSizes - 1] > 'z') chkUp();
        if(n1 == n2) break;
    }
    n1 = b1;
    n2 = b2;
    for(int i = 0; i < calcTimes / 2; i++){
        n1[stringSizes - 1] ++;
        if(n1[stringSizes - 1] > 'z') chkUp();
    }
    chkUp();
    cout << n1 << endl;
    return 0;
}