#include <bits/stdc++.h>
using namespace std;
 
int ma[405][405];
struct pos{
	double x;double y;
	pos(double _x,double _y){
		x = _x;y=_y;
	}
	void speak(){
		cout<<x<<" "<<y<<"\n";
	}
};
double dist(pos a,pos b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
pos find4th(pos aaa,pos aab,pos aac){
    int ab=dist(aaa,aab)*dist(aaa,aab);
    int bc=dist(aab,aac)*dist(aab,aac);
	int ac=dist(aaa,aac)*dist(aaa,aac);
    if (ab+ac==bc) return pos(aab.x+aac.x-aaa.x,aab.y+aac.y-aaa.y);
    if (ab+bc==ac) return pos(aaa.x+aac.x-aab.x, aaa.y+aac.y-aab.y);
    if (bc+ac==ab) return pos(aaa.x+aab.x-aac.x, aaa.y+aab.y-aac.y);
	else return pos(-25535,-25535);
}
int build(){
	return 0;
}
int main(){
	pos a1 = pos(1,1);
	pos a2 = pos(1,3);
	pos a3 = pos(3,1);
	find4th(a3,a1,a2).speak();
	return 0;
}
