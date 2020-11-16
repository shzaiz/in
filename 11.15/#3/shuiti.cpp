#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define fi first
#define se second
#define ci const int 
#define tm fuckccf
int tm = 0;
int cntt = 0;
map<string , int > mp;
struct Task{
    string nm;
    int lai,t;
}t[N];
bool hasval(string str){if((mp.find(str)->se) == 0) return 0; else return mp[str];}
char res[5000] = "_bsddfs:[a,c,d]:2;c:[a]:3;a:[]:1/2";
string nm="",dep="";int tm1=0,tm2=0,par=0,ind[N],outd[N];
struct Edge{
    int to,nxt;
}e[N];
Task ts[N];
int cntedge = 0,head[N];
void adde(int u,int v){
    e[++cntedge].to = v;
    e[cntedge].nxt = head[u];
    head[u] = cntedge;
}
int newnd(string str){
    if(hasval(str)){
        return mp[str];
    }else{
        tm++;
        mp[str] = tm;
        t[tm].nm = str;
        t[tm].lai = ++cntt;
        return tm;
    }
}
void addew(string u,string v){
    cout<<"add "<<u<<" "<<v<<"\n";
    int uu = newnd(u);
    int vv = newnd(v);
    adde(uu,vv);
    ind[vv] ++;
}
void fix(string s, int ttt){
    cout<<s<<" " <<time<<endl;
    int vv = mp[s];
    if(vv = 0) cout<<"Fuck!!!"; 
    t[vv].t = ttt;
}
int getstr(){
    ci NAME=0,DEP=1,DEPEND=2,BEGIN=4;
    int len = strlen(res);
    int mode = 0;
    fo(i,len){
        char s = res[i];
        if(mode == NAME){
            if(isalpha(s)) nm= nm+s;
            else if(s==':') continue;
            else if(s=='[') mode = DEP;
        }else if(mode==DEP){
            if(isalpha(s)) dep = dep+s;
            else if(s==']') continue;
            else if(s==':') {mode = DEPEND;addew(dep,nm);dep = "";}
            else if (s==',') {mode = DEP;addew(dep,nm);dep = "";}
        }else if(mode==DEPEND){
            if(isalpha(s)) mode =DEP;
            else if(isdigit(s)) tm1 = tm1*10+(int)(s-'0');
            else if(s==']') continue;
            else if(s==';') {mode = NAME;fix(nm,tm1);dep = "",nm="";tm1=0;}
            else if(s=='/') {mode = BEGIN;fix(nm,tm1);dep = "",nm="";tm1=0;nm="",dep="";}
        }else if(mode==BEGIN){
            if(isdigit(s)) par = par*10+(int ) (s-'0');
        }
    }
}

int main(){
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    // mp["akioi"] = 1;
    getstr();
    return 0;
}