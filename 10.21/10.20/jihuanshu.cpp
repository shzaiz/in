#include <bits/stdc++.h>
using namespace std;
int main(){
    /*
    
    \par $\text{Yuzaki Tsukasa}$认为这样的序列是$\texttt{NASA}$序列, 当且仅当\textbf{数列中不存在长度大于1且长度为偶数的回文子数列}\footnote{本题目中, 认为一个数列的子序列必须为连续的子序列.}. 在被酸腐蚀之前, 这棵柠檬树上从1到所有节点的简单路径都是\texttt{NASA}序列.
    \par $\text{Yuzaki Nasa}$可以在这棵柠檬树上自由行走. 定义$S(x)$ 的值为从1到当前节点的简单路径组成的数列, 在$[1,k]$的范围内填补\textbf{被腐蚀掉}的权值之后, 有多少种不同的情况, 使得这条路径对应的数列组成$\texttt{NASA}$序列.
    \\并对于998244353取模.
    \par 换句话说, 假定$\{g_i\}$表示从$1$到$x$的路径中第$i$个节点,  $S(x)$表示满足如下情况的数量:
    \begin{itemize}
        \item 对于$\forall g_i=0$, 令$g_i\in[1,k]$. 
        \item $g_i$中数列中不存在长度大于1且长度为偶数的回文子数列.(即这个数列是\texttt{NASA}序列)
    \end{itemize}
    对于$998,244,353$取模的值.
    \par \textbf{注意}:我们保证$\forall \{g_i\}$中未被腐蚀的节点的权值, \emph{不存在}长度大于1且长度为偶数的回文子数列.
    \par 显然, $\text{Yuzaki Tsukasa}$并不满足于求出单个$S(x)$的值. 因此,她希望求出:
    $$
    \bigoplus_{i=1}^nS(i).
    $$
    的值.*/
}