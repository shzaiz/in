#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
map<int,string> mp;
string name[MAXN];int cntname = 0;
void parase(string s){
	int sz = s.size();
	int mode = 0;
	string id = "";int parent =0;
	string childid = "";
	for(int i = 0;i<sz;i++){
		if(s[i]==':' && s[i+1]=='[') {
			++cntname;
			mp.insert(pair<int,string > (cntname, id ));
			name[cntname] = id;
			printf("Insert %d -- %s",cntname,id.c_str());
			mode = 1;
			i = i+1;
			continue;
		}
		if(mode==0){
			id = id+s[i];
		}
		if(mode==1){
			childid  = childid+s[i];
			if(s[i+1]==','){
				
			}
		}
		
	}
}
int main(){
	
} 
