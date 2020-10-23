#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int x,y,d,next;
}a[5100];int len,last[210000];
inline void ins(int x,int y,int d){
	len++;
	a[len].x=x;a[len].y=y;a[len].d=d;
	a[len].next=last[x];last[x]=len;
}
int n,p,m;
int f[210000];
int head,tail,list[210000],d[210000];
bool v[210000];
int main(){
	int i,j,x,y,c,k;
	scanf("%d%d%d",&n,&p,&m);
	for(i=1;i<=n;i++) scanf("%d",&f[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&c);
		ins(x,y,c);ins(y,x,c);
	}
	int minn=2147483647,s;
	for(i=1;i<=p;i++){
		
	
		memset(d,127,sizeof(d));d[i]=0;
		memset(v,true,sizeof(v));v[i]=false;
		head=1;tail=2;list[1]=i;
		while(head!=tail){
			x=list[head];
			for(k=last[x];k;k=a[k].next)
			{
				y=a[k].y;
				if(d[y]>d[x]+a[k].d)
				{
					d[y]=d[x]+a[k].d;
					if(v[y]==true)
					{
						v[y]=false;
						list[tail]=y;
						tail++;if(tail==p+1) tail=1;
					}
				}
			}
			v[x]=true;
			head++;if(head==p+1) head=1;
		}
		s=0;
		for(j=1;j<=n;j++) s=s+d[f[j]];
		minn=min(minn,s);
	}
	printf("%d\n",minn);
	return 0;
}
