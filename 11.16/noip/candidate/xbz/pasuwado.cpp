#include<bits/stdc++.h>
#define fint register int
#define H 5001
#define N 200001
using namespace std;
char a[N],b[N];
int main()
{
	freopen("pasuwado.in","r",stdin);
	freopen("pasuwado.out","w",stdout);
	int op;
	cin>>op;
	cin>>a;
	int len=strlen(a);
	for(fint i=0;i<len;i++)
	{
		char minns=a[i];
		int min_pos=-1;
		for(fint j=i+1;j<=i+op&&j<len;j++)
		if(a[j]<minns)
		minns=a[j],min_pos=j;
		if(min_pos>0)
		{
			for(fint j=i;j<min_pos;j++)
			b[j]=a[j];
			for(fint j=i;j<min_pos;j++)
			a[j+1]=b[j]; 
			a[i]=minns;
			op=op-(min_pos-i);
		}
		if(op==0)
		break;
	}
	for(fint i=0;i<len;i++)
	cout<<a[i];
	return 0;
}
/*
3
dcba
*/
