#include<bits/stdc++.h>
using namespace std;
struct Birthday{
    string name;
    int year,mon,day;
    bool operator <(Birthday tmp)const{
        if(year!=tmp.year) return year<tmp.year;
        if(mon!=tmp.mon) return mon<tmp.mon;
        if(day!=tmp.day) return day<tmp.day;
    }
};
Birthday per[105];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char c=getchar();
        string N;
        int y,m,d;
        cin>>N>>y>>m>>d;
        per[i]=(Birthday){N,y,m,d};
    }
    stable_sort(per+1,per+n+1);
    for(int i=1;i<=n;i++) cout<<per[i].name<<endl;
    return 0;
}
