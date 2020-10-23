#include<bits/stdc++.h>
using namespace std;
struct Wint:vector<int>{
    Wint(int n=0){
        push_back(n);
        check();
    }
    Wint& check(){
        while(!empty()&&!back())pop_back();
        if(empty())return *this;
        for(int i=1; i<size(); ++i){
            (*this)[i]+=(*this)[i-1]/10;
            (*this)[i-1]%=10;
        }
        while(back()>=10){
            push_back(back()/10);
            (*this)[size()-2]%=10;
        }
        return *this;
    }
};
istream& operator>>(istream &is,Wint &n){
    string s;
    is>>s;
    n.clear();
    for(int i=s.size()-1; i>=0; --i)n.push_back(s[i]-'0');
    return is;
}
ostream& operator<<(ostream &os,const Wint &n){
    if(n.empty())os<<0;
    for(int i=n.size()-1; i>=0; --i)os<<n[i];
    return os;
}
Wint& operator+=(Wint &a,const Wint &b){
    if(a.size()<b.size())a.resize(b.size());
    for(int i=0; i!=b.size(); ++i)a[i]+=b[i];
    return a.check();
}
Wint operator+(Wint a,const Wint &b){
    return a+=b;
}
Wint operator*(const Wint &a,const Wint &b){
    Wint n;
    n.assign(a.size()+b.size()-1,0);
    for(int i=0; i!=a.size(); ++i)
        for(int j=0; j!=b.size(); ++j)
            n[i+j]+=a[i]*b[j];
    return n.check();
}
Wint f[1005][1005];
int main(){
    for(int i=0;i<1005;i++){
		f[i][0] = 1;
	}
	for(int i=1;i<50;i++){
		for(int j=1;j<50;j++){
//			f[i][j] = add(mul(f[i-1][j-1],ITS((i-j))),mul(ITS((j+1)),f[i-1][j]));
//			cout<<i<<j<<" "<<mul(ITS((j+1)),f[i-1][j])<<endl;
			f[i][j] = (f[i-1][j-1]*Wint((i-j)) + f[i-1][j]*Wint(j+1));
		}
	}
	int n,p;
	cin>>n>>p;
	cout<<f[n][p];
	return 0;
}
