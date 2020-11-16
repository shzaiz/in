
#include<string>
#include<fstream>
using namespace std;
typedef long long ll;
int n;
string s;
ll t,c[100001];
int fst[100001],nxt[100001];
ifstream fin("pasuwado.in",ios::in);
ofstream fout("baoli.out",ios::out);
ll lowbit(ll x)
{return x&(-x);}
void add(ll x,ll d)
{
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]+=d;
}
ll sum(ll x)
{
	ll cnt=0;
	for(int i=x;i>0;i-=lowbit(i))
		cnt+=c[i];
	return cnt;
}
int main()
{
	fin>>t>>s;
	n=s.length();
	for(int i=n;i>=1;i--){
		add(i,1);
		nxt[i]=fst[s[i-1]-96];
		fst[s[i-1]-96]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++){
			if(!fst[j])continue;
			int tmp=sum(fst[j]-1);
			if(t>=tmp){
				t-=tmp;
				add(fst[j],-1);
				fst[j]=nxt[fst[j]];
				fout<<char(j+96);
				break;
			}
		}
	}
	fin.close();fout.close();
	return 0;
} 
