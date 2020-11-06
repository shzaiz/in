#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define maxn 1000100
using namespace std;
char ins[maxn];
namespace ACAM
{
    int ch[maxn][26];
    int fail[maxn],ep[maxn];
    int tot=1;
    inline void insert()
    {
        int now=1;
        int len=strlen(ins+1);
        for(register int i=1;i<=len;i++)
        {
            int c=ins[i]-'a';
            if(!ch[now][c]) ch[now][c]=++tot;
            now=ch[now][c];
        }
        ep[now]++;
    }
    inline void getfail()
    {
        queue<int> que;
        for(register int i=0;i<26;i++)
            if(ch[1][i]) fail[ch[1][i]]=1,que.push(ch[1][i]);
        while(!que.empty())
        {
            int u=que.front(); que.pop();
            for(register int i=0;i<26;i++)
                if(ch[u][i]) 
                {
                    fail[ch[u][i]]=ch[fail[u]][i];
                    que.push(ch[u][i]);
                }
                else ch[u][i]=ch[fail[u]][i];
        }
    }
    int book[maxn];
    inline void getrun()
    {
        int len=strlen(ins+1);
        int now=1,ans=0;
        for(register int i=1;i<=len;i++)
        {
            now=ch[now][ins[i]-'a'];
            for(register int j=now;j;j=fail[j])
                if(!book[j])
                {
                    book[j]=1; ans+=ep[j];
                }
                else break;
        }
        printf("%d",ans);
    }
}
int main()
{
    int n; scanf("%d",&n);
    for(register int i=1;i<=n;i++)
    {
        scanf("%s",ins+1);
        ACAM::insert();
    }
    ACAM::getfail();
    scanf("%s",ins+1);
    ACAM::getrun();
    return 0;
}