#include<stdio.h>
#include<string.h>
int p,k,s,len,w[205][205],F[205][45];
char A[205],temp[25],word[10][205];
void Input(void)
{
    int i;
    scanf("%d%d",&p,&k); len=20*p;
    while(getchar()!='\n');
    while(p--)
    {
        gets(temp);
        strcat(&A[1],temp);
    }
    scanf("%d",&s);
    while(getchar()!='\n');
    for(i=1;i<=s;i++) gets(word[i]);
}
int have(int x,int end)//是否存在以字符A[x]开头的单词 
{
    int i; 
    for(i=1;i<=s;i++)
    {
        char *p=strstr(&A[x],word[i]);
        if(p!=NULL && p-&A[x]==0 
            && (int)strlen(word[i])<=end-x+1) return 1;
    }
    return 0;
}
void Init(void)
{
    int i,j;
    for(j=len;j>=1;j--) 
        for(i=j;i>=1;i--)
            if(have(i,j)) w[i][j]=w[i+1][j]+1;
            else w[i][j]=w[i+1][j];
}
void DP(void)
{
    int i,j,r;
    for(i=1;i<=k;i++)   F[i][i]=F[i-1][i-1]+w[i][i];
    for(i=1;i<=len;i++) F[i][1]=w[1][i];
    for(i=1;i<=len;i++)
        for(j=2;j<=k&&j<i;j++)
            for(r=j;r<i;r++)
                if(F[i][j]<F[r][j-1]+w[r+1][i])
                    F[i][j]=F[r][j-1]+w[r+1][i];
}
int main(void)
{
    Input();
    Init();
    DP();
    printf("%d",F[len][k]);
    return 0;
}
