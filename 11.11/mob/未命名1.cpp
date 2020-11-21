#include <iostream>
#define 使用 using
#define 整型 int
#define 浮点 double
#define 命名空间 namespace
#define IO流 std
#define 输出文本 cout
#define 输入文本 cin
#define 换行 endl
#define 输出流 <<
#define 输入流 >>
#define 主 main
#define 返回 return
#define 如果 if
#define 遍历循环 for
#define 检查循环 while
#define 继续 continue
#define 退出 break
#define 大于 >
#define 小于 <
#define 等于 =
#define 大于等于 >=
#define 小于等于 <=
#define 是否等于 ==
#define 不等于 !=
#define 逻辑与 &&
#define 逻辑或 ||
#define 布尔值 bool
#define 递增 ++
#define 递减 --
#define 增加 +=
#define 减少 -=
#define 真 true
#define 假 false
#define 字符串 string

/*
 * 这是一个使用define关键字用中文定义C++关键字的程序。
 * 因此下面的程序都是用中文编写的。
 * 版权所有 大米
 * 该段代码创建于 2019年12月7日 21：07 星期六
*/

整型 主(){
 使用 命名空间 IO流;
 整型 x 等于 0;
 整型 y 等于 0;
 输出文本 输出流 "你好" 输出流 换行;
 遍历循环(整型 计数器 等于 0; 计数器 小于等于 10; 计数器 递增){
 输出文本 输出流 计数器 输出流 换行;
 }
 输出文本 输出流 真 逻辑与 假;
 输出文本 输出流 假 逻辑与 假;
 布尔值 运行中 等于 真;
 字符串 命令 等于 "";
 输出文本 输出流 换行;
 检查循环(运行中 是否等于 真){
 输出文本 输出流 "输入命令 >>> ";
 输入文本 输入流 命令;
 输出文本 输出流 换行;
 如果(命令 是否等于 "查看位置"){
 输出文本 输出流 "X:" 输出流 x 输出流 "Y:" 输出流 y 输出流 换行;
 }
 如果(命令 是否等于 "更改位置"){
 输出文本 输出流 "X:";
 输入文本 输入流 x;
 输出文本 输出流 换行;
 输出文本 输出流 "Y:";
 输入文本 输入流 y;
 输出文本 输出流 换行;
 }
 如果(命令 是否等于 "退出"){
 运行中 等于 假;
 }
 }
 返回 0;
}#include <bits/stdc++.h>
using namespace std;
#define using_debug_output 1
#define using_temp_file 0
#define this_is_a_real_file_output 1
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
#define deb if(using_debug_output)
#define fil if(using_temp_file)
#define realfl if(this_is_a_real_file_output)
int main(){
	realfl freopen(".in","r",stdin);
	realfl freopen(".out","w",stdout);
	
	return 0;
}

