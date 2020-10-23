// // 如果发现数据全出成某一个特定的值,说明就可能取min的时候忘记memset了.
// // 邻接表存图, 要注意对角线归零.
// #include <bits/stdc++.h>
// using namespace std;
// #define MAXN 1001
// #define MEM(x) memset((x.v), 1, sizeof(x.v))
// struct M{
//   int v[MAXN][MAXN];

// }A,B,C;
// int cnt = 0;
// int id[MAXN];
// M g;
// int mxnode ;
// int n,t,s,e;
// #define n mxnode
// M operator *(M a,M b){
//     M c;
//     MEM(c);
//     for(int k = 1;k<=n;k++){
//         for(int i =1;i<=n;i++){
//             for(int j = 1;j<=n;j++){
//                 c.v[i][j] = min(c.v[i][j],a.v[i][k]+b.v[k][j]);
//             }
//         }
//     }
//     return c;
// }
// void cpymat(int nt){
//     A=g;B=g;
//     int pow = nt;
//     M ans=B;
// 	for (pow--;pow;B=B*B,pow>>=1) {
// 		if (pow&1) ans=ans*g;
// 	}
// }
// #undef n
// int main(){
//     #ifndef ONLINE_JUDGE
//     freopen("D:/Testcases/wa.in","r",stdin);
//     freopen("D:/Testcases/wa.out","w",stdout);
//     #endif
//     MEM(A),MEM(B),MEM(C),MEM(g);
//     cin>>n>>t>>s>>e;
//     for(int i=1;i<=t;i++){
//         int w,uu,vv;
//         cin>>w>>uu>>vv;
//         uu = (id[uu]?id[uu]:id[uu] = ++cnt);
//         vv = (id[vv]?id[vv]:id[vv] = ++cnt);
//         g.v[uu][vv] = g.v[vv][uu] = w;

//     }
//     mxnode = cnt;
//     for(int i=1; i<=mxnode;i++){
//         g.v[i][i] = 0;
//     }
//     s = id[s],e = id[e];
//     cpymat(n);
//     cout<<B.v[s][e]<<endl;

// }


#include <bits/stdc++.h>
using namespace std;
int num[1000005];
int n,s,t,e,tol;
struct map
{
    int a[500][500];
    map operator * (const map &x) const //重载运算符，一会儿要用
    {
        map c;
        memset(c.a,0x3f3f3f3f,sizeof(c.a));//取min，显然置大数
        for(int k=1;k<=tol;k++)
            for(int i=1;i<=tol;i++)
                for(int j=1;j<=tol;j++)
                    c.a[i][j]=min(c.a[i][j],a[i][k]+x.a[k][j]);
        return c;		
    }
}dis,ans;
void init()
{
    memset(dis.a,0x3f3f3f3f,sizeof(dis.a));
    int x,y,z;
    cin>>n>>t>>s>>e;
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        if(!num[y])  //这里做一个离散化
            num[y]=++tol;
        if(!num[z])
            num[z]=++tol;
        dis.a[num[y]][num[z]]=dis.a[num[z]][num[y]]=x;
    }
}
void doit() //快速幂
{
    n--;
    ans=dis;
    while(n)
    {
        if(n&1)
            ans=ans*dis;
        dis=dis*dis;
        n>>=1;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/Testcases/wa.in","r",stdin);
    freopen("D:/Testcases/wa.out","w",stdout);
    #endif
    init();
    doit();
    cout<<ans.a[num[s]][num[e]];
}