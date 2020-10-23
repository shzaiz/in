// ---------------------------------------------------
// This is T2 T2 T2 T2 T2 T22222 #include<O_m_g_._h>
//                       -- A nice notice by korgo :)
// ---------------------------------------------------
#include <iostream>
#include <cstdio>
using namespace std;
bool checkBinary(long long n){
    while(n != 0){
        int t = n % 10;
        n /= 10;
        if(t != 0 && t != 1) return false;
    }
    return true;
}
int main(){
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    long long num, nowPlace = 1, temp = 0;
    cin >> num;
    while(true){
        temp = num * nowPlace;
        if(temp % 10 == 0 || temp % 10 == 1 && temp / 10 % 10 == 0 || temp / 10 % 10 == 1){
            if(checkBinary(temp)){
                cout << temp << endl;
                return 0;
            }
        }
        if(nowPlace >= 140000000) {
            cout << -1 << endl;
            return 0;
        }
        nowPlace++;
    }
    return 0;
}
