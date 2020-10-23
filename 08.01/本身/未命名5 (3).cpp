#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main(){
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll arr[n+5],a[n+5] = {0},b[n+5] = {0},Max;
        for(int i = 0;i < n;i++)
            cin >> arr[i];
        Max = *max_element(arr,arr+n);
        for(int i = 0;i < n;i++)
            a[i] = Max-arr[i];
        Max = *max_element(a,a+n);
        for(int i = 0;i < n;i++)
            b[i] = Max-a[i];
        if(k % 2 != 0)
            for(int i = 0;i < n;i++)
                i != n-1 ? cout << a[i] << " " : cout << a[i] << endl;
        else
            for(int i = 0;i < n;i++)
                i != n-1 ? cout << b[i] << " " : cout << b[i] << endl;
    }
}

