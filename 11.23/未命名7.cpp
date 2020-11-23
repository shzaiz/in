//#include <bits/stdc++.h>
//using namespace std;
//#define using_debug_output 1
//#define using_temp_file 0
//#define this_is_a_real_file_output 1
//#define fo(i,x) for(int i = 1;i<=x;i++)
//#define fo_(i,b,x) for(int i = b;i<=x;i++)
//#define re(i,x,b) for(int i = x;i>b;i--)
//#define N 50005
//#define deb if(using_debug_output)
//#define fil if(using_temp_file)
//#define realfl if(this_is_a_real_file_output)
//#define int long long
//int val[N], t[N], ans[N];
//int n,m,k,tmp;
//struct Q{
//	int l,r,id,d;
//}que[N];
//bool cmp(Q a, Q b){
//	return a.id<b.id? a.r<b.r:a.id<b.id;
//}
//void del(int x) {
//	tmp-= 2*--t[val[x]]+1;
//}
//void add(int x){
//	tmp+= 2*++t[val[x]]-1;
//}
//signed main(){
//	cin>>n>>m>>k;
//	int len = sqrt(n*n/m);
//	fo(i,n) cin>>val[i];
//	fo(i,m){
//		 cin>>que[i].l>>que[i].r;
//		 que[i].id = (que[i].l+len-1)/len;
//		 que[i].d = i;
//	}
//	sort(que+1, que+n+1,cmp);
//	int l = que[1].l,r = que[1].l-1;
//	fo(i,m){
//		while(l<que[i].l) del(l++);
//		while(l>que[i].l) add(--l);
//		while(r>que[i].r) del(r--);
//		while(r<que[i].r) add(++r);
//		ans[que[i].d] = tmp;
//	}
//	fo(i,m) cout<<ans[i];
//	return 0;
//	return 0;
//}
#include<bits/stdc++.h>
#define N 50005
#define ll long long
using namespace std;
struct Query{
    int l,r,id,pos;
    bool operator <(const Query &x)const{if(pos==x.pos)return r<x.r;
    else return pos<x.pos;}
}a[N];
int b[N],n,m,K;ll cnt[N],Ans[N];
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return x*f;
}
int main(){
    n=read();m=read();K=read();
    int size=(int)sqrt(n);
    for(int i=1;i<=n;i++)b[i]=read();
    for(int i=1;i<=m;i++){
        a[i].l=read();a[i].r=read();a[i].id=i;
        a[i].pos=(a[i].l-1)/size+1;
    }
    sort(a+1,a+m+1);
    int l=1,r=0;ll ans=0;
    for(int i=1;i<=m;i++){
        while(l>a[i].l)l--,cnt[b[l]]++,ans+=2*cnt[b[l]]-1;
        while(r<a[i].r)r++,cnt[b[r]]++,ans+=2*cnt[b[r]]-1;
        while(l<a[i].l)cnt[b[l]]--,ans-=2*cnt[b[l]]+1,l++;
        while(r>a[i].r)cnt[b[r]]--,ans-=2*cnt[b[r]]+1,r--;
        Ans[a[i].id]=ans;
    }
    for(int i=1;i<=m;i++)printf("%lld\n",Ans[i]);
    return 0;
}

