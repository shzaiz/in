#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 0
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 300105
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
int fa[N], d[N], num[N], t;
int find(int x){
	if(x!= fa[x]){
		int ff = fa[x];
		fa[x] = find(fa[x]);
		d[x]+=d[ff];
		num[x]+=num[fa[x]];
	}
	return fa[x];
}
void merge(int x,int y ){
	int xx = find(x); int yy = find(y);
	if(xx != yy){
		fa[xx] = yy; d[xx] = d[yy]+num[yy];
		num[yy]+=num[xx];
		num[xx] = num[yy];
	}
}
int ask(int a,int b){
	int xx = find(a); int yy = find(b);
	if(xx!=yy) return -1;
	else return abs(d[a]-d[b])-1;
}
int main(){
	realfl freopen("P1196.in","r",stdin);
	realfl freopen("P1196.out","w",stdout);
	int t;
	cin>>t;
	fo(i,30005) fa[i] = i,num[i] = 1;
	fo(i,t){
		char op;cin>>op;
		int a,b;cin>>a>>b;
		if(op=='M') merge(a,b);
		else if(op=='C') cout<<ask(a,b)<<endl;
	}
	return 0;
}

