#include <bits/stdc++.h>
#define deb if(debug)
const int  debug = 0;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define N 55
using namespace std;
struct ios{
    inline char read(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }
    template <typename _Tp> inline ios & operator >> (_Tp&x){
        static char c11,boo;
        for(c11=read(),boo=0;!isdigit(c11);c11=read()){
            if(c11==-1)return *this;
            boo|=c11=='-';
        }
        for(x=0;isdigit(c11);c11=read())x=x*10+(c11^'0');
        boo&&(x=-x);
        return *this;
    }
}io;
bool f = 0;
int a[N];
int main(){
	freopen("cycle.in","r",stdin);
	freopen("cycle.out","w",stdout);
	int n;cin>>n;
	fo(i,n) cin>>a[i];
	int i;
	for(i =1;a[i];i++);
	if((i-1)%2) f = 1;
	for(i = n; a[i];i--);
	if((n-i)%2) f = 1;
	if(f) puts("YES\n");
	else puts("NO\n");
	return 0; 
}
