#include <bits/stdc++.h>
#define x1 xbzakioi
#define y1 wangshuoakioi
#define x2 lyfxakioi
#define y2 zgwbaoling
using namespace std;
int hx[60],hy[60],h;
int x1,y1,x2,y2;
int n,m;
char c[60];
bool b[60][60],tx[51][51];
int t1[60][60],t2[60][60];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int xx[2510],yy[2510];
void shui(int t,int x,int y){
      t1[x][y]=min(t,t1[x][y]);
      for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(b[xx][yy]&&xx>0&&xx<=n&&yy>0&&yy<=m&&t+1<t1[xx][yy])
              shui(t+1,xx,yy);
        }
  }
  void inp(){
  	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c;
        for(int j=0;j<m;j++){
            if(c[j]== '.'){
				b[i][j+1]=true;break;
			}
			
            if(c[j]== 'S'){
            	x1=i;y1=j+1;b[i][j+1]=true;break;
			}
            if(c[j]== 'D'){
            	x2=i;y2=j+1;b[i][j+1]=false;break;
			}
            if(c[j]== '*'){
            	++h;hx[h]=i;hy[h]=j+1;break;
			}
            if(c[j]== 'X'){
            	b[i][j+1]=false;break;
			}
        }
    }
  }
void bfs(){
	for(int i=1;i<=h;i++)
        shui(0,hx[i],hy[i]);
      b[x2][y2]=true;
    xx[1]=x1,yy[1]=y1;
    int head=0,tail=1;
    t2[x1][y1]=0;
    tx[x1][y1]=true;
    while(head<=tail){
          ++head;
          int x=xx[head],y=yy[head];
          for(int i=0;i<4;i++){
                int nowx=x+dx[i],nowy=y+dy[i];
                if(b[nowx][nowy]==true&&
				   nowx>0&&nowx<=n&&
				   nowy>0&&nowy<=m&&
				   t2[x][y]+1<t1[nowx][nowy]){
                      t2[nowx][nowy]=min(t2[nowx][nowy],t2[x][y]+1);
                      if(tx[nowx][nowy]==false){
                            tx[nowx][nowy]=true;
                            tail++;
                            xx[tail]=nowx;
                            yy[tail]=nowy;
                  }
              }
            }
      }
      if(t2[x2][y2]<t2[0][0]) cout<<t2[x2][y2];
      else cout<<"ORZ hzwer!!!";
}
int main(){
    freopen("sliker.in","r",stdin);
    freopen("sliker.out","w",stdout);
    inp();
    memset(t1,127,sizeof(t1));
    memset(t2,127,sizeof(t2));
      bfs();
      return 0;
  }
