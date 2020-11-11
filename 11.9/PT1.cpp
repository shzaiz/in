#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
int a[N],b[N],t[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;

int main(){
	realfl freopen(".in","r",stdin);
	realfl freopen(".out","w",stdout);
	cin>>n;
	fo(i,n) cin>>a[i];
	fo(i,n){
		cin>>b[i]; to[i] = 1;
		q.push(pair<int, int>(a[1] + b[i], i));
	}
	while(n--){
		printf("%d ", q.top().first);
        i = q.top().second; q.pop();
        q.push(pair<int, int>(a[++to[i]] + b[i], i));
	}
	return 0;
}

