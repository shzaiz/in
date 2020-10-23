#include <bits/stdc++.h>
#include <set>
using namespace std;
#define N 50005
#define ll long long
int LCP(vector<string>& strs){
	if(strs.size() == 0) return 0;;
    int num = strs.size();
    int len = strs[0].size();
    
    for(int i = 0; i<len; i++){
        for(int j = 0; j<num; j++){
            if((i > strs[j].size())  || (strs[0][i] != strs[j][i]))
                return i;
        }
    }
    return len; 
}
string s[10009] = {};
vector<string > tom ;
ll ans = 0;
int main(){
	int n,k;cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n);
//	for(int i = 1;i<=n;i++){
//		cout<<s[i]<<" ";
//	}
	for(int i =1;i<=n;i++){
		tom.push_back(s[i]);
		if(i%k==0){
			ans += LCP(tom);
			tom.clear();
		}
	}
	cout<<ans;
} 
