#include <iostream>
#define ll long long
using namespace std;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	ll n;
	cin >> n;
	ll diff = 0;
	for (ll x, i = 0; i < n; ++i)
		cin >> x, diff += x;
	long long k = ((diff - n*(n - 1)/2) / n);
    diff = diff - (n*k + n*(n - 1)/2);
    for(long i = 0; i < n; i++){
            if(i < diff){
                cout<<k+i+1LL<<" ";
                
            }else{
                cout<<k+i<<" ";
            }
    }
}
