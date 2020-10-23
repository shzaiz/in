#include<bits/stdc++.h>
#define debug printf("%d %s\n",__LINE__,__FUNCTION__)
/*
-Wall -Wextra -Wconversion -fsanitize=undefined -fsanitize=address 
*/

using namespace std;

int _w;

int n;

int a[15];

long long b;

char s[100];

void dfs(){
	debug;
	while(1);
}

struct node{
	int u,v;
	node(int ru=0,int rv=0){
		u=ru;v=rv;
	}
	bool operator<(const node&rhs)const{
		return u^rhs.u?u<rhs.u:v<rhs.v;
	}
}nd[100];

int main(){
//	for(int i=1;i<=65;i++){
//		printf("%d %lld\n",1<<i,(long long)1<<i);
//	}
	debug;
//	dfs();
	debug;
//	for(int i=-1;i<=16;i++){
//		printf("%d\n",a[i]);
//	}
//	_w=scanf("%d",&n);
//	printf("%d\n",n);
//	for(int i=0;i<(int)G.size();i++){
//		//...
//	}
//	scanf("%s",s+1);
//	int len=strlen(s+1); 
	printf("bool:%d\n",sizeof (bool));
	printf("char:%d\n",sizeof (char));
	printf("int:%d\n",sizeof (int));
	printf("long long:%d\n",sizeof (long long));
	printf("double:%d\n",sizeof (double));
	printf("long double:%d\n",sizeof (long double));
	return 0;
} 
