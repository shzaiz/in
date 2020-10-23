#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
ofstream fscore,freport;
ifstream fin,fout,fstd;

const int N=2e7+7;

int n,m,lens,full,ans;

char s[N],extc;

bool lined;

int main(int argc,char *argv[]){
	fin.open(argv[1]);
    fout.open(argv[2]);
    fstd.open(argv[3]);
    full=atoi(argv[4]);
    fscore.open(argv[5]);
    freport.open(argv[6]);
    
    fin>>n;
    m=n<<1;
    fout>>s;
    if(s[0]=='-'){
    	freport<<"Jury has answer but you don't!\n";
    	return 0;
	}
	lens=(int)strlen(s);
    fout>>extc;
    if(extc||lens>m){
        freport<<"Output Limit Exceeded!\n";
        return 0;
    }
    for(int i=0;i<lens;i++){
        if(s[i]<'0'||s[i]>'1'){
            freport<<"Wrong output format!\n";
            return 0;
        }
        ans=ans*10+s[i]-'0';
        ans%=n;
    }
    if(ans){
        freport<<"Wrong answer!\n";
        return 0;
    }
    fscore<<full;
    freport<<"Accepted!\n";
    
    fin.close();
    fout.close();
    fstd.close();
    fscore.close();
    freport.close();
    return 0;
}
