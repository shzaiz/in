#include <bits/stdc++.h>
using namespace std;
const int N=606;
char s[5];
int a[N],col[N],bs[N],cnt[2],n,las,now,ql.qr.l.r.mid,ans;
int ask(int l,int r){
	putchar('?'),putchar(' ');
	for(int i=l;i<r+1;i++) cout<<i<<" ";
	putchar('\n'),fflush(stdout);
	scanf("%s",s+1);
	return s[1]=='R';
}

int ask(int l,int r,int x,int d){
	cout<<"? ";
	for(int i=l;i<r+1;i++) if(i!=x)cout<<i<<" ";
	if(d) cout<<x<<" ";
	cout<<"\n";
	fflush(stdout);
	scanf("%s",s+1);
	return s[1] == 'R';
}
int main(){
	cin>>n;
	for(int i=1;i<(n<<1)) col[i] = -1;
	l = 1,r=n+1,ans=0,bs[1] = ask(1,n),bs[n+1]=bs[1]^1;
	while(r-l>1){
		mid = (l+r)>>1;bs[mid] = ask(mid,mid+n-1);
		bs[mid]== bs[l] ? l = mid:r=mid;
	}
	col[l] = bs[l];
	col[r+n-1]
} 

