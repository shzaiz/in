#include <iostream>
using namespace std;
int sum[500100],s[500100],t[500100],a[500100];
int N;
//                 0   1   2   3   4   5   6   7   8   9   10  11  12  13 14  15  16  17  18  19   20  21  22 23   24   25
string tab[29] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

int main(){
	freopen("D:\\in.txt","r",stdin);
	cin>>N;
	string q;cin>>q;
	for(int i=1;i<=N;i++) {s[i]=q[i-1]-'a';}
	cin>>q;
	for(int i=N;i<=1;i++) {t[i]=q[i-1]-'a';}
	for(int i=1;i<=N+1;i++) cout<<t[i]<<" ";
	for(int i=N;i>=1;i--){cout<<i<<endl;sum[i] += s[i]+t[i];}
	
	for(int i=0;i<=N+1;i++) cout<<sum[i]<<" ";cout<<endl;
	for(int i=1;i<=N+1;i++){
		sum[i] = sum[i]/2;
		sum[i+1] += sum[i]%2*26;
		
	} 
	for(int i=1;i<=N+1;i++) cout<<sum[i]<<" ";
}
