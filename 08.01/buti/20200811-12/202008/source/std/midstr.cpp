#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int n,rep,sum;

char s[N],t[N],ans[N];

int a[N],b[N],c[N];

int main(){
	freopen("midstr.in","r",stdin);
	freopen("midstr.out","w",stdout);
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'a';
		b[i]=t[i]-'a';
		c[i]=a[i]+b[i];
	}
	for(int i=n;i>1;i--){
		if(c[i]>25){
			c[i-1]+=(c[i]/26);
			c[i]%=26;
		}
	}
	for(int i=1;i<n;i++){
		if(c[i]&1){
			c[i]--;
			c[i+1]+=26;
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]='a'+(c[i]>>1);
	}
	printf("%s\n",ans+1);
	return 0;
}
