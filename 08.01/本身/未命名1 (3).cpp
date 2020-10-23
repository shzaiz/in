#include <bits/stdc++.h>
#define d cout<<__LINE__<<" "<<__FUNCTION__<<endl;
#define ll long long
using namespace std;
const int mod = 1e9+9;
int ans[29];
stack<int > num;
stack<char > op;
string s="(a-1)^2+4*a";


string read(){
    string ss;
    char ch = getchar();
    while(ch=='\n'||ch=='\r'||ch==' ') ch=getchar();
    while(ch!='\n'&&ch!='\r'){
        if(ch!=' ') ss+=ch;
        ch=getchar();
        if(ch==EOF) break;
    }
    return ss;
}


int qpow(int a,int b,int mod){
	int tmp=1;
	while(b>0){
		if(b&1) tmp = tmp*a%mod;
		b>>=1;
		a = a*a % mod;
	}
	return tmp;
}

void calc(){
	int num1 = num.top();num.pop();
	int num2 = num.top();num.pop();
	char oper  = op.top();
	if(oper=='+'){
		int ans = (num1+num2)%mod;
		num.push(ans);
	}else if(oper=='-'){
		num.push((num2-num1+mod)%mod);
	}else if(oper=='*'){
		num.push((ll)num1*(ll)num2%mod);
	}else if(oper=='^'){
		num.push(qpow(num2,num1,1e9+9));
	}
	op.pop();
}

int gettp(char c){
	if(c=='+' || c=='-') return 2;
	else if(c=='*') return 3;
	else if(c=='^') return 4;
	else return 0;
}

void build(){
	int sum = 0;
	int l = (int)s.size();
	for (int i=0;i<l;i++){
		if(s[i]==' ') continue;
		if(s[i] == 'a') num.push(131);
		else if(isdigit(s[i])){
			sum*=10;
			sum+=s[i]-'0';
			if(i==l-1 || !isdigit(s[i+1]))num.push(sum),sum=0;
		}else{
			if(s[i]=='('){
				op.push('(');
				continue;
			}else if(s[i]==')'){
				while(!op.empty() && op.top()!='(') calc();
				if(!op.empty()&& op.top()=='(') op.pop();
				continue;
			}
			while(!op.empty() && gettp(s[i])<=gettp(op.top())) calc();
			op.push(s[i]);
		} 
	}
}

int make(){
	build();
	while(!op.empty()){
		if(op.top()=='('){
			op.pop();continue;
		}
		calc();
	}
	return num.top();
}

int main(){
	freopen("D:\\in.txt","r",stdin);
	s = read();
    int n,ans;
    ans = make();
    cin>>n;
    for(int i = 0;i < n;i++){
        while(!num.empty()) num.pop();
        while(!op.empty()) op.pop();
        s = read();
        int asn = make();
        cout<<asn<<endl;
        if(asn == ans) printf("%c",'A'+i);
    }
    return 0;
}
