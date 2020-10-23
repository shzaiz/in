#include<bits/stdc++.h>
#define fint register int
#define h 5001
#define p 603534 
#define int long long
using namespace std;
char a[p],b[p];
int mp[p];
char pm[p];
int s[p];
int sa[p],sb[p];
int ans[p],c[p];
signed main()
{
	freopen("midstr.in","r",stdin);
	freopen("midstr.out","w",stdout);
	int n;
	cin>>n;
	scanf("%s",a);
	scanf("%s",b);
	int cnt=-1;
	for(char i='a';i<='z';i++)
	mp[i]=++cnt,pm[cnt]=i;
	for(fint i=0;i<n;i++) 
	sa[n-i]=mp[a[i]];
    for(fint i=0;i<n;i++) 
	sb[n-i]=mp[b[i]];
    for(fint i=1;i<=n;i++)
    {
        c[i]=sa[i]+sb[i]+c[i];
        c[i+1]=c[i]/26;
        c[i]=c[i]%26;
    }
    int l=n;
    if(c[l+1]>0) 
	l++;
	int ctn=0;
	for(fint i=l;i>=1;i--)
	s[++ctn]=c[i];//26进制加法
	int mid=0;
	for(fint i=1;i<=l;i++)
    { 
        ans[i]=(mid*26+s[i])/2;
        mid=(mid*26+s[i])%2;
    }
    int lenc=1;
    while(ans[lenc]==0&&lenc<l-1)
	lenc++;
	int tim=0;
    for(fint i=lenc;i<=ctn;i++)
    {
    	cout<<pm[ans[i]],tim++;
    	if(tim>=n)
    	break;
	}
	return 0;
}
/*
6
nijfvj
tvqhwp

qoztvz
*/

