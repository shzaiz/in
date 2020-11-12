#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < n; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int n,m;
const int N = 200010;
pair<int,int>st[N];
vector<int>G[N];
int col[N], anscol[N];
ifstream fin("sbtg.in");
FILE *fscore,*freport,*fstd,*fout;
int w;
double point_score;
char s[100];

void Init()
{
	fscanf(fstd, "%d", &n);
	for(int i=0,l,r;i<n;i++)
	{
		fscanf(fstd, "%d%d", &l, &r);
		st[m++]=make_pair(l<<1,i<<1);
		st[m++]=make_pair((r<<1)+1,(i<<1)+1);
		G[i<<1].push_back(1+(i<<1));
		G[(i<<1)+1].push_back(i<<1);
	}
}

int Judge()
{
  double score = 1;
  double std_ans, user_ans;
  long long tmp = 0;
	double eps = 1e-4;
	double ans = 0, out = 0;
	for(int i = 1; i <= 10; ++i)
	{
		fscanf(fstd, "%lf", &ans);
		fscanf(fout, "%lf", &out);
		double temp = ( fabs(out - ans) / ans );
		if(temp > eps)
		{
			fprintf(freport, "第%d行，标准%.6f，输出%.6f\n", i, ans, out); 
			return 0;
		}
	}
  	return 10;
}

int main(int argc,char *argv[])
{
    fscore=fopen("score.log","w");//打开得分文件
    freport=fopen("report.log","w");//打开报告文件

    fstd=fopen(argv[2],"r");//打开测试点标准输出文件，std_ans和w

    point_score=atoi(argv[1]);//取得测试点的分数

//    ifstream fin("paint.in");//原始数据
    fout=fopen("sbtg.out","r");//用户输出

    fprintf(fscore,"%d",Judge());//返回分数

    fclose(fscore);//关闭得分文件
    fclose(freport);//关闭报告文件

    return 0;
}
