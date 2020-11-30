#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define ll long long
#define realfl if(this_is_a_real_file_output) 
int T,x,y,a,b;
ll d;
bool ok(ll x,ll y){
	return x%d==0&&y%d==0;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&x,&y);
		d=__gcd(a,b)<<1;
		x%=d;
		y%=d;
		a%=d;
		b%=d;
        if((ok(x,y)||ok(x+a,y+b)||ok(x+b,y+a)||ok(x+a+b,y+a+b)))puts("Y");
        else puts("N");
    }
return 0;
}
