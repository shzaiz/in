#include<cstdio>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long LL;
const int mo=1000000007,ms=200100,mn=ms+2;
LL fa[mn],nfa[mn];
LL N,M,A,B,R,C,S,ans;
LL mul(LL x,LL p)
{
	if(p==1)return x;
	if(p==0)return 1;
	if(p%2==0)return mul((LL)x*x%mo,p/2);
	else return (LL)mul((LL)x*x%mo,p/2)*x%mo;
}
LL ask(LL A,LL B)
{
	return fa[A]*nfa[B]%mo*nfa[A-B]%mo;
}
LL calc(LL A,LL C,LL N)
{
	if((N-A)%2!=0)return 0;
	LL S=(N-A)/2;
	return ask(C,A)*ask(S+C-1,C-1)%mo;
}
int main()
{
	freopen("Caitlyn_.in","r",stdin);
	freopen("Caitlyn_.out","w",stdout);
	cin>>R>>C>>N>>M>>S;
	fa[0]=nfa[0]=1;
	LL L=max(max(R,C),max(N,M))*2+1;
	fo(i,1,L)
	{
		fa[i]=fa[i-1]*i%mo;
		nfa[i]=mul(fa[i],mo-2);
	}
	fo(i,0,R)
	{
		if(A>N)break;
		A=i;
		if(2*A==R)
		{
			if(S%A!=0)continue;
			if(A*C!=S)continue;
			ans=(ans+calc(A,R,N)*ask(M+C-1,C-1))%mo; 
		}
		else
		{
			B=(S-A*C)/(R-A-A);
			if(B<0||A*C+B*R-2*A*B!=S)continue;
			if(B>C||B>M)continue;
			ans=(ans+calc(A,R,N)*calc(B,C,M))%mo;
		}
	}
	cout<<ans<<endl;
	return 0;
}
