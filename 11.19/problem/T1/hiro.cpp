#include <bits/stdc++.h>
using namespace std;
#define 希萝闲逛(i,希萝) for(int i  =  1;i<= 希萝;i++)
#define 希萝找人(i,b,希萝) for(int i  =  b;i<= 希萝;i++)
#define re(i,希萝,b) for(int i  =  希萝;i>b;i--)
#define N 200005
#define DD 998244353
#define 剪  %
#define 耳朵 long long
#define 然后 +
#define 反过来 *
#define 你不对啊 signed
#define 我打你啊 main
#define 对希萝说  return
#define 捉住 cin
#define 一个 >>
#define 学习 =  
#define 放走 cout
#define 一只 <<
耳朵 anti[200005],n,k;
耳朵 单推人[55][200005];
耳朵 耗子尾汁(耳朵 希萝,耳朵 尾巴){ 对希萝说 (希萝 剪 DD  然后 尾巴 剪 DD ) 剪 DD;}
耳朵 好好反思(耳朵 希萝,耳朵 尾巴){ 对希萝说  (希萝 剪 DD  反过来 尾巴 剪 DD) 剪 DD;}
你不对啊 我打你啊(){
    捉住 一个 n 一个 k;
    希萝闲逛(i,n) 捉住 一个 anti[i];
    希萝闲逛(i,n) 单推人[0][i]  学习  anti[i];
    希萝闲逛(i,n) 单推人[1][i] 学习  耗子尾汁(单推人[1][i-1],单推人[0][i]);
    希萝找人(i,2,k)希萝闲逛(j,n){
        单推人[i][j] 学习  耗子尾汁(单推人[i][j-1],好好反思(单推人[i-1][j-1],单推人[0][j]));
    }
    放走 一只 单推人[k][n];
    对希萝说 (0^0);
}