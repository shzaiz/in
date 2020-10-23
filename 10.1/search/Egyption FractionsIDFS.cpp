#include <iostream>
using namespace std;

const double error = 1e-6;
double frac;
int depth = 1;
inline double abs(double num){
    return num>0 ? num:-num;
}

bool IDS(int d,double now,int dion){
    if(d == depth){
            if(abs(frac - now) < error)
                return true;
            return false;
        }
    int maxdion = (int)((depth - d) / (frac - now));
    for(;dion <= maxdion;dion++){
            if(IDS(d+1, now + 1.0/dion, dion+1)){
                    cout<< dion <<' ';
                    return true;
                }
        }
    return false;
}

int main(){
    int a, b;
   cin >> a >> b;
    frac = (double)a/b;
    while(IDS(0,0.0,(int)(1.0/frac)+1) == false){
            depth++;
        }
    return 0;
}