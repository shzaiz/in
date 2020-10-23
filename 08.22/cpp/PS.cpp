#include<iostream>
#include<algorithm>
using namespace std;
struct f{
    int rank,sum;
}cou[10];
int a[10][10],h[10][10],l[10][10],g[10][10],s[100][4],u,ok,most=-1,have;
bool cmp(f a,f b){
    return a.sum<b.sum; 
}
void dfs(int p,int score){
    if(p==u){
        if(score>most)  most=score;
        return;
    }
    for(int i=1;i<=9;i++){
        if(!h[s[p][0]][i]&&!l[s[p][1]][i]&&!g[s[p][3]][i]){
            h[s[p][0]][i]=l[s[p][1]][i]=g[s[p][3]][i]=1;
            dfs(p+1,score+(s[p][2]*i));
            h[s[p][0]][i]=l[s[p][1]][i]=g[s[p][3]][i]=0;
        }
    }
    return;
}


int which(int i,int j){
    if(i<=3){
        if(j<=3)return 1;
        else if(j<=6)return 2;
        else return 3;
    }else if(i<=6){
        if(j<=3)return 4;
        else if(j<=6)return 5;
        else return 6;
    }else{
        if(j<=3)return 7;
        else if(j<=6)return 8;
        else return 9;
    }
}

int point(int i,int j){
    if(i==1||j==1||i==9||j==9)return 6;
    if(i==2||j==2||i==8||j==8)return 7;
    if(i==3||j==3||i==7||j==7)return 8;
    if(i==4||j==4||i==6||j==6)return 9;
    return 10;
}
int main(){
    for(int i=1;i<=9;i++)  cou[i].rank=i;
    for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++)
    {
        cin>>a[i][j];
        if(a[i][j]>0)
        h[i][a[i][j]]=l[j][a[i][j]]=g[which(i,j)][a[i][j]]=1,have+=a[i][j]*point(i,j);
        else  cou[i].sum++;
    }
    sort(cou+1,cou+10,cmp);
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        if(a[cou[i].rank][j]==0)
        s[u][0]=cou[i].rank,s[u][1]=j,s[u][2]=point(cou[i].rank,j),s[u++][3]=which(cou[i].rank,j);
    }
    dfs(0,have);
    cout<<most<<endl;
    return 0;
} 


