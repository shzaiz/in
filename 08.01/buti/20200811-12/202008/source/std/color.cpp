#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,MOD=998244353;

int n,k,mood;

int a[N],cnto,cnte;

int odst,oden,evst,even,od[N],ev[N];

long long f[2][N],ans=1;//same/amount of -1

long long plu(long long u,long long v){
	return (u+v)%MOD;
}

long long mul(long long u,long long v){
	return u*v%MOD;
}

long long qpow(long long u,int v){
	long long rep=1;
	while(v>0){
		if(v&1){ 
			rep=rep*u%MOD;
		}
		u=u*u%MOD;
		v>>=1;
	}
	return rep;
}

int main(){
	freopen("D:\\Testcases\\in.ac","r",stdin);
	freopen("D:\\Testcases\\ac2.in","w",stdout);
	scanf("%d%d%d",&n,&k,&mood);
	if(mood){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i&1){
				od[++cnto]=a[i];
			}
			else{
				ev[++cnte]=a[i];
			}
		}
		f[0][0]=1;
		od[cnto+1]=-1;
		ev[cnte+1]=-1;
		for(int i=1;i<=n;i++){
			f[0][i]=plu(f[1][i-1],mul(k-2,f[0][i-1]));
			f[1][i]=mul(k-1,f[0][i-1]);
		}
		odst=1;oden=cnto;
		evst=1;even=cnte;
		for(int i=1;i<=cnto+1;i++){
			if(od[i]!=0){
				odst=i;
				break;
			}
		}
		if(odst>cnto){
			ans=mul(ans,mul(k,qpow(k-1,cnto-1)));
		}
		else{
			for(int i=cnto;~i;i--){
				if(od[i]!=0){
					oden=i;
					break;
				}
			}
			ans=mul(ans,qpow(k-1,odst-1+cnto-oden));
			for(int i=odst+1,lst=odst;i<=oden;i++){
				if(od[i]!=0){
					if(od[i]==od[lst]){
						ans=mul(ans,f[1][i-lst-1]);
					}
					else{
						ans=mul(ans,f[0][i-lst-1]);
					}
					lst=i;
				}
			}
		}
		for(int i=1;i<=cnte+1;i++){
			if(ev[i]!=0){
				evst=i;
				break;
			}
		}
		if(evst>cnte){
			ans=mul(ans,mul(k,qpow(k-1,cnte-1)));
		}
		else{
			for(int i=cnte;~i;i--){
				if(ev[i]!=0){
					even=i;
					break;
				}
			}
			ans=mul(ans,qpow(k-1,evst-1+cnte-even));
			for(int i=evst+1,lst=evst;i<=even;i++){
				if(ev[i]!=0){
					if(ev[i]==ev[lst]){
						ans=mul(ans,f[1][i-lst-1]);
					}
					else{
						ans=mul(ans,f[0][i-lst-1]);
					}
					lst=i;
				}
			}
		}
		printf("%lld\n",ans);
	}
	else{
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			od[++cnto]=a[i];
		}
		f[0][0]=1;
		od[cnto+1]=-1;
		for(int i=1;i<=n;i++){
			f[0][i]=plu(f[1][i-1],mul(k-2,f[0][i-1]));
			f[1][i]=mul(k-1,f[0][i-1]);
		}
		odst=1;oden=cnto;
		for(int i=1;i<=cnto+1;i++){
			if(od[i]!=0){
				odst=i;
				break;
			}
		}
		if(odst>cnto){
			ans=mul(ans,mul(k,qpow(k-1,cnto-1)));
		}
		else{
			for(int i=cnto;~i;i--){
				if(od[i]!=0){
					oden=i;
					break;
				}
			}
			ans=mul(ans,qpow(k-1,odst-1+cnto-oden));
			for(int i=odst+1,lst=odst;i<=oden;i++){
				if(od[i]!=0){
					if(od[i]==od[lst]){
						ans=mul(ans,f[1][i-lst-1]);
					}
					else{
						ans=mul(ans,f[0][i-lst-1]);
					}
					lst=i;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
