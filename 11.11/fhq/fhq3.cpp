#include <bits/stdc++.h>
using namespace std;
struct Tr{
    int siz,v,pr,l,r,fa;
};
Tr tr[400005];
int S=0,root=0,n,m,a[200005];
int pos[200005];
void maintain(int k){
    tr[k].siz=1;
    if(tr[k].l)tr[k].siz+=tr[tr[k].l].siz,tr[tr[k].l].fa=k;
    if(tr[k].r)tr[k].siz+=tr[tr[k].r].siz,tr[tr[k].r].fa=k;
}
int newnode(int k){
    S++,tr[S].v=k,tr[S].pr=rand(),tr[S].siz=1;
    tr[S].l=tr[S].r=tr[S].fa=0;
    return S;
}
void Split_K(int now,int k,int &x,int &y){
    if(!now)x=y=0;
    else{
        if(k>tr[tr[now].l].siz)
            x=now,Split_K(tr[now].r,k-tr[tr[now].l].siz-1,tr[now].r,y);
        else
            y=now,Split_K(tr[now].l,k,x,tr[now].l);
        maintain(now);
    }
}
int Merge(int x,int y){
    if(!x||!y)return x+y;
    if(tr[x].pr<tr[y].pr){
        tr[x].r=Merge(tr[x].r,y);
        maintain(x);
        return x;
    }else{
        tr[y].l=Merge(x,tr[y].l);
        maintain(y);
        return y;
    }
}
int read(){
    int f=1,x=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x; 
}    
int get_pos(int x){
    int res=1+tr[tr[x].l].siz;
    while(tr[x].fa){
        if(x==tr[tr[x].fa].r)
            res+=tr[tr[tr[x].fa].l].siz+1;
        x=tr[x].fa;
    }
    return res;
}
void init(){
    srand(12414841);
    tr[0].siz=tr[0].v=tr[0].fa=0;
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)
        pos[a[i]]=newnode(a[i]),
        root=Merge(root,pos[a[i]]);
}
void solve(){
    char ord[10];
    int x,u,v,w,y,z,t,i1,i2;//全是辅助变量
    for(int i=1;i<=m;i++){
        scanf("%s",ord);
        u=v=w=y=z=t=0;
        if(ord[0]=='A')
            x=read(),
            printf("%d\n",get_pos(pos[x])-1);
        if(ord[0]=='T'){
            x=read(),u=get_pos(pos[x]);
            Split_K(root,u-1,w,z);
            Split_K(z,1,y,v);
            root=Merge(Merge(y,w),v);
        }
        if(ord[0]=='B'){
            x=read(),u=get_pos(pos[x]);
            Split_K(root,u-1,w,z);
            Split_K(z,1,y,v);
            root=Merge(Merge(w,v),y);
        }    
        if(ord[0]=='Q'){
            x=read();
            Split_K(root,x-1,w,z);
            Split_K(z,1,y,v);
            printf("%d\n",tr[y].v);
            root=Merge(Merge(w,y),v);
        }
        if(ord[0]=='I'){
            x=read(),y=read();
            if(y){
                u=get_pos(pos[x]);
                Split_K(root,u-1,w,v);
                Split_K(v,1,t,z);
                if(y==-1){
                    Split_K(w,u-2,i1,i2);
                    root=Merge(Merge(Merge(i1,t),i2),z);
                }else{
                    Split_K(z,1,i1,i2);
                    root=Merge(Merge(Merge(w,i1),t),i2);
                }
            }
        }
    }
}