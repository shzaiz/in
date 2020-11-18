#include <bits/treegenerator.h>
#include <bits/stdc++.h>
#define fo(i,x) for(int i = 1;i<=x;i++)
#define fo_(i,b,x) for(int i = b;i<=x;i++)
#define re(i,x,b) for(int i = x;i>b;i--)
#define N 10010
using namespace std;
using namespace tree_generator_by_ouuan;

void myOutputEdge(ostream& os, int u, int pa)
{
    os << u + 1 << ' ' << pa + 1 << ' '<< endl;
}

int main()
{
    #ifdef XBZAKIOI
    freopen("D:/Testcases/baoli.ac","w",stdout);
    #endif
    srand(time(0));
    int n = 20;
    cout<<n+1<<"\n";
    fo(i,n+1) cout<<i<<' ';
    cout<<"\n";
    Tree t;
    t.complete(n, 4, 0);
    t.shuffleNodes(1);
    t.shuffleEdges();
    outputEdge = myOutputEdge;
    cout << t << endl;

    return 0;
}