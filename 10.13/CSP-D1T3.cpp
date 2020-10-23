#include <bits/stdc++.h>
using namespace std;
int frm[15],to[15];
int a[15],cop[15];
int n;
string perform(string s){
    char ans[15];
    string sb="";
    for(int i = 0; i<n-1;i++){
        int f = frm[s[i]-'0']-1;
        int t = to[s[i]-'0']-1;
        swap(a[f],a[t]);
    }
    for(int i =0;i<n;i++){
        ans[a[i]] = i+'0';
    }
    return ans;
}
char nowans[15];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
    #endif
    cin >> n;
    char gen[100] ;
    for(int i = 0;i<n;i++){
        gen[i] = i+'0';
        nowans[i] = '9';
    }
    for(int i = 0;i<n;i++){
        int x;cin>>x;
        a[x-1]=i;
        cop[x-1] = i;
    }
    for(int i= 0;i<n;i++){
        cin>>frm[i]>>to[i];
    }
    string aa = perform(gen);
    // printf("Examing :%s\n",gen);
    for(int i = 0;i<n;i++){
        a[i] = cop[i];
    }
    int x = atoi(nowans),y = atoi(aa.c_str());
    // printf("%d,%d\n",x,y);
    if(x>=y) {
       for(int i = 0;i<n;i++){
            nowans[i] = aa[i];
        }
    }
    while(next_permutation(gen,gen+n)){
        string aa = perform(gen);
         printf("Examing :%s\n",gen);
        for(int i = 0;i<n;i++){
            a[i] = cop[i];
        }
        int x = atoi(nowans),y = atoi(aa.c_str());
        printf("%d,%d\n",x,y);
        if(x>=y) {
            for(int i = 0;i<n;i++){
                nowans[i] = aa[i];
            }
        }
    }
    for(int i = 0;i<n;i++){ 
        cout<<(char)(nowans[i]+1)<<" ";
    }
}