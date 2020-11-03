#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
#define N 100050
#define int long long
int n,V[N],T[N],S[N];
#define fo(i,x) for(register int i = 1;i<=(x);++i)
#define fo2(i,x) for(register int i = 2;i<=(x);++i)
int debug =0;
#define deb if(debug)
int a[N] = {0},c[N];
int ans[N];
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
signed main(){
	#ifdef XBZAKIOI
	freopen("D:/Testcases/in.ac","r",stdin);
	freopen("D:/Testcases/out.ac","w",stdout);
	#else
	freopen("snow.in","r",stdin);
	freopen("snow.out","w",stdout);
	#endif
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
		int which = lower_bound(S+1,S+n+1,jilei) - S;
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



//#include <bits/stdc++.h>
//using namespace std;
//#define N 5000005
//#define int unsigned long long
//#define fo(i,x) for(register int i =1;i<=x;++i)
//int a[N],b[N],n;
//signed main(){
//	freopen("D:\\in.in","r",stdin);
//	freopen("D:\\out.out","w",stdout);
//	cin>>n;
//	fo(i,n) cin>>a[i];
//	fo(i,n){
//		cin>>b[i];
//		int ans = 0;
//		fo(j,i){
//			if(a[j] == 0) continue;
//			else if(a[j]>=b[i]){
////				printf("Melting some\n");
//				 ans += b[i];
//				 a[j] -= b[i]; 
//			} 
//			else if(a[j]<b[i]){
////				printf("Melting all %d %d\n",a[j],b[i]);
//				ans+= a[j];
//				a[j]= 0;
//			}
//		}
//		cout<<ans<<" ";
//	}
//}
