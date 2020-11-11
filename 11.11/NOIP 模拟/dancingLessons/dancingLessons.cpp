#include <bits/stdc++.h>
#define deb if(debug)
const int  debug = 0;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define N 500005
using namespace std;
int n,a[N],s[N],id[N],tp = 0;
char ch[N];
struct Out{
	int l,r,d;
}O[N];
bool cmp(Out a,Out b){
	return a.d<b.d;
}
int tp2 = 0;
int main(){
	freopen("dancingLessons.in","r",stdin);
	freopen("dancingLessons.out","w",stdout);
	cin>>n;
	fo(i,n) cin>>ch[i];
	fo(i,n) cin>>a[i];
	s[++tp] = ch[1];
	id[tp] = 1;
	fo_(i,2,n){
		s[++tp] = ch[i];
		id[tp] = i;
		if((s[tp]=='B'&&s[tp-1]=='G') ||( s[tp]=='G'&&s[tp-1]=='B')){
			O[++tp2].r = id[tp];
			O[tp2].l = id[tp-1];
			O[tp2].d = abs(a[id[tp]]-a[id[tp-1]]);
			tp-=2;
		}
	}
	cout<<tp2<<"\n";
	sort(O+1,O+tp2+1,cmp);
	fo(i,tp2){
		cout<<O[i].l<<" "<<O[i].r<<"\n";
	}
	return 0;
}
