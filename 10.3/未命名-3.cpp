#include <bits/stdc++.h>
using namespace std;
#define MAXN 50010
#define MAXM 32771
#define MOD 1000000007
int a[MAXN],aa[MAXN],c[MAXM],lsh[MAXN],tmp[MAXN],n;

#define ll long long
ll add(ll a,ll b){
	return ((a%MOD)+(b%MOD))%MOD;
}
ll mul(ll a,ll b){
	return ((a%MOD)*(b%MOD)%MOD);
}
int lowbit(int x){
    return x&(-x);
}
void add(int x,int ad){
    while(x<MAXM){
	    c[x]+=ad;
        x+=lowbit(x);
    }
}
ll sum(int x){
    ll res=0;
    while(x>0){
        res+=c[x];
        x-=lowbit(x);
    } 
    return res;
}
ll get(int l,int n){
	memset(a,0,sizeof(a));
	for(int i = 0;i<n;i++){
		a[i+1] = aa[i+l];
	}
		long long ans=0;
	    memset(tmp,0,sizeof(tmp));
	    memset(c,0,sizeof(c));
	    for(int i=1;i<=n;i++){
	    	lsh[i] = a[i];
	    	
	    }
	    sort(lsh+1 , lsh+n+1);
		int cnt = unique(lsh+1 , lsh+n+1) - lsh - 1;
		for(int i=1; i<=n; i++)
			a[i] = (cnt+1)-(lower_bound(lsh+1 , lsh+cnt+1 , a[i]) - lsh);
        for(int i=1;i<=n;i++){
            // cout<<a[i]<<" ";
      	    a[i]++;
           	tmp[i]=sum(a[i]-1);
            add(a[i],1); 
        }
        memset(c,0,sizeof(c));
        for(int i=n;i>=1;i--){
        	ans=add(ans,mul(sum(a[i]-1),tmp[i]));
        	add(a[i],1);
        }
        return ans;
        // printf("\n%lld\n",ans);
}

int main(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>aa[i];
	}
	ll anss = 0;
	for(int l = 1;l<=n;l++){
		for(int r =l;r<=n;r++){
			if(abs(r-l+1)<3)continue;
			else{
				anss = add(anss,get(l,r-l+1));
			}
		}
	}
    cout<<anss;
    return 0;
}