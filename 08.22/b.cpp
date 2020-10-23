#include <bits/stdc++.h>
#define MOD 2012
using namespace std;
int f[1005][1005];
int dabiao[10][10]={{1,0,0,0,0,0,0,0,0,0},
{1,1,0,0,0,0,0,0,0,0},
{1,4,1,0,0,0,0,0,0,0},
{1,11,11,1,0,0,0,0,0,0},
{1,26,66,26,1,0,0,0,0,0},
{1,57,302,302,57,1,0,0,0,0},
{1,120,1191,404,1191,120,1,0,0,0},
{1,247,269,1535,1535,269,247,1,0,0},
{1,502,524,1718,1266,1718,524,502,1,0},
{1,1013,1564,480,542,542,480,1564,1013,1}};

inline int read(){
	int x;
    x=0;char ch=0;bool sign=false;
    while(ch < '0' || ch > '9'){
        sign|=(ch == '-');
        ch=getchar();
    }
    while(!(ch < '0' || ch > '9')){
        x=x*10+(ch^48);
        ch=getchar();
    }
    x=sign ? -x : x;
    return x;
}

inline void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

int main(){
	freopen("num.in","r",stdin);
 	freopen("num.out","w",stdout);
	for(int i=0;i<1005;i++){
		f[i][0] = 1;
	}
	for(int i=1;i<1005;i++){
		for(int j=1;j<1005;j++){
			f[i][j] = (f[i-1][j-1]*(i-j) + f[i-1][j]*(j+1))%MOD;
		}
	}
	int n=read(),p=read();
	if(n<=10) printf("%d\n",dabiao[n-1][p]);
	printf("%d\n",f[n][p]);
	
	return 0;
}