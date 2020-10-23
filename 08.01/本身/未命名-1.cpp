#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int T;
		cin >> T;
    while(T--){
        cin >> n;
        string s;
        cin >> s;
        vector<int>L;
        for(int i = 0;i < s.size();i++){
            int cnt = 1;
            while(i + 1 < s.size() && s[i] == s[i+1]){
                i++;
                cnt++;
            }
            L.push_back(cnt);
        }
        if(s[s.size() - 1] == s[0] && L.size() > 1){
            L[0] += L[L.size()-1];
            L.pop_back();
        }
        if(L.size() == 1){
            if(L[0] <= 2){
                cout << 0 << endl;
            }
            else{
                cout << (L[0] + 2) / 3 << endl;
            }
        }
        else{
            int ans = 0;
            for(int i : L){
                ans += i/3;
            }
            cout << ans << endl;
        }
    }
}
