#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
#define N 100050
int n,V[N],T[N],S[N];
#define fo(i,x) for(register int i = 1;i<=(x);++i)
#define fo2(i,x) for(register int i = 2;i<=(x);++i)
int debug =0;
#define deb if(debug)
int a[50005] = {0},c[50005];
int ans[50005];
void updata(int i,int k){
     while(i <= n){
         c[i] += k;
         i += lowbit(i);
     }
}
int getsum(int i){
    int res = 0;
     while(i > 0){
         res += c[i];
         i -= lowbit(i);
     }
     return res;
 }
int main(){
	freopen("D:\\in.in","r",stdin);
	freopen("D:\\out.out","w",stdout);
	cin>>n;
	fo(i,n) cin>>V[i];
	cin>>T[1];
	S[1] = T[1];
	fo2(i,n){
		cin>>T[i]; S[i] = S[i-1]+ T[i];
	}
	deb fo(i,n) cout<<S[i]<<" ";
	
	deb cout<<"\n";
	fo(i,n){
		int jilei = S[i-1] + V[i];
		int which = lower_bound(S+1,S+n,jilei) - S;
		deb printf("Add %d~%d with val %d\n",i,which,1);
		ans[which] += V[i] - (S[which-1]-S[i-1]);
		updata(i,1);
		updata(which,-1);
	}
	deb cout<<"\n";
	fo(i,n){
		int sum = getsum(i);
		ans[i] += sum*T[i]; 
		cout<<ans[i]<<" ";
	}
	return 0;
}
