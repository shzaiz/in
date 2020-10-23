#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int level[200];
const int mod=1e9+7, x = 131;
stack<int>num;
stack<char>opera;
string s;

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
int quickPower(int n1,int n2){
    ull ans = 1,pow = n1;
    while(n2){
        if(n2&1) ans = ans*pow%mod;
        pow = pow*pow%mod;
        n2>>=1;
    }
    return ans%mod;
}
void calculate(){
    int n1 = num.top();
    num.pop();
    int  n2 = num.top();
    num.pop();
    int ans;
    switch (opera.top()) {
        case '+':ans = (n2+n1)%mod;  break;
        case '-':ans = (n2-n1+mod)%mod;  break;
        case '*':ans = ( (long long)(n2%mod) * (n1%mod) )%mod; break;
        case '^':ans = quickPower(n2,n1);
    }
    num.push(ans);
    opera.pop();
}
void pushStack(){
    int len = (int)s.length(),sum = 0;
    for(int i = 0;i < len;i++){
        if(s[i] == 'a') num.push(x);
        else if(isdigit(s[i])){
            sum = sum*10+(s[i]-'0');
            if(i == len-1||!isdigit(s[i+1]) ) num.push(sum),sum = 0;
        }
        else {
            if(s[i] == '(') {
                opera.push('(');
                continue;
            }else if(s[i] == ')'){
                while(!opera.empty() && opera.top() != '(') calculate();
                if(!opera.empty() && opera.top() == '(') opera.pop();
                continue;
            }
            while(!opera.empty() && level[s[i]] <= level[opera.top()])  calculate();
            opera.push(s[i]);
        }
    }
}

int getResult(){
    pushStack();
    while(!opera.empty()){
        if(opera.top()=='(') {
            opera.pop();continue;
        }
        calculate();
    }
    return num.top();
}

int main(){
	freopen("D:\\in.txt","r",stdin);
    level['^'] = 4;level['*'] = 3;level['+'] = 2;level['-'] = 2;
    s = read();
    int n,ans;
    ans = getResult();
    cin>>n;
    for(int i = 0;i < n;i++){
        while(!num.empty()) num.pop();
        while(!opera.empty()) opera.pop();
        s = read();
        if(getResult() == ans) printf("%c",'A'+i);
    }
    return 0;
}
