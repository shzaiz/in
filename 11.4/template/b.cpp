#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define maxn 200100
using namespace std;

namespace AC
{
    int ch[maxn][26],tot=1,fail[maxn];
    int num[maxn];
    inline void insert(char *ss)
    {
        int now=1;
        for(register int i=1;i<=strlen(ss);i++)
        {
            int w=ss[i]-'a';
            if(!ch[now][w]) ch[now][w]=++tot;
            now=ch[now][w];
        }
        num[now]++;
    }
    inline void init()
    {
        queue<int> que; 
        for(register int i=0;i<26;i++)
            if(ch[1][i]) que.push(ch[1][i]),fail[ch[1][i]]=1;
        while(!que.empty())
        {
            int u=que.front(); que.pop();
            for(register int i=0;i<26;i++)
            {
                if(!ch[u][i]) ch[u][i]=ch[fail[u]][i];
                else fail[ch[u][i]]=ch[fail[u]][i],que.push(ch[u][i]);
            }
        }
    }
    int book[maxn];
    inline int search(char *ss)
    {
        int now=1,ans=0;
        for(register int i=1;i<=strlen(ss);i++)
        {
            now=ch[now][ss[i]-'a'];
            for(register int j=now;j;j=fail[j])
            {
                if(!book[j])
                {
                    book[j]=1;
                    ans+=num[j];
                }
                else break;
            }
        }
        return ans;
    }
}
char s[maxn];
int n;
int main()
{
    #ifdef XBZAKIOI
    freopen("D:/Testcases/in.ac","r",stdin);
    freopen("D:/Testcases/out.ac","w",stdout);
    #endif
    scanf("%d",&n);
    for(register int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        AC::insert(s);
    }
    AC::init();
    scanf("%s",s+1);
    printf("%d",AC::search(s));
    return 0;
}