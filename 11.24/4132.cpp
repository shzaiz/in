#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
int main () {
	long long p, q;
	scanf("%lld%lld", &p, &q);
    if (p == q) {
		printf("%lld", p * p / 4);
		return 0;
	}
	p = (p - 1) / 2;
	q = (q - 1) / 2;
	printf("%lld", p * q);
	return 0;
}