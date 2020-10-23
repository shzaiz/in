#include<bits/stdc++.h>

using namespace std;

const int N=3e5+5;

char in[20],out[20];

struct node{
	int l,r;
	node(int rl=0x3f3f3f3f,int rr=0){
		l=rl;r=rr;
	}
}tree[19][N<<2],nd[N];

int n,m,a[N],b[N],ans[N],lmt;

void pushup(int level,int u){
	tree[level][u].l=min(tree[level][u<<1].l,tree[level][u<<1|1].l);
	tree[level][u].r=max(tree[level][u<<1].r,tree[level][u<<1|1].r);
}

void build(int level,int l,int r,int u){
	if(l==r){
		tree[level][u]=nd[l];
		return;
	}
	int mid=(l+r)>>1;
	build(level,l,mid,u<<1);
	build(level,mid+1,r,u<<1|1);
	pushup(level,u);
}

node query(int level,int L,int R,int l,int r,int u){
	if(L<=l&&r<=R){
		return tree[level][u];
	}
	node rep,rrep;
	int mid=(l+r)>>1;
	if(L<=mid){
		rrep=query(level,L,R,l,mid,u<<1);
		rep.l=min(rep.l,rrep.l);
		rep.r=max(rep.r,rrep.r);
	}
	if(mid<R){
		rrep=query(level,L,R,mid+1,r,u<<1|1);
		rep.l=min(rep.l,rrep.l);
		rep.r=max(rep.r,rrep.r);
	}
	return rep;
}

int main(){
    for(int t=21;t<=25;t++){
        sprintf(in,"info%d.in",t);
        sprintf(out,"info%d.out",t);
        freopen(in,"r",stdin);
        freopen(out,"w",stdout);
        memset(ans,0,sizeof ans);
        scanf("%d",&n);
        m=3*n;lmt=n<<1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        for(int i=1,j;i<=n;i++){
            j=i;
            nd[j]=node(j-a[i],j+b[i]);
            j+=n;
            nd[j]=node(j-a[i],j+b[i]);
            j+=n;
            nd[j]=node(j-a[i],j+b[i]);
        }
        build(0,1,m,1);
        for(int i=1,ls,rs;i<19;i++){
            for(int j=1;j<=m;j++){
                ls=nd[j].l;rs=nd[j].r;
                nd[j]=query(i-1,ls,rs,1,m,1);
            }
            build(i,1,m,1);
        }
        for(int i=n+1,ls,rs,repl,repr;i<=lmt;i++){
            ls=rs=i;
            node rep;
            for(int j=18;~j;j--){
                rep=query(j,ls,rs,1,m,1);
                repl=rep.l;
                repr=rep.r;
                if(repr-repl+1<n){
                    ls=repl;rs=repr;ans[i-n]|=(1<<j);
                }
            }
            if(rs-ls+1<n){
                ans[i-n]++;
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d%c",ans[i]," \n"[i==n]);
        }
        fclose(stdin);
        fclose(stdout);
    }
	return 0;
}
