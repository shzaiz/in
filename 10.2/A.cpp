#include <bits/stdc++.h>
using namespace std;
#define MAXN 10010
int s[MAXN],a[MAXN];
int n,k;
int check(int d){
	int start = 1,ptr=1,ans=0;
	while(ptr<=n){
		// for(;s[ptr]-s[start]<=d && ptr<=n;ptr++);
// 		
		// if(ptr==n){ans++;cout<<ans<<endl;return 0;}
		// ans++;
		// start = ptr-1;
		// ptr--;
		// cout<<ptr<<" "<<start<<" "<<n<<"\n";
		// for(;s[ptr]-s[start]<=d&& ptr<=n;ptr++);
		// start = ptr;
		// ptr--;
		// cout<<ptr<<" "<<start<<" "<<n<<"\n";
		if(ptr==n){
			ans++;
			// cout<<"Plug"<<ptr-1<<" "<<start<<" "<<n<<"\n";
			// cout<<ans;
			// printf("d = %d, ans = %d\n",d,ans);
			if(ans>k) return 0;
			else return 1;
		}
		for(;s[ptr]-s[start]<=d && ptr<=n;ptr++);
		// cout<<"Plug"<<ptr-1<<" "<<start<<" "<<n<<"\n";
		start = ptr-1;
		
		ans++;
		
		for(;s[ptr]-s[start]<=d&& ptr<=n;ptr++);
		// cout<<"Find"<<ptr-1<<" "<<start<<" "<<n<<"\n";
		start = ptr;
		
	}
	
	// printf("d = %d, ans = %d\n",d,ans);
	if(ans>k) return 0;
	else return 1;
}
int main(){
	
	cin>>n>>k;
	cin>>a[1];
	for(int i = 2;i<=n;i++){
		cin>>a[i];
		a[i]-=a[1];
	}
	a[1] = 0;
	s[1] = a[1];
	for(int i= 2;i<=n;i++){
		s[i] = a[i];
		// cout<<s[i]<<" ";
	}
	int l = 0,r = s[n];
	while (l < r){
        int mid = (l + r) /2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout<<l<<endl;
	return 0;
}