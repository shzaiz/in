#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int N=505;
char s[5];int a[N],col[N],bs[N],cnt[2],n,las,now,ql,qr,l,r,mid,ans;
inline int ask(R int l,R int r){
	putchar('?'),putchar(' ');
	fp(i,l,r)printf("%d ",i);
	putchar('\n'),fflush(stdout);
	scanf("%s",s+1);return s[1]=='R';
}
inline int ask(R int l,R int r,R int x,R int d){
	putchar('?'),putchar(' ');
	fp(i,l,r)if(i!=x)printf("%d ",i);
	if(d)printf("%d ",x);
	putchar('\n'),fflush(stdout);
	scanf("%s",s+1);
	if(s[1]=='-')while(true);
	return s[1]=='R';
}
int main(){
	scanf("%d",&n);
	fp(i,1,n<<1)col[i]=-1;
	l=1,r=n+1,ans=0,bs[1]=ask(1,n),bs[n+1]=bs[1]^1;
	while(r-l>1){
		mid=(l+r)>>1,bs[mid]=ask(mid,mid+n-1);
		bs[mid]==bs[l]?l=mid:r=mid;
	}
	col[l]=bs[l],col[r+n-1]=bs[r];
	ql=r,qr=r+n-2;
	fp(i,ql,qr)col[i]=ask(ql-1,qr+1,i,0)^1;
	fp(i,1,ql-2)col[i]=ask(ql,qr,i,1);
	fp(i,qr+2,n<<1)col[i]=ask(ql,qr,i,1);
	putchar('!'),putchar(' ');
	fp(i,1,n<<1)putchar(col[i]?'R':'B');
	putchar('\n'),fflush(stdout);
	return 0;
}
