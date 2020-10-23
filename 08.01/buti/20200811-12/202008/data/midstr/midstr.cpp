#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int n;

char s[N],t[N],ans[N];

int a[N],b[N],c[N];

char in[20],out[20];

int main(){
	//for(int tt=1;tt<=20;tt++){
	//	sprintf(in,"midstr%d.in",tt);
      //  sprintf(out,"midstr%d.out",tt);
	//	freopen(in,"r",stdin);
	//	freopen(out,"w",stdout);
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
		ans[n+1]=0;
		printf("%s\n",ans+1);
		fclose(stdin);
		fclose(stdout);
	//}
	return 0;
}
