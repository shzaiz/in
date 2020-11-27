#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 100
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
#define sz abs(head-tail)
#define deb cout<<"";
int n,m,k;
int a[N][N],Q[N],q[N],x[N][N],X[N][N],y[N][N],Y[N][N];
int front,back,head,tail;
signed main(){
	cin>>n>>m>>k;
	fo(i,n) fo(j,m) cin>>a[i][j]; 
	deb
	fo(I,n){
		head = tail = front = back = Q[1] = q[1] = 1;
		fo_(i,2,m){
			while(head<=tail&& a[I][i]>=a[I][Q[tail]]) tail--;
			while(front<=back&& a[I][i]<=a[I][q[back]]) back--;
			tail++; back++; Q[tail] = i; q[back] = i;
			while(i-Q[head]>=k) head++;
			while(i-q[front]>=k) front++;
			if(i>=k) X[I][i-k+1] = a[I][Q[head]],
				x[I][i-k+1] = a[I][q[front]];
		}
	}
	deb 
	fo(I,m-k+1){
		head = tail = front = back = Q[1] = q[1] = 1;
		fo_(i,2,n){
			while(head<=tail&& X[i][I]>=X[Q[tail]][I]) tail--;
			while(front<=back&& x[i][I]<=x[q[back]][I]) back--;
			tail++; back++; Q[tail] = i; q[back] = i;
			while(i-Q[head]>=k) head++;
			while(i-q[front]>=k) front++;
			if(i>=k) Y[i-k+1][I] = X[Q[head]][I],
				y[i-k+1][I] = x[q[front]][I];
		}
	}
	deb
	int ans = 1e9;
	fo(I,n-k+1) fo(i,m-k+1) ans = min(ans,Y[I][i]-y[I][i]);
	cout<<ans;
	return 0;
}

