#include<bits/stdc++.h>
#define fint register int
#define h 5001
#define p 200001
using namespace std;
char st[p];
int tops=0;
int main()
{
	freopen("type.in","r",stdin);
	freopen("type.out","w",stdout);
	int n;
	cin>>n;
	char op,wr;
	int num;
	for(fint i=1;i<=n;i++)
	{
		cin>>op;
		if(op=='T')
		cin>>wr,st[++tops]=wr;
		else
		if(op=='U')
		cin>>num,tops-=num;
		else
		if(op=='Q')
		cin>>num,cout<<st[num]<<endl;
	}
	return 0;
} 
/*
7
T a
T b
T c
Q 2
U 2
T c
Q 2
*/
