#include<bits/stdc++.h>
#define fint register int
#define int long long
using namespace std;
inline int fpow(int b,int pp,int k);
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,x,mods;
		cin>>n>>m>>x>>mods;
		int xt=0;
		int a,b;
		for(fint i=1;i<=n;i++)
		cin>>a,xt^=a;
		for(fint i=1;i<=m;i++)
		cin>>b,xt^=b;
		if(xt)
		cout<<"0"<<endl;
		else
		cout<<fpow(fpow(fpow(2,n-1,mods),m-1,mods),x,mods)%mods<<endl;
	}
	return 0;
}
inline int fpow(int b,int pp,int k)
{
	int ans=1;
	while(pp>0)
	{
        if(pp%2==1)
        ans=ans*b%k;
        b=b*b%k;
        pp=pp>>1;
    }
	return ans;
}

/*
in:
1
2 2 1 998244353
0 0
0 0
out:
2

in:
3
3 3 1 35433
1 0 1
1 1 1
5 5 1 23423
0 0 0 1 1
1 1 0 0 0
7 7 1 4380953
1 0 0 0 1 1 0 
0 1 0 1 0 0 1
out:
0
18690
4228931

in:
2
12 15 1 19260817
1 1 1 1 1 1 1 0 0 0 0 1 
0 0 1 1 1 1 0 0 0 1 1 1 1 1 0
19 8 1 1000000007
1 0 1 0 1 1 0 1 0 0 0 1 0 1 0 1 1 1 0
1 0 1 0 0 0 1 1
out:
0
319908071
*/
